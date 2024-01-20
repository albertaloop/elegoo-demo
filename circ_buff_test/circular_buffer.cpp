#include "circular_buffer.h"
#include <iostream>

void push(int val, volatile circular_buffer *buf)
{
    std::cout <<  buf->read_ptr << " " << buf->write_ptr << std::endl;

  if (buf->write_ptr >= buf->read_ptr && buf->write_ptr < BUFFER_LEN)
  {
    buf->values[buf->write_ptr] = val;
    std::cout << buf->values[buf->write_ptr] << std::endl;
    buf->write_ptr++;
    buf->write_ptr &= BUFFER_LEN-1;
    std::cout << buf->write_ptr << std::endl;
  }
}

int pop(volatile circular_buffer *buf)
{
  std::cout <<  buf->read_ptr << " " << buf->write_ptr << buf->values[buf->read_ptr] << std::endl;
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