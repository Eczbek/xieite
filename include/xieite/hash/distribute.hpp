#pragma once

#include <concepts>
#include <cstdint>
#include <xieite/math/alternatingBits.hpp>
#include <xieite/math/robert.hpp>
#include <xieite/math/xorShift.hpp>

namespace xieite::hash {
	template<std::unsigned_integral UnsignedIntegral>
	[[nodiscard]]
	constexpr UnsignedIntegral distribute(const UnsignedIntegral value) noexcept {
		return xieite::math::robert<UnsignedIntegral> * xieite::math::xorShift(xieite::math::alternatingBits<UnsignedIntegral> * xieite::math::xorShift(value, sizeof(UnsignedIntegral) * 4), sizeof(UnsignedIntegral) * 4);
	}
}
