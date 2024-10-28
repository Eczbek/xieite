module;

#include <xieite/feat.hpp>

export module xieite:num_literal;

import std;
import :ssize;

#if XIEITE_FEAT_I128
import :int128;
#endif

export namespace xieite::num_literal {
	[[nodiscard]] constexpr auto operator""_i(unsigned long long int value) noexcept {
		return static_cast<int>(value);
	}

	[[nodiscard]] constexpr auto operator""_i(long double value) noexcept {
		return static_cast<signed int>(value);
	}

	[[nodiscard]] constexpr auto operator""_u(unsigned long long int value) noexcept {
		return static_cast<unsigned int>(value);
	}

	[[nodiscard]] constexpr auto operator""_u(long double value) noexcept {
		return static_cast<unsigned int>(value);
	}

	[[nodiscard]] constexpr auto operator""_il(unsigned long long int value) noexcept {
		return static_cast<long int>(value);
	}

	[[nodiscard]] constexpr auto operator""_il(long double value) noexcept {
		return static_cast<long int>(value);
	}

	[[nodiscard]] constexpr auto operator""_ul(unsigned long long int value) noexcept {
		return static_cast<unsigned long int>(value);
	}

	[[nodiscard]] constexpr auto operator""_ul(long double value) noexcept {
		return static_cast<unsigned long int>(value);
	}

	[[nodiscard]] constexpr auto operator""_ill(unsigned long long int value) noexcept {
		return static_cast<long long int>(value);
	}

	[[nodiscard]] constexpr auto operator""_ill(long double value) noexcept {
		return static_cast<long long int>(value);
	}

	[[nodiscard]] constexpr auto operator""_ull(unsigned long long int value) noexcept {
		return static_cast<unsigned long long int>(value);
	}

	[[nodiscard]] constexpr auto operator""_ull(long double value) noexcept {
		return static_cast<unsigned long long int>(value);
	}

	[[nodiscard]] constexpr auto operator""_is(unsigned long long int value) noexcept {
		return static_cast<short int>(value);
	}

	[[nodiscard]] constexpr auto operator""_is(long double value) noexcept {
		return static_cast<short int>(value);
	}

	[[nodiscard]] constexpr auto operator""_us(unsigned long long int value) noexcept {
		return static_cast<unsigned short int>(value);
	}

	[[nodiscard]] constexpr auto operator""_us(long double value) noexcept {
		return static_cast<unsigned short int>(value);
	}

	[[nodiscard]] constexpr auto operator""_b(unsigned long long int value) noexcept {
		return static_cast<bool>(value);
	}

	[[nodiscard]] constexpr auto operator""_b(long double value) noexcept {
		return static_cast<bool>(value);
	}

	[[nodiscard]] constexpr auto operator""_c(unsigned long long int value) noexcept {
		return static_cast<char>(value);
	}

	[[nodiscard]] constexpr auto operator""_c(long double value) noexcept {
		return static_cast<char>(value);
	}

	[[nodiscard]] constexpr auto operator""_uc(unsigned long long int value) noexcept {
		return static_cast<unsigned char>(value);
	}

	[[nodiscard]] constexpr auto operator""_uc(long double value) noexcept {
		return static_cast<unsigned char>(value);
	}

	[[nodiscard]] constexpr auto operator""_ic(unsigned long long int value) noexcept {
		return static_cast<signed char>(value);
	}

	[[nodiscard]] constexpr auto operator""_ic(long double value) noexcept {
		return static_cast<signed char>(value);
	}

	[[nodiscard]] constexpr auto operator""_cw(unsigned long long int value) noexcept {
		return static_cast<wchar_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_cw(long double value) noexcept {
		return static_cast<wchar_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_c8(unsigned long long int value) noexcept {
		return static_cast<char8_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_c8(long double value) noexcept {
		return static_cast<char8_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_c16(unsigned long long int value) noexcept {
		return static_cast<char16_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_c16(long double value) noexcept {
		return static_cast<char16_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_c32(unsigned long long int value) noexcept {
		return static_cast<char32_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_c32(long double value) noexcept {
		return static_cast<char32_t>(value);
	}

#if XIEITE_FEAT_I8
	[[nodiscard]] constexpr auto operator""_u8(unsigned long long int value) noexcept {
		return static_cast<std::uint8_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_u8(long double value) noexcept {
		return static_cast<std::uint8_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_i8(unsigned long long int value) noexcept {
		return static_cast<std::int8_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_i8(long double value) noexcept {
		return static_cast<std::int8_t>(value);
	}
#endif

	[[nodiscard]] constexpr auto operator""_u8f(unsigned long long int value) noexcept {
		return static_cast<std::uint_fast8_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_u8f(long double value) noexcept {
		return static_cast<std::uint_fast8_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_i8f(unsigned long long int value) noexcept {
		return static_cast<std::int_fast8_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_i8f(long double value) noexcept {
		return static_cast<std::int_fast8_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_u8l(unsigned long long int value) noexcept {
		return static_cast<std::uint_least8_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_u8l(long double value) noexcept {
		return static_cast<std::uint_least8_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_i8l(unsigned long long int value) noexcept {
		return static_cast<std::int_least8_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_i8l(long double value) noexcept {
		return static_cast<std::int_least8_t>(value);
	}

#if XIEITE_FEAT_I16
	[[nodiscard]] constexpr auto operator""_u16(unsigned long long int value) noexcept {
		return static_cast<std::uint16_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_u16(long double value) noexcept {
		return static_cast<std::uint16_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_i16(unsigned long long int value) noexcept {
		return static_cast<std::int16_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_i16(long double value) noexcept {
		return static_cast<std::int16_t>(value);
	}
#endif

	[[nodiscard]] constexpr auto operator""_u16f(unsigned long long int value) noexcept {
		return static_cast<std::uint_fast16_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_u16f(long double value) noexcept {
		return static_cast<std::uint_fast16_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_i16f(unsigned long long int value) noexcept {
		return static_cast<std::int_fast16_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_i16f(long double value) noexcept {
		return static_cast<std::int_fast16_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_u16l(unsigned long long int value) noexcept {
		return static_cast<std::uint_least16_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_u16l(long double value) noexcept {
		return static_cast<std::uint_least16_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_i16l(unsigned long long int value) noexcept {
		return static_cast<std::int_least16_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_i16l(long double value) noexcept {
		return static_cast<std::int_least16_t>(value);
	}

#if XIEITE_FEAT_I32
	[[nodiscard]] constexpr auto operator""_u32(unsigned long long int value) noexcept {
		return static_cast<std::uint32_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_u32(long double value) noexcept {
		return static_cast<std::uint32_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_i32(unsigned long long int value) noexcept {
		return static_cast<std::int32_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_i32(long double value) noexcept {
		return static_cast<std::int32_t>(value);
	}
#endif

	[[nodiscard]] constexpr auto operator""_u32f(unsigned long long int value) noexcept {
		return static_cast<std::uint_fast32_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_u32f(long double value) noexcept {
		return static_cast<std::uint_fast32_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_i32f(unsigned long long int value) noexcept {
		return static_cast<std::int_fast32_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_i32f(long double value) noexcept {
		return static_cast<std::int_fast32_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_u32l(unsigned long long int value) noexcept {
		return static_cast<std::uint_least32_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_u32l(long double value) noexcept {
		return static_cast<std::uint_least32_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_i32l(unsigned long long int value) noexcept {
		return static_cast<std::int_least32_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_i32l(long double value) noexcept {
		return static_cast<std::int_least32_t>(value);
	}

#if XIEITE_FEAT_I64
	[[nodiscard]] constexpr auto operator""_u64(unsigned long long int value) noexcept {
		return static_cast<std::uint64_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_u64(long double value) noexcept {
		return static_cast<std::uint64_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_i64(unsigned long long int value) noexcept {
		return static_cast<std::int64_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_i64(long double value) noexcept {
		return static_cast<std::int64_t>(value);
	}
#endif

	[[nodiscard]] constexpr auto operator""_u64f(unsigned long long int value) noexcept {
		return static_cast<std::uint_fast64_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_u64f(long double value) noexcept {
		return static_cast<std::uint_fast64_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_i64f(unsigned long long int value) noexcept {
		return static_cast<std::int_fast64_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_i64f(long double value) noexcept {
		return static_cast<std::int_fast64_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_u64l(unsigned long long int value) noexcept {
		return static_cast<std::uint_least64_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_u64l(long double value) noexcept {
		return static_cast<std::uint_least64_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_i64l(unsigned long long int value) noexcept {
		return static_cast<std::int_least64_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_i64l(long double value) noexcept {
		return static_cast<std::int_least64_t>(value);
	}

#if XIEITE_FEAT_I128
	[[nodiscard]] constexpr auto operator""_u128(unsigned long long int value) noexcept {
		return static_cast<xieite::uint128>(value);
	}

	[[nodiscard]] constexpr auto operator""_u128(long double value) noexcept {
		return static_cast<xieite::uint128>(value);
	}

	[[nodiscard]] constexpr auto operator""_i128(unsigned long long int value) noexcept {
		return static_cast<xieite::int128>(value);
	}

	[[nodiscard]] constexpr auto operator""_i128(long double value) noexcept {
		return static_cast<xieite::int128>(value);
	}
#endif

	[[nodiscard]] constexpr auto operator""_um(unsigned long long int value) noexcept {
		return static_cast<std::uintmax_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_um(long double value) noexcept {
		return static_cast<std::uintmax_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_im(unsigned long long int value) noexcept {
		return static_cast<std::intmax_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_im(long double value) noexcept {
		return static_cast<std::intmax_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_up(unsigned long long int value) noexcept {
		return static_cast<std::uintptr_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_up(long double value) noexcept {
		return static_cast<std::uintptr_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_ip(unsigned long long int value) noexcept {
		return static_cast<std::intptr_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_ip(long double value) noexcept {
		return static_cast<std::intptr_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_pd(unsigned long long int value) noexcept {
		return static_cast<std::ptrdiff_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_pd(long double value) noexcept {
		return static_cast<std::ptrdiff_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_uz(unsigned long long int value) noexcept {
		return static_cast<std::size_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_uz(long double value) noexcept {
		return static_cast<std::size_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_iz(unsigned long long int value) noexcept {
		return static_cast<xieite::ssize>(value);
	}

	[[nodiscard]] constexpr auto operator""_iz(long double value) noexcept {
		return static_cast<xieite::ssize>(value);
	}

	[[nodiscard]] constexpr auto operator""_f(unsigned long long int value) noexcept {
		return static_cast<float>(value);
	}

	[[nodiscard]] constexpr auto operator""_f(long double value) noexcept {
		return static_cast<float>(value);
	}

	[[nodiscard]] constexpr auto operator""_d(unsigned long long int value) noexcept {
		return static_cast<double>(value);
	}

	[[nodiscard]] constexpr auto operator""_d(long double value) noexcept {
		return static_cast<double>(value);
	}

	[[nodiscard]] constexpr auto operator""_dl(unsigned long long int value) noexcept {
		return static_cast<long double>(value);
	}

	[[nodiscard]] constexpr auto operator""_dl(long double value) noexcept {
		return static_cast<long double>(value);
	}

#if XIEITE_FEAT_F16
	[[nodiscard]] constexpr auto operator""_f16(unsigned long long int value) noexcept {
		return static_cast<std::float16_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_f16(long double value) noexcept {
		return static_cast<std::float16_t>(value);
	}
#endif

#if XIEITE_FEAT_F32
	[[nodiscard]] constexpr auto operator""_f32(unsigned long long int value) noexcept {
		return static_cast<std::float32_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_f32(long double value) noexcept {
		return static_cast<std::float32_t>(value);
	}
#endif

#if XIEITE_FEAT_F64
	[[nodiscard]] constexpr auto operator""_f64(unsigned long long int value) noexcept {
		return static_cast<std::float64_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_f64(long double value) noexcept {
		return static_cast<std::float64_t>(value);
	}
#endif

#if XIEITE_FEAT_F128
	[[nodiscard]] constexpr auto operator""_f128(unsigned long long int value) noexcept {
		return static_cast<std::float128_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_f128(long double value) noexcept {
		return static_cast<std::float128_t>(value);
	}
#endif

#if XIEITE_FEAT_FBRAIN
	[[nodiscard]] constexpr auto operator""_fb(unsigned long long int value) noexcept {
		return static_cast<std::bfloat16_t>(value);
	}

	[[nodiscard]] constexpr auto operator""_fb(long double value) noexcept {
		return static_cast<std::bfloat16_t>(value);
	}
#endif
}
