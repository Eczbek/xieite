#ifndef XIEITE_HEADER__HASHES__DISTRIBUTE
#	define XIEITE_HEADER__HASHES__DISTRIBUTE

#	include <concepts>
#	include <cstdint>
#	include "../math/alternatingBits.hpp"
#	include "../math/robert.hpp"
#	include "../math/xorShift.hpp"

namespace xieite::hashes {
	template<std::unsigned_integral UnsignedIntegral>
	[[nodiscard]]
	constexpr UnsignedIntegral distribute(const UnsignedIntegral value) noexcept {
		return xieite::math::robert<UnsignedIntegral> * xieite::math::xorShift(xieite::math::alternatingBits<UnsignedIntegral> * xieite::math::xorShift(value, sizeof(UnsignedIntegral) * 4), sizeof(UnsignedIntegral) * 4);
	}
}

#endif
