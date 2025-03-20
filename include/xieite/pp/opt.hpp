#pragma once

#include "../pp/any.hpp"
#include "../pp/if.hpp"
#include "../pp/unwrap.hpp"

#define XIEITE_OPT(...) XIEITE_IF(XIEITE_ANY(XIEITE_UNWRAP(__VA_ARGS__)))
