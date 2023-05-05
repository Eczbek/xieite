#pragma once

#include <xieite/macros/EMPTY.hpp>

#define XIEITE_DEFER(...) \
	__VA_ARGS__ XIEITE_EMPTY()
