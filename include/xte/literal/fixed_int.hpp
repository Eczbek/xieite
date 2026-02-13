#ifndef DETAIL_XTE_HEADER_LITERAL_FIXED_INT
#	define DETAIL_XTE_HEADER_LITERAL_FIXED_INT
#
#	include "../preproc/feature.hpp"
#	include "../util/types.hpp"

namespace xte::literal::fixed_int {
#	if XTE_FEATURE_INT_8
	[[nodiscard]] constexpr xte::u8 operator""_u8(unsigned long long x) noexcept {
		return static_cast<xte::u8>(x);
	}

	[[nodiscard]] constexpr xte::i8 operator""_i8(unsigned long long x) noexcept {
		return static_cast<xte::i8>(x);
	}
#	endif
#	if XTE_FEATURE_INT_16
	[[nodiscard]] constexpr xte::u16 operator""_u16(unsigned long long x) noexcept {
		return static_cast<xte::u16>(x);
	}

	[[nodiscard]] constexpr xte::i16 operator""_i16(unsigned long long x) noexcept {
		return static_cast<xte::i16>(x);
	}
#	endif
#	if XTE_FEATURE_INT_32
	[[nodiscard]] constexpr xte::u32 operator""_u32(unsigned long long x) noexcept {
		return static_cast<xte::u32>(x);
	}

	[[nodiscard]] constexpr xte::i32 operator""_i32(unsigned long long x) noexcept {
		return static_cast<xte::i32>(x);
	}
#	endif
#	if XTE_FEATURE_INT_64
	[[nodiscard]] constexpr xte::u64 operator""_u64(unsigned long long x) noexcept {
		return static_cast<xte::u64>(x);
	}

	[[nodiscard]] constexpr xte::i64 operator""_i64(unsigned long long x) noexcept {
		return static_cast<xte::i64>(x);
	}
#	endif
#	if XTE_FEATURE_INT_128
	template<char... digits>
	[[nodiscard]] consteval xte::u128 operator""_u128() noexcept {
		xte::u128 result = 0;
		(void)(... && ((digits == '\'') || ((digits >= '0') && (digits <= '9') && ((result *= 10) += digits - '0'))));
		return result;
	}

	template<char... digits>
	[[nodiscard]] consteval xte::i128 operator""_i128() noexcept {
		xte::u128 result = 0;
		(void)(... && ((digits == '\'') || ((digits >= '0') && (digits <= '9') && ((result *= 10) += digits - '0'))));
		return static_cast<xte::i128>(result);
	}
#	endif
}

#endif
