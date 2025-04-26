#ifndef DETAIL_XIEITE_HEADER_FN_ENUM_OP
#	define DETAIL_XIEITE_HEADER_FN_ENUM_OP
#
#	include <utility>
#	include "../trait/is_enum.hpp"

namespace xieite::enum_op {
	template<xieite::is_enum Enum>
	[[nodiscard]] constexpr Enum operator+(Enum lhs) noexcept {
		return lhs;
	}

	template<xieite::is_enum Enum>
	[[nodiscard]] constexpr Enum operator+(Enum lhs, std::underlying_type_t<Enum> rhs) noexcept {
		return static_cast<Enum>(std::to_underlying(lhs) + rhs);
	}

	template<xieite::is_enum Enum>
	[[nodiscard]] constexpr Enum operator+(Enum lhs, Enum rhs) noexcept {
		return lhs + std::to_underlying(rhs);
	}

	template<xieite::is_enum Enum>
	constexpr Enum& operator+=(Enum& lhs, std::underlying_type_t<Enum> rhs) noexcept {
		return lhs = lhs + rhs;
	}

	template<xieite::is_enum Enum>
	constexpr Enum& operator+=(Enum& lhs, Enum rhs) noexcept {
		return lhs = lhs + rhs;
	}

	template<xieite::is_enum Enum>
	constexpr Enum& operator++(Enum& lhs) noexcept {
		return lhs += 1;
	}

	template<xieite::is_enum Enum>
	constexpr Enum operator++(Enum& lhs, int) noexcept {
		return std::exchange(lhs, lhs + 1);
	}

	template<xieite::is_enum Enum>
	[[nodiscard]] constexpr Enum operator-(Enum lhs) noexcept {
		return static_cast<Enum>(-std::to_underlying(lhs));
	}

	template<xieite::is_enum Enum>
	[[nodiscard]] constexpr Enum operator-(Enum lhs, std::underlying_type_t<Enum> rhs) noexcept {
		return static_cast<Enum>(std::to_underlying(lhs) - rhs);
	}

	template<xieite::is_enum Enum>
	[[nodiscard]] constexpr Enum operator-(Enum lhs, Enum rhs) noexcept {
		return lhs - std::to_underlying(rhs);
	}

	template<xieite::is_enum Enum>
	constexpr Enum& operator-=(Enum& lhs, std::underlying_type_t<Enum> rhs) noexcept {
		return lhs = lhs - rhs;
	}

	template<xieite::is_enum Enum>
	constexpr Enum& operator-=(Enum& lhs, Enum rhs) noexcept {
		return lhs = lhs - rhs;
	}

	template<xieite::is_enum Enum>
	constexpr Enum& operator--(Enum& lhs) noexcept {
		return lhs -= 1;
	}

	template<xieite::is_enum Enum>
	constexpr Enum operator--(Enum& lhs, int) noexcept {
		return std::exchange(lhs, lhs - 1);
	}

	template<xieite::is_enum Enum>
	[[nodiscard]] constexpr Enum operator*(Enum lhs, std::underlying_type_t<Enum> rhs) noexcept {
		return static_cast<Enum>(std::to_underlying(lhs) * rhs);
	}

	template<xieite::is_enum Enum>
	[[nodiscard]] constexpr Enum operator*(Enum lhs, Enum rhs) noexcept {
		return lhs * std::to_underlying(rhs);
	}

	template<xieite::is_enum Enum>
	constexpr Enum& operator*=(Enum& lhs, std::underlying_type_t<Enum> rhs) noexcept {
		return lhs = lhs * rhs;
	}

	template<xieite::is_enum Enum>
	constexpr Enum& operator*=(Enum& lhs, Enum rhs) noexcept {
		return lhs = lhs * rhs;
	}

	template<xieite::is_enum Enum>
	[[nodiscard]] constexpr Enum operator/(Enum lhs, std::underlying_type_t<Enum> rhs) noexcept {
		return static_cast<Enum>(std::to_underlying(lhs) / rhs);
	}

	template<xieite::is_enum Enum>
	[[nodiscard]] constexpr Enum operator/(Enum lhs, Enum rhs) noexcept {
		return lhs / std::to_underlying(rhs);
	}

	template<xieite::is_enum Enum>
	constexpr Enum& operator/=(Enum& lhs, std::underlying_type_t<Enum> rhs) noexcept {
		return lhs = lhs / rhs;
	}

	template<xieite::is_enum Enum>
	constexpr Enum& operator/=(Enum& lhs, Enum rhs) noexcept {
		return lhs = lhs / rhs;
	}

	template<xieite::is_enum Enum>
	[[nodiscard]] constexpr Enum operator%(Enum lhs, std::underlying_type_t<Enum> rhs) noexcept {
		return static_cast<Enum>(std::to_underlying(lhs) % rhs);
	}

	template<xieite::is_enum Enum>
	[[nodiscard]] constexpr Enum operator%(Enum lhs, Enum rhs) noexcept {
		return lhs % std::to_underlying(rhs);
	}

	template<xieite::is_enum Enum>
	constexpr Enum& operator%=(Enum& lhs, std::underlying_type_t<Enum> rhs) noexcept {
		return lhs = lhs % rhs;
	}

	template<xieite::is_enum Enum>
	constexpr Enum& operator%=(Enum& lhs, Enum rhs) noexcept {
		return lhs = lhs % rhs;
	}

	template<xieite::is_enum Enum>
	[[nodiscard]] constexpr Enum operator&(Enum lhs, std::underlying_type_t<Enum> rhs) noexcept {
		return static_cast<Enum>(std::to_underlying(lhs) & rhs);
	}

	template<xieite::is_enum Enum>
	[[nodiscard]] constexpr Enum operator&(Enum lhs, Enum rhs) noexcept {
		return lhs & std::to_underlying(rhs);
	}

	template<xieite::is_enum Enum>
	constexpr Enum& operator&=(Enum& lhs, std::underlying_type_t<Enum> rhs) noexcept {
		return lhs = lhs & rhs;
	}

	template<xieite::is_enum Enum>
	constexpr Enum& operator&=(Enum& lhs, Enum rhs) noexcept {
		return lhs = lhs & rhs;
	}

	template<xieite::is_enum Enum>
	[[nodiscard]] constexpr Enum operator|(Enum lhs, std::underlying_type_t<Enum> rhs) noexcept {
		return static_cast<Enum>(std::to_underlying(lhs) | rhs);
	}

	template<xieite::is_enum Enum>
	[[nodiscard]] constexpr Enum operator|(Enum lhs, Enum rhs) noexcept {
		return lhs | std::to_underlying(rhs);
	}

	template<xieite::is_enum Enum>
	constexpr Enum& operator|=(Enum& lhs, std::underlying_type_t<Enum> rhs) noexcept {
		return lhs = lhs | rhs;
	}

	template<xieite::is_enum Enum>
	constexpr Enum& operator|=(Enum& lhs, Enum rhs) noexcept {
		return lhs = lhs | rhs;
	}

	template<xieite::is_enum Enum>
	[[nodiscard]] constexpr Enum operator^(Enum lhs, std::underlying_type_t<Enum> rhs) noexcept {
		return static_cast<Enum>(std::to_underlying(lhs) ^ rhs);
	}

	template<xieite::is_enum Enum>
	[[nodiscard]] constexpr Enum operator^(Enum lhs, Enum rhs) noexcept {
		return lhs ^ std::to_underlying(rhs);
	}

	template<xieite::is_enum Enum>
	constexpr Enum& operator^=(Enum& lhs, std::underlying_type_t<Enum> rhs) noexcept {
		return lhs = lhs ^ rhs;
	}

	template<xieite::is_enum Enum>
	constexpr Enum& operator^=(Enum& lhs, Enum rhs) noexcept {
		return lhs = lhs ^ rhs;
	}

	template<xieite::is_enum Enum>
	[[nodiscard]] constexpr Enum operator<<(Enum lhs, std::underlying_type_t<Enum> rhs) noexcept {
		return static_cast<Enum>(std::to_underlying(lhs) << rhs);
	}

	template<xieite::is_enum Enum>
	[[nodiscard]] constexpr Enum operator<<(Enum lhs, Enum rhs) noexcept {
		return lhs << std::to_underlying(rhs);
	}

	template<xieite::is_enum Enum>
	constexpr Enum& operator<<=(Enum& lhs, std::underlying_type_t<Enum> rhs) noexcept {
		return lhs = lhs << rhs;
	}

	template<xieite::is_enum Enum>
	constexpr Enum& operator<<=(Enum& lhs, Enum rhs) noexcept {
		return lhs = lhs << rhs;
	}

	template<xieite::is_enum Enum>
	[[nodiscard]] constexpr Enum operator>>(Enum lhs, std::underlying_type_t<Enum> rhs) noexcept {
		return static_cast<Enum>(std::to_underlying(lhs) >> rhs);
	}

	template<xieite::is_enum Enum>
	[[nodiscard]] constexpr Enum operator>>(Enum lhs, Enum rhs) noexcept {
		return lhs >> std::to_underlying(rhs);
	}

	template<xieite::is_enum Enum>
	constexpr Enum& operator>>=(Enum& lhs, std::underlying_type_t<Enum> rhs) noexcept {
		return lhs = lhs >> rhs;
	}

	template<xieite::is_enum Enum>
	constexpr Enum& operator>>=(Enum& lhs, Enum rhs) noexcept {
		return lhs = lhs >> rhs;
	}

	template<xieite::is_enum Enum>
	[[nodiscard]] constexpr Enum operator~(Enum lhs) noexcept {
		return static_cast<Enum>(~std::to_underlying(lhs));
	}

	template<xieite::is_enum Enum>
	[[nodiscard]] constexpr bool operator!(Enum lhs) noexcept {
		return !std::to_underlying(lhs);
	}

	template<xieite::is_enum Enum>
	[[nodiscard]] constexpr bool operator&&(Enum lhs, std::underlying_type_t<Enum> rhs) noexcept {
		return std::to_underlying(lhs) && rhs;
	}

	template<xieite::is_enum Enum>
	[[nodiscard]] constexpr bool operator&&(Enum lhs, Enum rhs) noexcept {
		return lhs && std::to_underlying(rhs);
	}

	template<xieite::is_enum Enum>
	[[nodiscard]] constexpr bool operator||(Enum lhs, std::underlying_type_t<Enum> rhs) noexcept {
		return std::to_underlying(lhs) || rhs;
	}

	template<xieite::is_enum Enum>
	[[nodiscard]] constexpr bool operator||(Enum lhs, Enum rhs) noexcept {
		return lhs || std::to_underlying(rhs);
	}
}

#endif
