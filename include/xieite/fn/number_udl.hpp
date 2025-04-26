#ifndef DETAIL_XIEITE_HEADER_FN_NUMBER_UDL
#	define DETAIL_XIEITE_HEADER_FN_NUMBER_UDL
#
#	include <cstddef>
#	include <cstdint>
#	include "../math/ssize_t.hpp"
#	include "../pp/feat.hpp"
#
#	if XIEITE_FEAT_I128
#		include "../math/int128_t.hpp"
#	endif
#
#	if XIEITE_FEAT_F16 || XIEITE_FEAT_F32 || XIEITE_FEAT_F64 || XIEITE_FEAT_F128
#		include <stdfloat>
#	endif

namespace xieite::number_udl {
	[[nodiscard]] consteval auto operator""_i(unsigned long long int x) noexcept {
		return static_cast<int>(x);
	}

	[[nodiscard]] consteval auto operator""_i(long double x) noexcept {
		return static_cast<signed int>(x);
	}

	[[nodiscard]] consteval auto operator""_u(unsigned long long int x) noexcept {
		return static_cast<unsigned int>(x);
	}

	[[nodiscard]] consteval auto operator""_u(long double x) noexcept {
		return static_cast<unsigned int>(x);
	}

	[[nodiscard]] consteval auto operator""_il(unsigned long long int x) noexcept {
		return static_cast<long int>(x);
	}

	[[nodiscard]] consteval auto operator""_il(long double x) noexcept {
		return static_cast<long int>(x);
	}

	[[nodiscard]] consteval auto operator""_ul(unsigned long long int x) noexcept {
		return static_cast<unsigned long int>(x);
	}

	[[nodiscard]] consteval auto operator""_ul(long double x) noexcept {
		return static_cast<unsigned long int>(x);
	}

	[[nodiscard]] consteval auto operator""_ill(unsigned long long int x) noexcept {
		return static_cast<long long int>(x);
	}

	[[nodiscard]] consteval auto operator""_ill(long double x) noexcept {
		return static_cast<long long int>(x);
	}

	[[nodiscard]] consteval auto operator""_ull(unsigned long long int x) noexcept {
		return static_cast<unsigned long long int>(x);
	}

	[[nodiscard]] consteval auto operator""_ull(long double x) noexcept {
		return static_cast<unsigned long long int>(x);
	}

	[[nodiscard]] consteval auto operator""_is(unsigned long long int x) noexcept {
		return static_cast<short int>(x);
	}

	[[nodiscard]] consteval auto operator""_is(long double x) noexcept {
		return static_cast<short int>(x);
	}

	[[nodiscard]] consteval auto operator""_us(unsigned long long int x) noexcept {
		return static_cast<unsigned short int>(x);
	}

	[[nodiscard]] consteval auto operator""_us(long double x) noexcept {
		return static_cast<unsigned short int>(x);
	}

	[[nodiscard]] consteval bool operator""_b(unsigned long long int x) noexcept {
		return x;
	}

	[[nodiscard]] consteval bool operator""_b(long double x) noexcept {
		return static_cast<bool>(x);
	}

	[[nodiscard]] consteval auto operator""_c(unsigned long long int x) noexcept {
		return static_cast<char>(x);
	}

	[[nodiscard]] consteval auto operator""_c(long double x) noexcept {
		return static_cast<char>(x);
	}

	[[nodiscard]] consteval auto operator""_uc(unsigned long long int x) noexcept {
		return static_cast<unsigned char>(x);
	}

	[[nodiscard]] consteval auto operator""_uc(long double x) noexcept {
		return static_cast<unsigned char>(x);
	}

	[[nodiscard]] consteval auto operator""_ic(unsigned long long int x) noexcept {
		return static_cast<signed char>(x);
	}

	[[nodiscard]] consteval auto operator""_ic(long double x) noexcept {
		return static_cast<signed char>(x);
	}

	[[nodiscard]] consteval auto operator""_cw(unsigned long long int x) noexcept {
		return static_cast<wchar_t>(x);
	}

	[[nodiscard]] consteval auto operator""_cw(long double x) noexcept {
		return static_cast<wchar_t>(x);
	}

	[[nodiscard]] consteval auto operator""_c8(unsigned long long int x) noexcept {
		return static_cast<char8_t>(x);
	}

	[[nodiscard]] consteval auto operator""_c8(long double x) noexcept {
		return static_cast<char8_t>(x);
	}

	[[nodiscard]] consteval auto operator""_c16(unsigned long long int x) noexcept {
		return static_cast<char16_t>(x);
	}

	[[nodiscard]] consteval auto operator""_c16(long double x) noexcept {
		return static_cast<char16_t>(x);
	}

	[[nodiscard]] consteval auto operator""_c32(unsigned long long int x) noexcept {
		return static_cast<char32_t>(x);
	}

	[[nodiscard]] consteval auto operator""_c32(long double x) noexcept {
		return static_cast<char32_t>(x);
	}

#	if XIEITE_FEAT_I8
	[[nodiscard]] consteval auto operator""_u8(unsigned long long int x) noexcept {
		return static_cast<std::uint8_t>(x);
	}

	[[nodiscard]] consteval auto operator""_u8(long double x) noexcept {
		return static_cast<std::uint8_t>(x);
	}

	[[nodiscard]] consteval auto operator""_i8(unsigned long long int x) noexcept {
		return static_cast<std::int8_t>(x);
	}

	[[nodiscard]] consteval auto operator""_i8(long double x) noexcept {
		return static_cast<std::int8_t>(x);
	}
#	endif

	[[nodiscard]] consteval auto operator""_u8f(unsigned long long int x) noexcept {
		return static_cast<std::uint_fast8_t>(x);
	}

	[[nodiscard]] consteval auto operator""_u8f(long double x) noexcept {
		return static_cast<std::uint_fast8_t>(x);
	}

	[[nodiscard]] consteval auto operator""_i8f(unsigned long long int x) noexcept {
		return static_cast<std::int_fast8_t>(x);
	}

	[[nodiscard]] consteval auto operator""_i8f(long double x) noexcept {
		return static_cast<std::int_fast8_t>(x);
	}

	[[nodiscard]] consteval auto operator""_u8l(unsigned long long int x) noexcept {
		return static_cast<std::uint_least8_t>(x);
	}

	[[nodiscard]] consteval auto operator""_u8l(long double x) noexcept {
		return static_cast<std::uint_least8_t>(x);
	}

	[[nodiscard]] consteval auto operator""_i8l(unsigned long long int x) noexcept {
		return static_cast<std::int_least8_t>(x);
	}

	[[nodiscard]] consteval auto operator""_i8l(long double x) noexcept {
		return static_cast<std::int_least8_t>(x);
	}

#	if XIEITE_FEAT_I16
	[[nodiscard]] consteval auto operator""_u16(unsigned long long int x) noexcept {
		return static_cast<std::uint16_t>(x);
	}

	[[nodiscard]] consteval auto operator""_u16(long double x) noexcept {
		return static_cast<std::uint16_t>(x);
	}

	[[nodiscard]] consteval auto operator""_i16(unsigned long long int x) noexcept {
		return static_cast<std::int16_t>(x);
	}

	[[nodiscard]] consteval auto operator""_i16(long double x) noexcept {
		return static_cast<std::int16_t>(x);
	}
#	endif

	[[nodiscard]] consteval auto operator""_u16f(unsigned long long int x) noexcept {
		return static_cast<std::uint_fast16_t>(x);
	}

	[[nodiscard]] consteval auto operator""_u16f(long double x) noexcept {
		return static_cast<std::uint_fast16_t>(x);
	}

	[[nodiscard]] consteval auto operator""_i16f(unsigned long long int x) noexcept {
		return static_cast<std::int_fast16_t>(x);
	}

	[[nodiscard]] consteval auto operator""_i16f(long double x) noexcept {
		return static_cast<std::int_fast16_t>(x);
	}

	[[nodiscard]] consteval auto operator""_u16l(unsigned long long int x) noexcept {
		return static_cast<std::uint_least16_t>(x);
	}

	[[nodiscard]] consteval auto operator""_u16l(long double x) noexcept {
		return static_cast<std::uint_least16_t>(x);
	}

	[[nodiscard]] consteval auto operator""_i16l(unsigned long long int x) noexcept {
		return static_cast<std::int_least16_t>(x);
	}

	[[nodiscard]] consteval auto operator""_i16l(long double x) noexcept {
		return static_cast<std::int_least16_t>(x);
	}

#	if XIEITE_FEAT_I32
	[[nodiscard]] consteval auto operator""_u32(unsigned long long int x) noexcept {
		return static_cast<std::uint32_t>(x);
	}

	[[nodiscard]] consteval auto operator""_u32(long double x) noexcept {
		return static_cast<std::uint32_t>(x);
	}

	[[nodiscard]] consteval auto operator""_i32(unsigned long long int x) noexcept {
		return static_cast<std::int32_t>(x);
	}

	[[nodiscard]] consteval auto operator""_i32(long double x) noexcept {
		return static_cast<std::int32_t>(x);
	}
#	endif

	[[nodiscard]] consteval auto operator""_u32f(unsigned long long int x) noexcept {
		return static_cast<std::uint_fast32_t>(x);
	}

	[[nodiscard]] consteval auto operator""_u32f(long double x) noexcept {
		return static_cast<std::uint_fast32_t>(x);
	}

	[[nodiscard]] consteval auto operator""_i32f(unsigned long long int x) noexcept {
		return static_cast<std::int_fast32_t>(x);
	}

	[[nodiscard]] consteval auto operator""_i32f(long double x) noexcept {
		return static_cast<std::int_fast32_t>(x);
	}

	[[nodiscard]] consteval auto operator""_u32l(unsigned long long int x) noexcept {
		return static_cast<std::uint_least32_t>(x);
	}

	[[nodiscard]] consteval auto operator""_u32l(long double x) noexcept {
		return static_cast<std::uint_least32_t>(x);
	}

	[[nodiscard]] consteval auto operator""_i32l(unsigned long long int x) noexcept {
		return static_cast<std::int_least32_t>(x);
	}

	[[nodiscard]] consteval auto operator""_i32l(long double x) noexcept {
		return static_cast<std::int_least32_t>(x);
	}

#	if XIEITE_FEAT_I64
	[[nodiscard]] consteval auto operator""_u64(unsigned long long int x) noexcept {
		return static_cast<std::uint64_t>(x);
	}

	[[nodiscard]] consteval auto operator""_u64(long double x) noexcept {
		return static_cast<std::uint64_t>(x);
	}

	[[nodiscard]] consteval auto operator""_i64(unsigned long long int x) noexcept {
		return static_cast<std::int64_t>(x);
	}

	[[nodiscard]] consteval auto operator""_i64(long double x) noexcept {
		return static_cast<std::int64_t>(x);
	}
#	endif

	[[nodiscard]] consteval auto operator""_u64f(unsigned long long int x) noexcept {
		return static_cast<std::uint_fast64_t>(x);
	}

	[[nodiscard]] consteval auto operator""_u64f(long double x) noexcept {
		return static_cast<std::uint_fast64_t>(x);
	}

	[[nodiscard]] consteval auto operator""_i64f(unsigned long long int x) noexcept {
		return static_cast<std::int_fast64_t>(x);
	}

	[[nodiscard]] consteval auto operator""_i64f(long double x) noexcept {
		return static_cast<std::int_fast64_t>(x);
	}

	[[nodiscard]] consteval auto operator""_u64l(unsigned long long int x) noexcept {
		return static_cast<std::uint_least64_t>(x);
	}

	[[nodiscard]] consteval auto operator""_u64l(long double x) noexcept {
		return static_cast<std::uint_least64_t>(x);
	}

	[[nodiscard]] consteval auto operator""_i64l(unsigned long long int x) noexcept {
		return static_cast<std::int_least64_t>(x);
	}

	[[nodiscard]] consteval auto operator""_i64l(long double x) noexcept {
		return static_cast<std::int_least64_t>(x);
	}

#	if XIEITE_FEAT_I128
	[[nodiscard]] consteval auto operator""_u128(unsigned long long int x) noexcept {
		return static_cast<xieite::uint128_t>(x);
	}

	[[nodiscard]] consteval auto operator""_u128(long double x) noexcept {
		return static_cast<xieite::uint128_t>(x);
	}

	[[nodiscard]] consteval auto operator""_i128(unsigned long long int x) noexcept {
		return static_cast<xieite::int128_t>(x);
	}

	[[nodiscard]] consteval auto operator""_i128(long double x) noexcept {
		return static_cast<xieite::int128_t>(x);
	}
#	endif

	[[nodiscard]] consteval auto operator""_um(unsigned long long int x) noexcept {
		return static_cast<std::uintmax_t>(x);
	}

	[[nodiscard]] consteval auto operator""_um(long double x) noexcept {
		return static_cast<std::uintmax_t>(x);
	}

	[[nodiscard]] consteval auto operator""_im(unsigned long long int x) noexcept {
		return static_cast<std::intmax_t>(x);
	}

	[[nodiscard]] consteval auto operator""_im(long double x) noexcept {
		return static_cast<std::intmax_t>(x);
	}

	[[nodiscard]] consteval auto operator""_up(unsigned long long int x) noexcept {
		return static_cast<std::uintptr_t>(x);
	}

	[[nodiscard]] consteval auto operator""_up(long double x) noexcept {
		return static_cast<std::uintptr_t>(x);
	}

	[[nodiscard]] consteval auto operator""_ip(unsigned long long int x) noexcept {
		return static_cast<std::intptr_t>(x);
	}

	[[nodiscard]] consteval auto operator""_ip(long double x) noexcept {
		return static_cast<std::intptr_t>(x);
	}

	[[nodiscard]] consteval auto operator""_pd(unsigned long long int x) noexcept {
		return static_cast<std::ptrdiff_t>(x);
	}

	[[nodiscard]] consteval auto operator""_pd(long double x) noexcept {
		return static_cast<std::ptrdiff_t>(x);
	}

	[[nodiscard]] consteval auto operator""_uz(unsigned long long int x) noexcept {
		return static_cast<std::size_t>(x);
	}

	[[nodiscard]] consteval auto operator""_uz(long double x) noexcept {
		return static_cast<std::size_t>(x);
	}

	[[nodiscard]] consteval auto operator""_iz(unsigned long long int x) noexcept {
		return static_cast<xieite::ssize_t>(x);
	}

	[[nodiscard]] consteval auto operator""_iz(long double x) noexcept {
		return static_cast<xieite::ssize_t>(x);
	}

	[[nodiscard]] consteval auto operator""_f(unsigned long long int x) noexcept {
		return static_cast<float>(x);
	}

	[[nodiscard]] consteval auto operator""_f(long double x) noexcept {
		return static_cast<float>(x);
	}

	[[nodiscard]] consteval auto operator""_d(unsigned long long int x) noexcept {
		return static_cast<double>(x);
	}

	[[nodiscard]] consteval auto operator""_d(long double x) noexcept {
		return static_cast<double>(x);
	}

	[[nodiscard]] consteval auto operator""_dl(unsigned long long int x) noexcept {
		return static_cast<long double>(x);
	}

	[[nodiscard]] consteval auto operator""_dl(long double x) noexcept {
		return static_cast<long double>(x);
	}

#	if XIEITE_FEAT_F16
	[[nodiscard]] consteval auto operator""_f16(unsigned long long int x) noexcept {
		return static_cast<std::float16_t>(x);
	}

	[[nodiscard]] consteval auto operator""_f16(long double x) noexcept {
		return static_cast<std::float16_t>(x);
	}
#	endif
#
#	if XIEITE_FEAT_F32
	[[nodiscard]] consteval auto operator""_f32(unsigned long long int x) noexcept {
		return static_cast<std::float32_t>(x);
	}

	[[nodiscard]] consteval auto operator""_f32(long double x) noexcept {
		return static_cast<std::float32_t>(x);
	}
#	endif
#
#	if XIEITE_FEAT_F64
	[[nodiscard]] consteval auto operator""_f64(unsigned long long int x) noexcept {
		return static_cast<std::float64_t>(x);
	}

	[[nodiscard]] consteval auto operator""_f64(long double x) noexcept {
		return static_cast<std::float64_t>(x);
	}
#	endif
#
#	if XIEITE_FEAT_F128
	[[nodiscard]] consteval auto operator""_f128(unsigned long long int x) noexcept {
		return static_cast<std::float128_t>(x);
	}

	[[nodiscard]] consteval auto operator""_f128(long double x) noexcept {
		return static_cast<std::float128_t>(x);
	}
#	endif
#
#	if XIEITE_FEAT_FBRAIN
	[[nodiscard]] consteval auto operator""_fb(unsigned long long int x) noexcept {
		return static_cast<std::bfloat16_t>(x);
	}

	[[nodiscard]] consteval auto operator""_fb(long double x) noexcept {
		return static_cast<std::bfloat16_t>(x);
	}
#	endif
}

#endif
