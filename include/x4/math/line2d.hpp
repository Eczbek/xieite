#pragma once

#include <cmath>
#include <type_traits>
#include "../math/pt2d.hpp"
#include "../trait/isarith.hpp"

namespace x4 {
	template<x4::isarith>
	struct poly2d;

	template<x4::isarith>
	struct ray2d;

	template<x4::isarith>
	struct segm2d;

	template<x4::isarith T = double>
	struct line2d {
		x4::pt2d<T> a;
		x4::pt2d<T> b;

		line2d() = default;

		[[nodiscard]] constexpr line2d(x4::pt2d<T> a, x4::pt2d<T> b) noexcept
		: a(a), b(b) {}

		[[nodiscard]] constexpr line2d(x4::pt2d<T> a, std::common_type_t<T, double> angle) noexcept
		: a(a), b(std::cos(angle), std::sin(angle)) {}

		template<typename U>
		[[nodiscard]] explicit constexpr operator x4::line2d<U>() const noexcept {
			return x4::line2d<U>(static_cast<U>(this->a), static_cast<U>(this->b));
		}

		[[nodiscard]] friend constexpr bool operator==(const x4::line2d<T>& l, const x4::line2d<T>& r) noexcept {
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

		[[nodiscard]] constexpr bool contains(x4::pt2d<T> pt) const noexcept {
			return x4::almost_eq(
				(this->b.x - this->a.x) * (pt.y - this->a.y),
				(this->b.y - this->a.y) * (pt.x - this->a.x)
			);
		}

		[[nodiscard]] constexpr bool contains(const x4::line2d<T>& line) const noexcept {
			return *this == line;
		}

		[[nodiscard]] constexpr bool contains(const x4::ray2d<T>& ray) const noexcept {
			return *this == x4::line2d<T>(ray.a, ray.b);
		}

		[[nodiscard]] constexpr bool contains(const x4::segm2d<T>& segm) const noexcept {
			return *this == x4::line2d<T>(segm.a, segm.b);
		}

		[[nodiscard]] constexpr bool contains(const x4::poly2d<T>& poly) const noexcept {
			for (x4::pt2d<T> pt : poly.pts) {
				if (!this->contains(pt)) {
					return false;
				}
			}
			return true;
		}
	};
}
