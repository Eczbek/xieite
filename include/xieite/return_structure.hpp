#pragma once

#include <xieite/concatenate.hpp>

#define XIEITE_RETURN_STRUCTURE(...) XIEITE_DETAIL_RETURN_STRUCTURE(XIEITE_CONCATENATE(XIEITE_DETAIL_STRUCTURE_, __COUNTER__), __VA_ARGS__)

#define XIEITE_DETAIL_RETURN_STRUCTURE(name_, ...) \
	struct name_ __VA_ARGS__; \
	return name_
