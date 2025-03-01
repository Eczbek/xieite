#pragma once

#include <cmath>
#include <limits>
#include <type_traits>
#include "../math/pt2d.hpp"
#include "../math/almosteq.hpp"
#include "../trait/isarith.hpp"

namespace x4 {
	template<x4::isarith>
	struct line2d;

	template<x4::isarith>
	struct segm2d;

	template<x4::isarith>
	struct poly2d;

	template<x4::isarith T = double>
	struct ray2d {
		x4::pt2d<T> a;
		x4::pt2d<T> b;

		[[nodiscard]] ray2d() = default;

		[[nodiscard]] constexpr ray2d(x4::pt2d<T> a, x4::pt2d<T> b) noexcept
		: a(a), b(b) {}

		[[nodiscard]] constexpr ray2d(x4::pt2d<T> a, std::common_type_t<T, double> angle) noexcept
		: a(a), b(std::cos(angle), std::sin(angle)) {}

		template<typename U>
		[[nodiscard]] explicit constexpr operator x4::ray2d<U>() const noexcept {
			return x4::ray2d<U>(static_cast<U>(this->a), static_cast<U>(this->b));
		}

		[[nodiscard]] friend constexpr bool operator==(const x4::ray2d<T>& l, const x4::ray2d<T>& r) noexcept {
			return (l.a == r.a) && x4::almosteq(l.angle(), r.angle());
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
			return x4::almosteq((this->b.x - this->a.x) * (pt.y - this->a.y), (this->b.y - this->a.y) * (pt.x - this->a.x)) && ((this->a.x <= this->b.x) == (this->a.x <= pt.x)) && ((this->a.y <= this->b.y) == (this->a.y <= pt.y));
		}

		[[nodiscard]] constexpr bool contains(const x4::line2d<T>&) const noexcept {
			return false;
		}

		[[nodiscard]] constexpr bool contains(const x4::ray2d<T>& ray) const noexcept {
			return this->contains(ray.a) && x4::almosteq(this->angle(), ray.angle());
		}

		[[nodiscard]] constexpr bool contains(const x4::segm2d<T>& segm) const noexcept {
			return this->contains(segm.a) && this->contains(segm.b);
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
