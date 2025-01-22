#pragma once

#include <xieite/eat.hpp>

#define XIEITE_DEFER(...) __VA_ARGS__ XIEITE_EAT()
