#pragma once

#include <xieite/cat.hpp>

#define XIEITE_RET_STRUCT(...) XIEITE_DETAIL_RET_STRUCT(XIEITE_CAT(XIEITE_DETAIL_STRUCT_, __COUNTER__), __VA_ARGS__)

#define XIEITE_DETAIL_RET_STRUCT(x, ...) \
	struct x __VA_ARGS__; \
	return x
