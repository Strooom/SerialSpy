#pragma once

#include <stdint.h>

class msgBuffer
{
public:
  static constexpr uint32_t length{128};
  char buffer[length]{};
  uint32_t level{0};
};
