#pragma once

#include <utility>
#include "../trait/isenum.hpp"

namespace x4::enumop {
	template<x4::isenum T>
	[[nodiscard]] constexpr T operator+(T l) noexcept {
		return l;
	}

	template<x4::isenum T>
	[[nodiscard]] constexpr T operator+(T l, std::underlying_type_t<T> r) noexcept {
		return static_cast<T>(std::to_underlying(l) + r);
	}

	template<x4::isenum T>
	[[nodiscard]] constexpr T operator+(T l, T r) noexcept {
		return l + std::to_underlying(r);
	}

	template<x4::isenum T>
	constexpr T& operator+=(T& l, std::underlying_type_t<T> r) noexcept {
		return l = l + r;
	}

	template<x4::isenum T>
	constexpr T& operator+=(T& l, T r) noexcept {
		return l = l + r;
	}

	template<x4::isenum T>
	constexpr T& operator++(T& l) noexcept {
		return l += 1;
	}

	template<x4::isenum T>
	constexpr T operator++(T& l, int) noexcept {
		return std::exchange(l, l + 1);
	}

	template<x4::isenum T>
	[[nodiscard]] constexpr T operator-(T l) noexcept {
		return static_cast<T>(-std::to_underlying(l));
	}

	template<x4::isenum T>
	[[nodiscard]] constexpr T operator-(T l, std::underlying_type_t<T> r) noexcept {
		return static_cast<T>(std::to_underlying(l) - r);
	}

	template<x4::isenum T>
	[[nodiscard]] constexpr T operator-(T l, T r) noexcept {
		return l - std::to_underlying(r);
	}

	template<x4::isenum T>
	constexpr T& operator-=(T& l, std::underlying_type_t<T> r) noexcept {
		return l = l - r;
	}

	template<x4::isenum T>
	constexpr T& operator-=(T& l, T r) noexcept {
		return l = l - r;
	}

	template<x4::isenum T>
	constexpr T& operator--(T& l) noexcept {
		return l -= 1;
	}

	template<x4::isenum T>
	constexpr T operator--(T& l, int) noexcept {
		return std::exchange(l, l - 1);
	}

	template<x4::isenum T>
	[[nodiscard]] constexpr T operator*(T l, std::underlying_type_t<T> r) noexcept {
		return static_cast<T>(std::to_underlying(l) * r);
	}

	template<x4::isenum T>
	[[nodiscard]] constexpr T operator*(T l, T r) noexcept {
		return l * std::to_underlying(r);
	}

	template<x4::isenum T>
	constexpr T& operator*=(T& l, std::underlying_type_t<T> r) noexcept {
		return l = l * r;
	}

	template<x4::isenum T>
	constexpr T& operator*=(T& l, T r) noexcept {
		return l = l * r;
	}

	template<x4::isenum T>
	[[nodiscard]] constexpr T operator/(T l, std::underlying_type_t<T> r) noexcept {
		return static_cast<T>(std::to_underlying(l) / r);
	}

	template<x4::isenum T>
	[[nodiscard]] constexpr T operator/(T l, T r) noexcept {
		return l / std::to_underlying(r);
	}

	template<x4::isenum T>
	constexpr T& operator/=(T& l, std::underlying_type_t<T> r) noexcept {
		return l = l / r;
	}

	template<x4::isenum T>
	constexpr T& operator/=(T& l, T r) noexcept {
		return l = l / r;
	}

	template<x4::isenum T>
	[[nodiscard]] constexpr T operator%(T l, std::underlying_type_t<T> r) noexcept {
		return static_cast<T>(std::to_underlying(l) % r);
	}

	template<x4::isenum T>
	[[nodiscard]] constexpr T operator%(T l, T r) noexcept {
		return l % std::to_underlying(r);
	}

	template<x4::isenum T>
	constexpr T& operator%=(T& l, std::underlying_type_t<T> r) noexcept {
		return l = l % r;
	}

	template<x4::isenum T>
	constexpr T& operator%=(T& l, T r) noexcept {
		return l = l % r;
	}

	template<x4::isenum T>
	[[nodiscard]] constexpr T operator&(T l, std::underlying_type_t<T> r) noexcept {
		return static_cast<T>(std::to_underlying(l) & r);
	}

	template<x4::isenum T>
	[[nodiscard]] constexpr T operator&(T l, T r) noexcept {
		return l & std::to_underlying(r);
	}

	template<x4::isenum T>
	constexpr T& operator&=(T& l, std::underlying_type_t<T> r) noexcept {
		return l = l & r;
	}

	template<x4::isenum T>
	constexpr T& operator&=(T& l, T r) noexcept {
		return l = l & r;
	}

	template<x4::isenum T>
	[[nodiscard]] constexpr T operator|(T l, std::underlying_type_t<T> r) noexcept {
		return static_cast<T>(std::to_underlying(l) | r);
	}

	template<x4::isenum T>
	[[nodiscard]] constexpr T operator|(T l, T r) noexcept {
		return l | std::to_underlying(r);
	}

	template<x4::isenum T>
	constexpr T& operator|=(T& l, std::underlying_type_t<T> r) noexcept {
		return l = l | r;
	}

	template<x4::isenum T>
	constexpr T& operator|=(T& l, T r) noexcept {
		return l = l | r;
	}

	template<x4::isenum T>
	[[nodiscard]] constexpr T operator^(T l, std::underlying_type_t<T> r) noexcept {
		return static_cast<T>(std::to_underlying(l) ^ r);
	}

	template<x4::isenum T>
	[[nodiscard]] constexpr T operator^(T l, T r) noexcept {
		return l ^ std::to_underlying(r);
	}

	template<x4::isenum T>
	constexpr T& operator^=(T& l, std::underlying_type_t<T> r) noexcept {
		return l = l ^ r;
	}

	template<x4::isenum T>
	constexpr T& operator^=(T& l, T r) noexcept {
		return l = l ^ r;
	}

	template<x4::isenum T>
	[[nodiscard]] constexpr T operator<<(T l, std::underlying_type_t<T> r) noexcept {
		return static_cast<T>(std::to_underlying(l) << r);
	}

	template<x4::isenum T>
	[[nodiscard]] constexpr T operator<<(T l, T r) noexcept {
		return l << std::to_underlying(r);
	}

	template<x4::isenum T>
	constexpr T& operator<<=(T& l, std::underlying_type_t<T> r) noexcept {
		return l = l << r;
	}

	template<x4::isenum T>
	constexpr T& operator<<=(T& l, T r) noexcept {
		return l = l << r;
	}

	template<x4::isenum T>
	[[nodiscard]] constexpr T operator>>(T l, std::underlying_type_t<T> r) noexcept {
		return static_cast<T>(std::to_underlying(l) >> r);
	}

	template<x4::isenum T>
	[[nodiscard]] constexpr T operator>>(T l, T r) noexcept {
		return l >> std::to_underlying(r);
	}

	template<x4::isenum T>
	constexpr T& operator>>=(T& l, std::underlying_type_t<T> r) noexcept {
		return l = l >> r;
	}

	template<x4::isenum T>
	constexpr T& operator>>=(T& l, T r) noexcept {
		return l = l >> r;
	}

	template<x4::isenum T>
	[[nodiscard]] constexpr T operator~(T l) noexcept {
		return static_cast<T>(~std::to_underlying(l));
	}

	template<x4::isenum T>
	[[nodiscard]] constexpr bool operator!(T l) noexcept {
		return !std::to_underlying(l);
	}

	template<x4::isenum T>
	[[nodiscard]] constexpr bool operator&&(T l, std::underlying_type_t<T> r) noexcept {
		return std::to_underlying(l) && r;
	}

	template<x4::isenum T>
	[[nodiscard]] constexpr bool operator&&(T l, T r) noexcept {
		return l && std::to_underlying(r);
	}

	template<x4::isenum T>
	[[nodiscard]] constexpr bool operator||(T l, std::underlying_type_t<T> r) noexcept {
		return std::to_underlying(l) || r;
	}

	template<x4::isenum T>
	[[nodiscard]] constexpr bool operator||(T l, T r) noexcept {
		return l || std::to_underlying(r);
	}
}
