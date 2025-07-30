#ifndef DETAIL_XIEITE_HEADER_MATH_HASH_DISTRIBUTE
#	define DETAIL_XIEITE_HEADER_MATH_HASH_DISTRIBUTE
#
#	include <concepts>
#	include <limits>
#	include <numbers>
#	include "../math/xor_shift.hpp"
#	include "../trait/try_unsigned.hpp"

namespace xieite {
	template<std::integral Int, std::floating_point Phi = double>
	[[nodiscard]] constexpr Int hash_distribute(Int x) noexcept {
		static constexpr auto max = std::numeric_limits<xieite::try_unsigned<Int>>::max();
		return static_cast<Int>(static_cast<Phi>(max) / std::numbers::phi_v<Phi>) * xieite::xor_shift(max / 3 * xieite::xor_shift(x, sizeof(Int) * 4), sizeof(Int) * 4);
	}
}

#endif
