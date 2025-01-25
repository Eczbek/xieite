#pragma once

#include "../pp/bool.hpp"
#include "../pp/cat.hpp"

#define XIEITE_IF(x) XIEITE_IF_PRIM(XIEITE_BOOL(x))
#define XIEITE_IF_PRIM(B) XIEITE_CAT_PRIM(XIEITE_IF_PRIM_, B)
#define XIEITE_IF_PRIM_0(x, ...) __VA_ARGS__
#define XIEITE_IF_PRIM_1(x, ...) x
