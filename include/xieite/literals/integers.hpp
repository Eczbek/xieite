#ifndef XIEITE_HEADER__LITERALS__INTEGERS
#	define XIEITE_HEADER__LITERALS__INTEGERS

#	include <cstdint>

namespace xieite::literals {
	constexpr int operator""_i(const unsigned long long int value) noexcept {
		return static_cast<int>(value);
	}

	constexpr bool operator""_b(const unsigned long long int value) noexcept {
		return static_cast<bool>(value);
	}

	constexpr std::int8_t operator""_i8(const unsigned long long int value) noexcept {
		return static_cast<std::int8_t>(value);
	}

	constexpr std::int16_t operator""_i16(const unsigned long long int value) noexcept {
		return static_cast<std::int16_t>(value);
	}

	constexpr std::int32_t operator""_i32(const unsigned long long int value) noexcept {
		return static_cast<std::int32_t>(value);
	}

	constexpr std::int64_t operator""_i64(const unsigned long long int value) noexcept {
		return static_cast<std::int64_t>(value);
	}

	constexpr std::intmax_t operator""_imax(const unsigned long long int value) noexcept {
		return static_cast<std::intmax_t>(value);
	}

	constexpr std::intptr_t operator""_iptr(const unsigned long long int value) noexcept {
		return static_cast<std::intptr_t>(value);
	}

	constexpr std::uint8_t operator""_u8(const unsigned long long int value) noexcept {
		return static_cast<std::uint8_t>(value);
	}

	constexpr std::uint16_t operator""_u16(const unsigned long long int value) noexcept {
		return static_cast<std::uint16_t>(value);
	}

	constexpr std::uint32_t operator""_u32(const unsigned long long int value) noexcept {
		return static_cast<std::uint32_t>(value);
	}

	constexpr std::uint64_t operator""_u64(const unsigned long long int value) noexcept {
		return static_cast<std::uint64_t>(value);
	}

	constexpr std::uintmax_t operator""_umax(const unsigned long long int value) noexcept {
		return static_cast<std::uintmax_t>(value);
	}

	constexpr std::uintptr_t operator""_uptr(const unsigned long long int value) noexcept {
		return static_cast<std::uintptr_t>(value);
	}
}

#endif
