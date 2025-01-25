#pragma once

#include <cmath>
#include <limits>
#include <type_traits>
#include "../math/almost_eq.hpp"
#include "../math/pi.hpp"
#include "../math/tau.hpp"
#include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith>
	struct line2d;

	template<xieite::is_arith>
	struct ray2d;

	template<xieite::is_arith>
	struct segm2d;

	template<xieite::is_arith>
	struct poly2d;

	template<xieite::is_arith T = double>
	struct pt2d {
		T x = 0;
		T y = 0;

		[[nodiscard]] pt2d() = default;

		[[nodiscard]] constexpr pt2d(T x, T y) noexcept
		: x(x), y(y) {}

		template<typename U>
		[[nodiscard]] constexpr operator xieite::pt2d<U>() const noexcept {
			return xieite::pt2d<U>(static_cast<U>(this->x), static_cast<U>(this->y));
		}

		[[nodiscard]] friend constexpr bool operator==(xieite::pt2d<T> left, xieite::pt2d<T> right) noexcept {
			return xieite::almost_eq(left.x, right.x) && xieite::almost_eq(left.y, right.y);
		}

		[[nodiscard]] constexpr std::common_type_t<T, double> angle_to(xieite::pt2d<T> pt) const noexcept {
			return std::fmod(std::atan2(this->y - pt.y, this->x - pt.x) + xieite::pi<std::common_type_t<T, double>>, xieite::tau<T>);
		}

		[[nodiscard]] constexpr std::common_type_t<T, double> dist_to(xieite::pt2d<T> pt) const noexcept {
			return std::hypot(this->x - pt.x, this->y - pt.y);
		}

		[[nodiscard]] constexpr std::common_type_t<T, double> slope_to(xieite::pt2d<T> pt) const noexcept {
			using Result = std::common_type_t<T, double>;
			return xieite::almost_eq(this->x, pt.x)
				? std::numeric_limits<Result>::infinity()
				: (static_cast<Result>(pt.y - this->y) / static_cast<Result>(pt.x - this->x));
		}

		[[nodiscard]] constexpr bool contains(xieite::pt2d<T> pt) const noexcept {
			return *this == pt;
		}

		[[nodiscard]] constexpr bool contains(const xieite::line2d<T>&) const noexcept {
			return false;
		}

		[[nodiscard]] constexpr bool contains(const xieite::ray2d<T>&) const noexcept {
			return false;
		}

		[[nodiscard]] constexpr bool contains(const xieite::segm2d<T>& segm) const noexcept {
			return (*this == segm.start) && (*this == segm.end);
		}

		[[nodiscard]] constexpr bool contains(const xieite::poly2d<T>& poly) const noexcept {
			for (xieite::pt2d<T> pt : poly.pts) {
				if (*this != pt) {
					return false;
				}
			}
			return true;
		}
	};
}
