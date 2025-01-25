#pragma once

#include <concepts>

namespace xieite {
	template<std::unsigned_integral T>
	struct dbl_uint {
		T lower;
		T upper;
	};
}
