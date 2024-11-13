export module xieite:dbl_mul;

import std;
import :bit_size;
import :dbl_uint;

export namespace xieite {
	template<std::unsigned_integral T>
	[[nodiscard]] constexpr xieite::dbl_uint<T> dbl_mul(T multiplier, T multiplicand) noexcept {
		static constexpr T half_size = xieite::bit_size<T> / 2;
		static constexpr T half_bits = static_cast<T>(-1) >> half_size;
		const T low0 = multiplier & half_bits;
		const T high0 = multiplier >> half_size;
		const T low1 = multiplicand & half_bits;
		const T high1 = multiplicand >> half_size;
		const T prod0 = low0 * low1;
		const T prod1 = low0 * high1;
		const T prod2 = high0 * low1;
		return xieite::dbl_uint<T>(prod0 + (prod1 << half_size) + (prod2 << half_size), high0 * high1 + (prod1 >> half_size) + (prod2 >> half_size) + (half_bits & (((prod0 >> half_size) + (prod1 & half_bits) + (prod2 & half_bits)) >> half_size)));
	}
}
