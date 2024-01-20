#include "circular_buffer.h"

void push(int val, volatile circular_buffer *buf)
{
  if (buf->write_ptr >= buf->read_ptr && buf->write_ptr < BUFFER_LEN)
  {
    buf->values[buf->write_ptr] = val;
    buf->write_ptr++;
    buf->write_ptr &= BUFFER_LEN-1;
  }
}

int pop(volatile circular_buffer *buf)
{
  if (buf->read_ptr != buf->write_ptr)
  {
    int ret = buf->values[buf->read_ptr];
    buf->read_ptr++;
    buf->read_ptr &= BUFFER_LEN-1;
    return ret;
  }
  else
  {
    return -1;
  }
}