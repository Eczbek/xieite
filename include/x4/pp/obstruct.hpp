#pragma once

#include "../pp/defer.hpp"
#include "../pp/eat.hpp"

#define X4OBSTRUCT(...) __VA_ARGS__ X4DEFER(X4EAT)()
