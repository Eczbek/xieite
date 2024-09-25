#pragma once

#include <xieite/concatenate.hpp>

#define XIEITE_COMPLEMENT(boolean_) XIEITE_CONCATENATE_PRIMITIVE(XIEITE_DETAIL_COMPLEMENT_, boolean_)

#define XIEITE_DETAIL_COMPLEMENT_0 1
#define XIEITE_DETAIL_COMPLEMENT_1 0
