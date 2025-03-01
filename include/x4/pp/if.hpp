#pragma once

#include "../pp/bool.hpp"
#include "../pp/cat.hpp"

#define X4IF(x) X4IIF(X4BOOL(x))
#define X4IIF(B) X4PCAT(DETAIL_X4IF, B)

#define DETAIL_X4IF0(x, ...) __VA_ARGS__
#define DETAIL_X4IF1(x, ...) x
