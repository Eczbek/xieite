#pragma once

#include "../pp/eat.hpp"

#define XIEITE_DEFER(...) __VA_ARGS__ XIEITE_EAT()
