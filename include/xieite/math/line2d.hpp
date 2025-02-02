#pragma once

#include <cmath>
#include <type_traits>
#include "../math/pt2d.hpp"
#include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith>
	struct poly2d;

	template<xieite::is_arith>
	struct ray2d;

	template<xieite::is_arith>
	struct segm2d;

	template<xieite::is_arith T = double>
	struct line2d {
		xieite::pt2d<T> a;
		xieite::pt2d<T> b;

		line2d() = default;

		[[nodiscard]] constexpr line2d(xieite::pt2d<T> a, xieite::pt2d<T> b) noexcept
		: a(a), b(b) {}

		[[nodiscard]] constexpr line2d(xieite::pt2d<T> a, std::common_type_t<T, double> angle) noexcept
		: a(a), b(std::cos(angle), std::sin(angle)) {}

		template<typename U>
		[[nodiscard]] constexpr operator xieite::line2d<U>() const noexcept {
			return xieite::line2d<U>(this->a, this->b);
		}

		[[nodiscard]] friend constexpr bool operator==(const xieite::line2d<T>& l, const xieite::line2d<T>& r) noexcept {
			return l.contains(r.a) && l.contains(r.b);
		}

		[[nodiscard]] constexpr std::common_type_t<T, double> angle() const noexcept {
			return this->a.angle_to(this->b);
		}

		[[nodiscard]] constexpr std::common_type_t<T, double> len() const noexcept {
			return std::numeric_limits<std::common_type_t<T, double>>::infinity();
		}

		[[nodiscard]] constexpr std::common_type_t<T, double> slope() const noexcept {
			return this->a.slope_to(this->b);
		}

		[[nodiscard]] constexpr bool contains(xieite::pt2d<T> pt) const noexcept {
			return xieite::almost_eq(
				(this->b.x - this->a.x) * (pt.y - this->a.y),
				(this->b.y - this->a.y) * (pt.x - this->a.x)
			);
		}

		[[nodiscard]] constexpr bool contains(const xieite::line2d<T>& line) const noexcept {
			return *this == line;
		}

		[[nodiscard]] constexpr bool contains(const xieite::ray2d<T>& ray) const noexcept {
			return *this == xieite::line2d<T>(ray.a, ray.b);
		}

		[[nodiscard]] constexpr bool contains(const xieite::segm2d<T>& segm) const noexcept {
			return *this == xieite::line2d<T>(segm.a, segm.b);
		}

		[[nodiscard]] constexpr bool contains(const xieite::poly2d<T>& poly) const noexcept {
			for (xieite::pt2d<T> pt : poly.pts) {
				if (!this->contains(pt)) {
					return false;
				}
			}
			return true;
		}
	};
}
