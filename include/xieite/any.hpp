#pragma once

#include <xieite/not.hpp>

#define XIEITE_ANY(...) XIEITE_NOT(__VA_OPT__(0))
