#pragma once

#include <utility>
#include "../trait/is_enum.hpp"

namespace xieite::enum_op {
	template<xieite::is_enum T>
	[[nodiscard]] constexpr T operator+(T l) noexcept {
		return l;
	}

	template<xieite::is_enum T>
	[[nodiscard]] constexpr T operator+(T l, std::underlying_type_t<T> r) noexcept {
		return static_cast<T>(std::to_underlying(l) + r);
	}

	template<xieite::is_enum T>
	[[nodiscard]] constexpr T operator+(T l, T r) noexcept {
		return l + std::to_underlying(r);
	}

	template<xieite::is_enum T>
	constexpr T& operator+=(T& l, std::underlying_type_t<T> r) noexcept {
		return l = l + r;
	}

	template<xieite::is_enum T>
	constexpr T& operator+=(T& l, T r) noexcept {
		return l = l + r;
	}

	template<xieite::is_enum T>
	constexpr T& operator++(T& l) noexcept {
		return l += 1;
	}

	template<xieite::is_enum T>
	constexpr T operator++(T& l, int) noexcept {
		return std::exchange(l, l + 1);
	}

	template<xieite::is_enum T>
	[[nodiscard]] constexpr T operator-(T l) noexcept {
		return static_cast<T>(-std::to_underlying(l));
	}

	template<xieite::is_enum T>
	[[nodiscard]] constexpr T operator-(T l, std::underlying_type_t<T> r) noexcept {
		return static_cast<T>(std::to_underlying(l) - r);
	}

	template<xieite::is_enum T>
	[[nodiscard]] constexpr T operator-(T l, T r) noexcept {
		return l - std::to_underlying(r);
	}

	template<xieite::is_enum T>
	constexpr T& operator-=(T& l, std::underlying_type_t<T> r) noexcept {
		return l = l - r;
	}

	template<xieite::is_enum T>
	constexpr T& operator-=(T& l, T r) noexcept {
		return l = l - r;
	}

	template<xieite::is_enum T>
	constexpr T& operator--(T& l) noexcept {
		return l -= 1;
	}

	template<xieite::is_enum T>
	constexpr T operator--(T& l, int) noexcept {
		return std::exchange(l, l - 1);
	}

	template<xieite::is_enum T>
	[[nodiscard]] constexpr T operator*(T l, std::underlying_type_t<T> r) noexcept {
		return static_cast<T>(std::to_underlying(l) * r);
	}

	template<xieite::is_enum T>
	[[nodiscard]] constexpr T operator*(T l, T r) noexcept {
		return l * std::to_underlying(r);
	}

	template<xieite::is_enum T>
	constexpr T& operator*=(T& l, std::underlying_type_t<T> r) noexcept {
		return l = l * r;
	}

	template<xieite::is_enum T>
	constexpr T& operator*=(T& l, T r) noexcept {
		return l = l * r;
	}

	template<xieite::is_enum T>
	[[nodiscard]] constexpr T operator/(T l, std::underlying_type_t<T> r) noexcept {
		return static_cast<T>(std::to_underlying(l) / r);
	}

	template<xieite::is_enum T>
	[[nodiscard]] constexpr T operator/(T l, T r) noexcept {
		return l / std::to_underlying(r);
	}

	template<xieite::is_enum T>
	constexpr T& operator/=(T& l, std::underlying_type_t<T> r) noexcept {
		return l = l / r;
	}

	template<xieite::is_enum T>
	constexpr T& operator/=(T& l, T r) noexcept {
		return l = l / r;
	}

	template<xieite::is_enum T>
	[[nodiscard]] constexpr T operator%(T l, std::underlying_type_t<T> r) noexcept {
		return static_cast<T>(std::to_underlying(l) % r);
	}

	template<xieite::is_enum T>
	[[nodiscard]] constexpr T operator%(T l, T r) noexcept {
		return l % std::to_underlying(r);
	}

	template<xieite::is_enum T>
	constexpr T& operator%=(T& l, std::underlying_type_t<T> r) noexcept {
		return l = l % r;
	}

	template<xieite::is_enum T>
	constexpr T& operator%=(T& l, T r) noexcept {
		return l = l % r;
	}

	template<xieite::is_enum T>
	[[nodiscard]] constexpr T operator&(T l, std::underlying_type_t<T> r) noexcept {
		return static_cast<T>(std::to_underlying(l) & r);
	}

	template<xieite::is_enum T>
	[[nodiscard]] constexpr T operator&(T l, T r) noexcept {
		return l & std::to_underlying(r);
	}

	template<xieite::is_enum T>
	constexpr T& operator&=(T& l, std::underlying_type_t<T> r) noexcept {
		return l = l & r;
	}

	template<xieite::is_enum T>
	constexpr T& operator&=(T& l, T r) noexcept {
		return l = l & r;
	}

	template<xieite::is_enum T>
	[[nodiscard]] constexpr T operator|(T l, std::underlying_type_t<T> r) noexcept {
		return static_cast<T>(std::to_underlying(l) | r);
	}

	template<xieite::is_enum T>
	[[nodiscard]] constexpr T operator|(T l, T r) noexcept {
		return l | std::to_underlying(r);
	}

	template<xieite::is_enum T>
	constexpr T& operator|=(T& l, std::underlying_type_t<T> r) noexcept {
		return l = l | r;
	}

	template<xieite::is_enum T>
	constexpr T& operator|=(T& l, T r) noexcept {
		return l = l | r;
	}

	template<xieite::is_enum T>
	[[nodiscard]] constexpr T operator^(T l, std::underlying_type_t<T> r) noexcept {
		return static_cast<T>(std::to_underlying(l) ^ r);
	}

	template<xieite::is_enum T>
	[[nodiscard]] constexpr T operator^(T l, T r) noexcept {
		return l ^ std::to_underlying(r);
	}

	template<xieite::is_enum T>
	constexpr T& operator^=(T& l, std::underlying_type_t<T> r) noexcept {
		return l = l ^ r;
	}

	template<xieite::is_enum T>
	constexpr T& operator^=(T& l, T r) noexcept {
		return l = l ^ r;
	}

	template<xieite::is_enum T>
	[[nodiscard]] constexpr T operator<<(T l, std::underlying_type_t<T> r) noexcept {
		return static_cast<T>(std::to_underlying(l) << r);
	}

	template<xieite::is_enum T>
	[[nodiscard]] constexpr T operator<<(T l, T r) noexcept {
		return l << std::to_underlying(r);
	}

	template<xieite::is_enum T>
	constexpr T& operator<<=(T& l, std::underlying_type_t<T> r) noexcept {
		return l = l << r;
	}

	template<xieite::is_enum T>
	constexpr T& operator<<=(T& l, T r) noexcept {
		return l = l << r;
	}

	template<xieite::is_enum T>
	[[nodiscard]] constexpr T operator>>(T l, std::underlying_type_t<T> r) noexcept {
		return static_cast<T>(std::to_underlying(l) >> r);
	}

	template<xieite::is_enum T>
	[[nodiscard]] constexpr T operator>>(T l, T r) noexcept {
		return l >> std::to_underlying(r);
	}

	template<xieite::is_enum T>
	constexpr T& operator>>=(T& l, std::underlying_type_t<T> r) noexcept {
		return l = l >> r;
	}

	template<xieite::is_enum T>
	constexpr T& operator>>=(T& l, T r) noexcept {
		return l = l >> r;
	}

	template<xieite::is_enum T>
	[[nodiscard]] constexpr T operator~(T l) noexcept {
		return static_cast<T>(~std::to_underlying(l));
	}

	template<xieite::is_enum T>
	[[nodiscard]] constexpr bool operator!(T l) noexcept {
		return !std::to_underlying(l);
	}

	template<xieite::is_enum T>
	[[nodiscard]] constexpr bool operator&&(T l, std::underlying_type_t<T> r) noexcept {
		return std::to_underlying(l) && r;
	}

	template<xieite::is_enum T>
	[[nodiscard]] constexpr bool operator&&(T l, T r) noexcept {
		return l && std::to_underlying(r);
	}

	template<xieite::is_enum T>
	[[nodiscard]] constexpr bool operator||(T l, std::underlying_type_t<T> r) noexcept {
		return std::to_underlying(l) || r;
	}

	template<xieite::is_enum T>
	[[nodiscard]] constexpr bool operator||(T l, T r) noexcept {
		return l || std::to_underlying(r);
	}
}
