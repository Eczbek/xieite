#pragma once

#include <xieite/complement.hpp>
#include <xieite/not.hpp>

#define XIEITE_BOOLEAN(value_) XIEITE_COMPLEMENT(XIEITE_NOT(value_))
