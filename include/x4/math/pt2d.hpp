#pragma once

#include <cmath>
#include <limits>
#include <type_traits>
#include "../math/almosteq.hpp"
#include "../math/pi.hpp"
#include "../math/tau.hpp"
#include "../trait/isarith.hpp"

namespace x4 {
	template<x4::isarith>
	struct line2d;

	template<x4::isarith>
	struct ray2d;

	template<x4::isarith>
	struct segm2d;

	template<x4::isarith>
	struct poly2d;

	template<x4::isarith T = double>
	struct pt2d {
		T x = 0;
		T y = 0;

		[[nodiscard]] pt2d() = default;

		[[nodiscard]] constexpr pt2d(T x, T y) noexcept
		: x(x), y(y) {}

		template<typename U>
		[[nodiscard]] explicit constexpr operator x4::pt2d<U>() const noexcept {
			return x4::pt2d<U>(static_cast<U>(this->x), static_cast<U>(this->y));
		}

		[[nodiscard]] friend constexpr bool operator==(x4::pt2d<T> l, x4::pt2d<T> r) noexcept {
			return x4::almosteq(l.x, r.x) && x4::almosteq(l.y, r.y);
		}

		[[nodiscard]] constexpr std::common_type_t<T, double> angle_to(x4::pt2d<T> pt) const noexcept {
			return std::fmod(std::atan2(this->y - pt.y, this->x - pt.x) + x4::pi<std::common_type_t<T, double>>, x4::tau<T>);
		}

		[[nodiscard]] constexpr std::common_type_t<T, double> dist_to(x4::pt2d<T> pt) const noexcept {
			return std::hypot(this->x - pt.x, this->y - pt.y);
		}

		[[nodiscard]] constexpr std::common_type_t<T, double> slope_to(x4::pt2d<T> pt) const noexcept {
			using Result = std::common_type_t<T, double>;
			return x4::almosteq(this->x, pt.x)
				? std::numeric_limits<Result>::infinity()
				: (static_cast<Result>(pt.y - this->y) / static_cast<Result>(pt.x - this->x));
		}

		[[nodiscard]] constexpr bool contains(x4::pt2d<T> pt) const noexcept {
			return *this == pt;
		}

		[[nodiscard]] constexpr bool contains(const x4::line2d<T>&) const noexcept {
			return false;
		}

		[[nodiscard]] constexpr bool contains(const x4::ray2d<T>&) const noexcept {
			return false;
		}

		[[nodiscard]] constexpr bool contains(const x4::segm2d<T>& segm) const noexcept {
			return (*this == segm.start) && (*this == segm.end);
		}

		[[nodiscard]] constexpr bool contains(const x4::poly2d<T>& poly) const noexcept {
			for (x4::pt2d<T> pt : poly.pts) {
				if (*this != pt) {
					return false;
				}
			}
			return true;
		}
	};
}
