#pragma once

#include "../pp/pragma.hpp"

#define XIEITE_REVIVE(f) XIEITE_PRAGMA(push_macro(#f)) XIEITE_PRAGMA(pop_macro(#f))
