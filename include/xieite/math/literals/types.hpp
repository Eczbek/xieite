#ifndef XIEITE_HEADER_MATH_LITERALS_TYPES
#	define XIEITE_HEADER_MATH_LITERALS_TYPES

#	include <cstddef>
#	include <cstdint>

namespace xieite::math::literals::types {
	[[nodiscard]] constexpr std::int8_t operator""_i8(const unsigned long long int value) noexcept {
		return static_cast<std::int8_t>(value);
	}

	[[nodiscard]] constexpr std::int8_t operator""_i8(const long double value) noexcept {
		return static_cast<std::int8_t>(value);
	}

	[[nodiscard]] constexpr std::uint8_t operator""_u8(const unsigned long long int value) noexcept {
		return static_cast<std::uint8_t>(value);
	}

	[[nodiscard]] constexpr std::uint8_t operator""_u8(const long double value) noexcept {
		return static_cast<std::uint8_t>(value);
	}

	[[nodiscard]] constexpr std::int_fast8_t operator""_i8f(const unsigned long long int value) noexcept {
		return static_cast<std::int_fast8_t>(value);
	}

	[[nodiscard]] constexpr std::int_fast8_t operator""_i8f(const long double value) noexcept {
		return static_cast<std::int_fast8_t>(value);
	}

	[[nodiscard]] constexpr std::uint_fast8_t operator""_u8f(const unsigned long long int value) noexcept {
		return static_cast<std::uint_fast8_t>(value);
	}

	[[nodiscard]] constexpr std::uint_fast8_t operator""_u8f(const long double value) noexcept {
		return static_cast<std::uint_fast8_t>(value);
	}

	[[nodiscard]] constexpr std::int_least8_t operator""_i8l(const unsigned long long int value) noexcept {
		return static_cast<std::int_least8_t>(value);
	}

	[[nodiscard]] constexpr std::int_least8_t operator""_i8l(const long double value) noexcept {
		return static_cast<std::int_least8_t>(value);
	}

	[[nodiscard]] constexpr std::uint_least8_t operator""_u8l(const unsigned long long int value) noexcept {
		return static_cast<std::uint_least8_t>(value);
	}

	[[nodiscard]] constexpr std::uint_least8_t operator""_u8l(const long double value) noexcept {
		return static_cast<std::uint_least8_t>(value);
	}

	[[nodiscard]] constexpr std::int16_t operator""_i16(const unsigned long long int value) noexcept {
		return static_cast<std::int16_t>(value);
	}

	[[nodiscard]] constexpr std::int16_t operator""_i16(const long double value) noexcept {
		return static_cast<std::int16_t>(value);
	}

	[[nodiscard]] constexpr std::uint16_t operator""_u16(const unsigned long long int value) noexcept {
		return static_cast<std::uint16_t>(value);
	}

	[[nodiscard]] constexpr std::uint16_t operator""_u16(const long double value) noexcept {
		return static_cast<std::uint16_t>(value);
	}

	[[nodiscard]] constexpr std::int_fast16_t operator""_i16f(const unsigned long long int value) noexcept {
		return static_cast<std::int_fast16_t>(value);
	}

	[[nodiscard]] constexpr std::int_fast16_t operator""_i16f(const long double value) noexcept {
		return static_cast<std::int_fast16_t>(value);
	}

	[[nodiscard]] constexpr std::uint_fast16_t operator""_u16f(const unsigned long long int value) noexcept {
		return static_cast<std::uint_fast16_t>(value);
	}

	[[nodiscard]] constexpr std::uint_fast16_t operator""_u16f(const long double value) noexcept {
		return static_cast<std::uint_fast16_t>(value);
	}

	[[nodiscard]] constexpr std::int_least16_t operator""_i16l(const unsigned long long int value) noexcept {
		return static_cast<std::int_least16_t>(value);
	}

	[[nodiscard]] constexpr std::int_least16_t operator""_i16l(const long double value) noexcept {
		return static_cast<std::int_least16_t>(value);
	}

	[[nodiscard]] constexpr std::uint_least16_t operator""_u16l(const unsigned long long int value) noexcept {
		return static_cast<std::uint_least16_t>(value);
	}

	[[nodiscard]] constexpr std::uint_least16_t operator""_u16l(const long double value) noexcept {
		return static_cast<std::uint_least16_t>(value);
	}

	[[nodiscard]] constexpr std::int32_t operator""_i32(const unsigned long long int value) noexcept {
		return static_cast<std::int32_t>(value);
	}

	[[nodiscard]] constexpr std::int32_t operator""_i32(const long double value) noexcept {
		return static_cast<std::int32_t>(value);
	}

	[[nodiscard]] constexpr std::uint32_t operator""_u32(const unsigned long long int value) noexcept {
		return static_cast<std::uint32_t>(value);
	}

	[[nodiscard]] constexpr std::uint32_t operator""_u32(const long double value) noexcept {
		return static_cast<std::uint32_t>(value);
	}

	[[nodiscard]] constexpr std::int_fast32_t operator""_i32f(const unsigned long long int value) noexcept {
		return static_cast<std::int_fast32_t>(value);
	}

	[[nodiscard]] constexpr std::int_fast32_t operator""_i32f(const long double value) noexcept {
		return static_cast<std::int_fast32_t>(value);
	}

	[[nodiscard]] constexpr std::uint_fast32_t operator""_u32f(const unsigned long long int value) noexcept {
		return static_cast<std::uint_fast32_t>(value);
	}

	[[nodiscard]] constexpr std::uint_fast32_t operator""_u32f(const long double value) noexcept {
		return static_cast<std::uint_fast32_t>(value);
	}

	[[nodiscard]] constexpr std::int_least32_t operator""_i32l(const unsigned long long int value) noexcept {
		return static_cast<std::int_least32_t>(value);
	}

	[[nodiscard]] constexpr std::int_least32_t operator""_i32l(const long double value) noexcept {
		return static_cast<std::int_least32_t>(value);
	}

	[[nodiscard]] constexpr std::uint_least32_t operator""_u32l(const unsigned long long int value) noexcept {
		return static_cast<std::uint_least32_t>(value);
	}

	[[nodiscard]] constexpr std::uint_least32_t operator""_u32l(const long double value) noexcept {
		return static_cast<std::uint_least32_t>(value);
	}

	[[nodiscard]] constexpr std::int64_t operator""_i64(const unsigned long long int value) noexcept {
		return static_cast<std::int64_t>(value);
	}

	[[nodiscard]] constexpr std::int64_t operator""_i64(const long double value) noexcept {
		return static_cast<std::int64_t>(value);
	}

	[[nodiscard]] constexpr std::uint64_t operator""_u64(const unsigned long long int value) noexcept {
		return static_cast<std::uint64_t>(value);
	}

	[[nodiscard]] constexpr std::uint64_t operator""_u64(const long double value) noexcept {
		return static_cast<std::uint64_t>(value);
	}

	[[nodiscard]] constexpr std::int_fast64_t operator""_i64f(const unsigned long long int value) noexcept {
		return static_cast<std::int_fast64_t>(value);
	}

	[[nodiscard]] constexpr std::int_fast64_t operator""_i64f(const long double value) noexcept {
		return static_cast<std::int_fast64_t>(value);
	}

	[[nodiscard]] constexpr std::uint_fast64_t operator""_u64f(const unsigned long long int value) noexcept {
		return static_cast<std::uint_fast64_t>(value);
	}

	[[nodiscard]] constexpr std::uint_fast64_t operator""_u64f(const long double value) noexcept {
		return static_cast<std::uint_fast64_t>(value);
	}

	[[nodiscard]] constexpr std::int_least64_t operator""_i64l(const unsigned long long int value) noexcept {
		return static_cast<std::int_least64_t>(value);
	}

	[[nodiscard]] constexpr std::int_least64_t operator""_i64l(const long double value) noexcept {
		return static_cast<std::int_least64_t>(value);
	}

	[[nodiscard]] constexpr std::uint_least64_t operator""_u64l(const unsigned long long int value) noexcept {
		return static_cast<std::uint_least64_t>(value);
	}

	[[nodiscard]] constexpr std::uint_least64_t operator""_u64l(const long double value) noexcept {
		return static_cast<std::uint_least64_t>(value);
	}

	[[nodiscard]] constexpr std::intmax_t operator""_imax(const unsigned long long int value) noexcept {
		return static_cast<std::intmax_t>(value);
	}

	[[nodiscard]] constexpr std::intmax_t operator""_imax(const long double value) noexcept {
		return static_cast<std::intmax_t>(value);
	}

	[[nodiscard]] constexpr std::uintmax_t operator""_umax(const unsigned long long int value) noexcept {
		return static_cast<std::uintmax_t>(value);
	}

	[[nodiscard]] constexpr std::uintmax_t operator""_umax(const long double value) noexcept {
		return static_cast<std::uintmax_t>(value);
	}

	[[nodiscard]] constexpr std::max_align_t operator""_amax(const unsigned long long int value) noexcept {
		return static_cast<std::max_align_t>(value);
	}

	[[nodiscard]] constexpr std::max_align_t operator""_amax(const long double value) noexcept {
		return static_cast<std::max_align_t>(value);
	}

	[[nodiscard]] constexpr std::intptr_t operator""_iptr(const unsigned long long int value) noexcept {
		return static_cast<std::intptr_t>(value);
	}

	[[nodiscard]] constexpr std::intptr_t operator""_iptr(const long double value) noexcept {
		return static_cast<std::intptr_t>(value);
	}

	[[nodiscard]] constexpr std::uintptr_t operator""_uptr(const unsigned long long int value) noexcept {
		return static_cast<std::uintptr_t>(value);
	}

	[[nodiscard]] constexpr std::uintptr_t operator""_uptr(const long double value) noexcept {
		return static_cast<std::uintptr_t>(value);
	}

	[[nodiscard]] constexpr std::ptrdiff_t operator""_dptr(const unsigned long long int value) noexcept {
		return static_cast<std::ptrdiff_t>(value);
	}

	[[nodiscard]] constexpr std::ptrdiff_t operator""_dptr(const long double value) noexcept {
		return static_cast<std::ptrdiff_t>(value);
	}
}

#endif
