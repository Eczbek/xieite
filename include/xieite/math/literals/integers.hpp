#ifndef XIEITE_HEADER__MATH__LITERALS__INTEGERS
#	define XIEITE_HEADER__MATH__LITERALS__INTEGERS

#	include <cstdint>

namespace xieite::math::literals {
	[[nodiscard]] constexpr int operator""_i(const unsigned long long int value) noexcept {
		return static_cast<int>(value);
	}

	[[nodiscard]] constexpr bool operator""_b(const unsigned long long int value) noexcept {
		return static_cast<bool>(value);
	}

	[[nodiscard]] constexpr std::int8_t operator""_i8(const unsigned long long int value) noexcept {
		return static_cast<std::int8_t>(value);
	}

	[[nodiscard]] constexpr std::int16_t operator""_i16(const unsigned long long int value) noexcept {
		return static_cast<std::int16_t>(value);
	}

	[[nodiscard]] constexpr std::int32_t operator""_i32(const unsigned long long int value) noexcept {
		return static_cast<std::int32_t>(value);
	}

	[[nodiscard]] constexpr std::int64_t operator""_i64(const unsigned long long int value) noexcept {
		return static_cast<std::int64_t>(value);
	}

	[[nodiscard]] constexpr std::intmax_t operator""_imax(const unsigned long long int value) noexcept {
		return static_cast<std::intmax_t>(value);
	}

	[[nodiscard]] constexpr std::intptr_t operator""_iptr(const unsigned long long int value) noexcept {
		return static_cast<std::intptr_t>(value);
	}

	[[nodiscard]] constexpr std::uint8_t operator""_u8(const unsigned long long int value) noexcept {
		return static_cast<std::uint8_t>(value);
	}

	[[nodiscard]] constexpr std::uint16_t operator""_u16(const unsigned long long int value) noexcept {
		return static_cast<std::uint16_t>(value);
	}

	[[nodiscard]] constexpr std::uint32_t operator""_u32(const unsigned long long int value) noexcept {
		return static_cast<std::uint32_t>(value);
	}

	[[nodiscard]] constexpr std::uint64_t operator""_u64(const unsigned long long int value) noexcept {
		return static_cast<std::uint64_t>(value);
	}

	[[nodiscard]] constexpr std::uintmax_t operator""_umax(const unsigned long long int value) noexcept {
		return static_cast<std::uintmax_t>(value);
	}

	[[nodiscard]] constexpr std::uintptr_t operator""_uptr(const unsigned long long int value) noexcept {
		return static_cast<std::uintptr_t>(value);
	}
}

#endif
