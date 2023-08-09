#ifndef XIEITE_HEADER__HASHES__DISTRIBUTE
#	define XIEITE_HEADER__HASHES__DISTRIBUTE

#	include <concepts>
#	include <cstdint>
#	include "../math/alternatingBits.hpp"
#	include "../math/robert.hpp"
#	include "../math/xorShift.hpp"

namespace xieite::hashes {
	template<std::unsigned_integral UnsignedInteger>
	constexpr UnsignedInteger distribute(const UnsignedInteger value) noexcept {
		return xieite::math::robert<UnsignedInteger> * xieite::math::xorShift(xieite::math::alternatingBits<UnsignedInteger> * xieite::math::xorShift(value, sizeof(UnsignedInteger) * 4), sizeof(UnsignedInteger) * 4);
	}
}

#endif
