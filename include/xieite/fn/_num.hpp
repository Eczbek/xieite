#ifndef DETAIL_XIEITE_HEADER_FN_NUM
#	define DETAIL_XIEITE_HEADER_FN_NUM
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

namespace xieite::_num {
	[[nodiscard]] consteval auto operator""_i(unsigned long long int n) noexcept {
		return static_cast<int>(n);
	}

	[[nodiscard]] consteval auto operator""_i(long double n) noexcept {
		return static_cast<signed int>(n);
	}

	[[nodiscard]] consteval auto operator""_u(unsigned long long int n) noexcept {
		return static_cast<unsigned int>(n);
	}

	[[nodiscard]] consteval auto operator""_u(long double n) noexcept {
		return static_cast<unsigned int>(n);
	}

	[[nodiscard]] consteval auto operator""_il(unsigned long long int n) noexcept {
		return static_cast<long int>(n);
	}

	[[nodiscard]] consteval auto operator""_il(long double n) noexcept {
		return static_cast<long int>(n);
	}

	[[nodiscard]] consteval auto operator""_ul(unsigned long long int n) noexcept {
		return static_cast<unsigned long int>(n);
	}

	[[nodiscard]] consteval auto operator""_ul(long double n) noexcept {
		return static_cast<unsigned long int>(n);
	}

	[[nodiscard]] consteval auto operator""_ill(unsigned long long int n) noexcept {
		return static_cast<long long int>(n);
	}

	[[nodiscard]] consteval auto operator""_ill(long double n) noexcept {
		return static_cast<long long int>(n);
	}

	[[nodiscard]] consteval auto operator""_ull(unsigned long long int n) noexcept {
		return static_cast<unsigned long long int>(n);
	}

	[[nodiscard]] consteval auto operator""_ull(long double n) noexcept {
		return static_cast<unsigned long long int>(n);
	}

	[[nodiscard]] consteval auto operator""_is(unsigned long long int n) noexcept {
		return static_cast<short int>(n);
	}

	[[nodiscard]] consteval auto operator""_is(long double n) noexcept {
		return static_cast<short int>(n);
	}

	[[nodiscard]] consteval auto operator""_us(unsigned long long int n) noexcept {
		return static_cast<unsigned short int>(n);
	}

	[[nodiscard]] consteval auto operator""_us(long double n) noexcept {
		return static_cast<unsigned short int>(n);
	}

	[[nodiscard]] consteval bool operator""_b(unsigned long long int n) noexcept {
		return n;
	}

	[[nodiscard]] consteval bool operator""_b(long double n) noexcept {
		return n;
	}

	[[nodiscard]] consteval auto operator""_c(unsigned long long int n) noexcept {
		return static_cast<char>(n);
	}

	[[nodiscard]] consteval auto operator""_c(long double n) noexcept {
		return static_cast<char>(n);
	}

	[[nodiscard]] consteval auto operator""_uc(unsigned long long int n) noexcept {
		return static_cast<unsigned char>(n);
	}

	[[nodiscard]] consteval auto operator""_uc(long double n) noexcept {
		return static_cast<unsigned char>(n);
	}

	[[nodiscard]] consteval auto operator""_ic(unsigned long long int n) noexcept {
		return static_cast<signed char>(n);
	}

	[[nodiscard]] consteval auto operator""_ic(long double n) noexcept {
		return static_cast<signed char>(n);
	}

	[[nodiscard]] consteval auto operator""_cw(unsigned long long int n) noexcept {
		return static_cast<wchar_t>(n);
	}

	[[nodiscard]] consteval auto operator""_cw(long double n) noexcept {
		return static_cast<wchar_t>(n);
	}

	[[nodiscard]] consteval auto operator""_c8(unsigned long long int n) noexcept {
		return static_cast<char8_t>(n);
	}

	[[nodiscard]] consteval auto operator""_c8(long double n) noexcept {
		return static_cast<char8_t>(n);
	}

	[[nodiscard]] consteval auto operator""_c16(unsigned long long int n) noexcept {
		return static_cast<char16_t>(n);
	}

	[[nodiscard]] consteval auto operator""_c16(long double n) noexcept {
		return static_cast<char16_t>(n);
	}

	[[nodiscard]] consteval auto operator""_c32(unsigned long long int n) noexcept {
		return static_cast<char32_t>(n);
	}

	[[nodiscard]] consteval auto operator""_c32(long double n) noexcept {
		return static_cast<char32_t>(n);
	}

#	if XIEITE_FEAT_I8
	[[nodiscard]] consteval auto operator""_u8(unsigned long long int n) noexcept {
		return static_cast<std::uint8_t>(n);
	}

	[[nodiscard]] consteval auto operator""_u8(long double n) noexcept {
		return static_cast<std::uint8_t>(n);
	}

	[[nodiscard]] consteval auto operator""_i8(unsigned long long int n) noexcept {
		return static_cast<std::int8_t>(n);
	}

	[[nodiscard]] consteval auto operator""_i8(long double n) noexcept {
		return static_cast<std::int8_t>(n);
	}
#	endif

	[[nodiscard]] consteval auto operator""_u8f(unsigned long long int n) noexcept {
		return static_cast<std::uint_fast8_t>(n);
	}

	[[nodiscard]] consteval auto operator""_u8f(long double n) noexcept {
		return static_cast<std::uint_fast8_t>(n);
	}

	[[nodiscard]] consteval auto operator""_i8f(unsigned long long int n) noexcept {
		return static_cast<std::int_fast8_t>(n);
	}

	[[nodiscard]] consteval auto operator""_i8f(long double n) noexcept {
		return static_cast<std::int_fast8_t>(n);
	}

	[[nodiscard]] consteval auto operator""_u8l(unsigned long long int n) noexcept {
		return static_cast<std::uint_least8_t>(n);
	}

	[[nodiscard]] consteval auto operator""_u8l(long double n) noexcept {
		return static_cast<std::uint_least8_t>(n);
	}

	[[nodiscard]] consteval auto operator""_i8l(unsigned long long int n) noexcept {
		return static_cast<std::int_least8_t>(n);
	}

	[[nodiscard]] consteval auto operator""_i8l(long double n) noexcept {
		return static_cast<std::int_least8_t>(n);
	}

#	if XIEITE_FEAT_I16
	[[nodiscard]] consteval auto operator""_u16(unsigned long long int n) noexcept {
		return static_cast<std::uint16_t>(n);
	}

	[[nodiscard]] consteval auto operator""_u16(long double n) noexcept {
		return static_cast<std::uint16_t>(n);
	}

	[[nodiscard]] consteval auto operator""_i16(unsigned long long int n) noexcept {
		return static_cast<std::int16_t>(n);
	}

	[[nodiscard]] consteval auto operator""_i16(long double n) noexcept {
		return static_cast<std::int16_t>(n);
	}
#	endif

	[[nodiscard]] consteval auto operator""_u16f(unsigned long long int n) noexcept {
		return static_cast<std::uint_fast16_t>(n);
	}

	[[nodiscard]] consteval auto operator""_u16f(long double n) noexcept {
		return static_cast<std::uint_fast16_t>(n);
	}

	[[nodiscard]] consteval auto operator""_i16f(unsigned long long int n) noexcept {
		return static_cast<std::int_fast16_t>(n);
	}

	[[nodiscard]] consteval auto operator""_i16f(long double n) noexcept {
		return static_cast<std::int_fast16_t>(n);
	}

	[[nodiscard]] consteval auto operator""_u16l(unsigned long long int n) noexcept {
		return static_cast<std::uint_least16_t>(n);
	}

	[[nodiscard]] consteval auto operator""_u16l(long double n) noexcept {
		return static_cast<std::uint_least16_t>(n);
	}

	[[nodiscard]] consteval auto operator""_i16l(unsigned long long int n) noexcept {
		return static_cast<std::int_least16_t>(n);
	}

	[[nodiscard]] consteval auto operator""_i16l(long double n) noexcept {
		return static_cast<std::int_least16_t>(n);
	}

#	if XIEITE_FEAT_I32
	[[nodiscard]] consteval auto operator""_u32(unsigned long long int n) noexcept {
		return static_cast<std::uint32_t>(n);
	}

	[[nodiscard]] consteval auto operator""_u32(long double n) noexcept {
		return static_cast<std::uint32_t>(n);
	}

	[[nodiscard]] consteval auto operator""_i32(unsigned long long int n) noexcept {
		return static_cast<std::int32_t>(n);
	}

	[[nodiscard]] consteval auto operator""_i32(long double n) noexcept {
		return static_cast<std::int32_t>(n);
	}
#	endif

	[[nodiscard]] consteval auto operator""_u32f(unsigned long long int n) noexcept {
		return static_cast<std::uint_fast32_t>(n);
	}

	[[nodiscard]] consteval auto operator""_u32f(long double n) noexcept {
		return static_cast<std::uint_fast32_t>(n);
	}

	[[nodiscard]] consteval auto operator""_i32f(unsigned long long int n) noexcept {
		return static_cast<std::int_fast32_t>(n);
	}

	[[nodiscard]] consteval auto operator""_i32f(long double n) noexcept {
		return static_cast<std::int_fast32_t>(n);
	}

	[[nodiscard]] consteval auto operator""_u32l(unsigned long long int n) noexcept {
		return static_cast<std::uint_least32_t>(n);
	}

	[[nodiscard]] consteval auto operator""_u32l(long double n) noexcept {
		return static_cast<std::uint_least32_t>(n);
	}

	[[nodiscard]] consteval auto operator""_i32l(unsigned long long int n) noexcept {
		return static_cast<std::int_least32_t>(n);
	}

	[[nodiscard]] consteval auto operator""_i32l(long double n) noexcept {
		return static_cast<std::int_least32_t>(n);
	}

#	if XIEITE_FEAT_I64
	[[nodiscard]] consteval auto operator""_u64(unsigned long long int n) noexcept {
		return static_cast<std::uint64_t>(n);
	}

	[[nodiscard]] consteval auto operator""_u64(long double n) noexcept {
		return static_cast<std::uint64_t>(n);
	}

	[[nodiscard]] consteval auto operator""_i64(unsigned long long int n) noexcept {
		return static_cast<std::int64_t>(n);
	}

	[[nodiscard]] consteval auto operator""_i64(long double n) noexcept {
		return static_cast<std::int64_t>(n);
	}
#	endif

	[[nodiscard]] consteval auto operator""_u64f(unsigned long long int n) noexcept {
		return static_cast<std::uint_fast64_t>(n);
	}

	[[nodiscard]] consteval auto operator""_u64f(long double n) noexcept {
		return static_cast<std::uint_fast64_t>(n);
	}

	[[nodiscard]] consteval auto operator""_i64f(unsigned long long int n) noexcept {
		return static_cast<std::int_fast64_t>(n);
	}

	[[nodiscard]] consteval auto operator""_i64f(long double n) noexcept {
		return static_cast<std::int_fast64_t>(n);
	}

	[[nodiscard]] consteval auto operator""_u64l(unsigned long long int n) noexcept {
		return static_cast<std::uint_least64_t>(n);
	}

	[[nodiscard]] consteval auto operator""_u64l(long double n) noexcept {
		return static_cast<std::uint_least64_t>(n);
	}

	[[nodiscard]] consteval auto operator""_i64l(unsigned long long int n) noexcept {
		return static_cast<std::int_least64_t>(n);
	}

	[[nodiscard]] consteval auto operator""_i64l(long double n) noexcept {
		return static_cast<std::int_least64_t>(n);
	}

#	if XIEITE_FEAT_I128
	[[nodiscard]] consteval auto operator""_u128(unsigned long long int n) noexcept {
		return static_cast<xieite::uint128_t>(n);
	}

	[[nodiscard]] consteval auto operator""_u128(long double n) noexcept {
		return static_cast<xieite::uint128_t>(n);
	}

	[[nodiscard]] consteval auto operator""_i128(unsigned long long int n) noexcept {
		return static_cast<xieite::int128_t>(n);
	}

	[[nodiscard]] consteval auto operator""_i128(long double n) noexcept {
		return static_cast<xieite::int128_t>(n);
	}
#	endif

	[[nodiscard]] consteval auto operator""_um(unsigned long long int n) noexcept {
		return static_cast<std::uintmax_t>(n);
	}

	[[nodiscard]] consteval auto operator""_um(long double n) noexcept {
		return static_cast<std::uintmax_t>(n);
	}

	[[nodiscard]] consteval auto operator""_im(unsigned long long int n) noexcept {
		return static_cast<std::intmax_t>(n);
	}

	[[nodiscard]] consteval auto operator""_im(long double n) noexcept {
		return static_cast<std::intmax_t>(n);
	}

	[[nodiscard]] consteval auto operator""_up(unsigned long long int n) noexcept {
		return static_cast<std::uintptr_t>(n);
	}

	[[nodiscard]] consteval auto operator""_up(long double n) noexcept {
		return static_cast<std::uintptr_t>(n);
	}

	[[nodiscard]] consteval auto operator""_ip(unsigned long long int n) noexcept {
		return static_cast<std::intptr_t>(n);
	}

	[[nodiscard]] consteval auto operator""_ip(long double n) noexcept {
		return static_cast<std::intptr_t>(n);
	}

	[[nodiscard]] consteval auto operator""_pd(unsigned long long int n) noexcept {
		return static_cast<std::ptrdiff_t>(n);
	}

	[[nodiscard]] consteval auto operator""_pd(long double n) noexcept {
		return static_cast<std::ptrdiff_t>(n);
	}

	[[nodiscard]] consteval auto operator""_uz(unsigned long long int n) noexcept {
		return static_cast<std::size_t>(n);
	}

	[[nodiscard]] consteval auto operator""_uz(long double n) noexcept {
		return static_cast<std::size_t>(n);
	}

	[[nodiscard]] consteval auto operator""_iz(unsigned long long int n) noexcept {
		return static_cast<xieite::ssize_t>(n);
	}

	[[nodiscard]] consteval auto operator""_iz(long double n) noexcept {
		return static_cast<xieite::ssize_t>(n);
	}

	[[nodiscard]] consteval auto operator""_f(unsigned long long int n) noexcept {
		return static_cast<float>(n);
	}

	[[nodiscard]] consteval auto operator""_f(long double n) noexcept {
		return static_cast<float>(n);
	}

	[[nodiscard]] consteval auto operator""_d(unsigned long long int n) noexcept {
		return static_cast<double>(n);
	}

	[[nodiscard]] consteval auto operator""_d(long double n) noexcept {
		return static_cast<double>(n);
	}

	[[nodiscard]] consteval auto operator""_dl(unsigned long long int n) noexcept {
		return static_cast<long double>(n);
	}

	[[nodiscard]] consteval auto operator""_dl(long double n) noexcept {
		return static_cast<long double>(n);
	}

#	if XIEITE_FEAT_F16
	[[nodiscard]] consteval auto operator""_f16(unsigned long long int n) noexcept {
		return static_cast<std::float16_t>(n);
	}

	[[nodiscard]] consteval auto operator""_f16(long double n) noexcept {
		return static_cast<std::float16_t>(n);
	}
#	endif
#
#	if XIEITE_FEAT_F32
	[[nodiscard]] consteval auto operator""_f32(unsigned long long int n) noexcept {
		return static_cast<std::float32_t>(n);
	}

	[[nodiscard]] consteval auto operator""_f32(long double n) noexcept {
		return static_cast<std::float32_t>(n);
	}
#	endif
#
#	if XIEITE_FEAT_F64
	[[nodiscard]] consteval auto operator""_f64(unsigned long long int n) noexcept {
		return static_cast<std::float64_t>(n);
	}

	[[nodiscard]] consteval auto operator""_f64(long double n) noexcept {
		return static_cast<std::float64_t>(n);
	}
#	endif
#
#	if XIEITE_FEAT_F128
	[[nodiscard]] consteval auto operator""_f128(unsigned long long int n) noexcept {
		return static_cast<std::float128_t>(n);
	}

	[[nodiscard]] consteval auto operator""_f128(long double n) noexcept {
		return static_cast<std::float128_t>(n);
	}
#	endif
#
#	if XIEITE_FEAT_FBRAIN
	[[nodiscard]] consteval auto operator""_fb(unsigned long long int n) noexcept {
		return static_cast<std::bfloat16_t>(n);
	}

	[[nodiscard]] consteval auto operator""_fb(long double n) noexcept {
		return static_cast<std::bfloat16_t>(n);
	}
#	endif
}

#endif
