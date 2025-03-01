#pragma once

#include "../pp/cat.hpp"

#define X4RETSTRUCT(...) DETAIL_X4RETSTRUCT(X4CAT(DETAIL_X4struct, __COUNTER__), __VA_ARGS__)

#define DETAIL_X4RETSTRUCT(name_, ...) \
	struct name_ __VA_ARGS__; \
	return name_
