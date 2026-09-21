#ifndef DETAIL_XTE_HEADER_ABS
#	define DETAIL_XTE_HEADER_ABS
#
#	include "./math/float.hpp"
#	include "./trait/is_arithmetic.hpp"
#	include "./trait/try_unsigned.hpp"

namespace xte {
	[[nodiscard]] constexpr auto abs(xte::is_arithmetic auto value) noexcept {
		using unsigned_type = xte::try_unsigned<decltype(value)>;
		return static_cast<unsigned_type>(xte::is_neg(value) ? -static_cast<unsigned_type>(value) : static_cast<unsigned_type>(value));
	}
}

#endif
