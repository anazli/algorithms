#pragma once

#include <cassert>
#include <cstdio>

#define ASSERT(x, msg)            \
  if (!(x)) {                     \
    fprintf(stderr, "%s\n", msg); \
    std::abort();                 \
  }
