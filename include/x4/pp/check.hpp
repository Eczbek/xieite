#pragma once

#include "../pp/at.hpp"

#define X4CHECK(...) X4AT(1, __VA_ARGS__, 0,)
