#pragma once

#include "../pp/pragma.hpp"

#define XIEITE_REVIVE(m) XIEITE_PRAGMA(push_macro(#m)) XIEITE_PRAGMA(pop_macro(#m))
