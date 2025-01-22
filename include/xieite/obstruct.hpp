#pragma once

#include <xieite/defer.hpp>
#include <xieite/eat.hpp>

#define XIEITE_OBSTRUCT(...) __VA_ARGS__ XIEITE_DEFER(XIEITE_EAT)()
