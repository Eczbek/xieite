#pragma once

#include "../pp/bool.hpp"
#include "../pp/cat.hpp"

#define XIEITE_IF(x) XIEITE_IIF(XIEITE_BOOL(x))
#define XIEITE_IIF(B) XIEITE_PCAT(DETAIL_XIEITE_IF_, B)

#define DETAIL_XIEITE_IF_0(x, ...) __VA_ARGS__
#define DETAIL_XIEITE_IF_1(x, ...) x
