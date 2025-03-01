#pragma once

#include "../pp/pragma.hpp"

#define X4REVIVE(m) X4PRAGMA(push_macro(#m)) X4PRAGMA(pop_macro(#m))
