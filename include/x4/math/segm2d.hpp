#pragma once

#include <type_traits>
#include "../math/almosteq.hpp"
#include "../math/pt2d.hpp"
#include "../trait/isarith.hpp"

namespace x4 {
	template<x4::isarith>
	struct line2d;

	template<x4::isarith>
	struct ray2d;

	template<x4::isarith>
	struct poly2d;

	template<x4::isarith T = double>
	struct segm2d {
		x4::pt2d<T> start;
		x4::pt2d<T> end;

		[[nodiscard]] segm2d() = default;

		[[nodiscard]] constexpr segm2d(x4::pt2d<T> start, x4::pt2d<T> end) noexcept
		: start(start), end(end) {}

		template<typename U>
		[[nodiscard]] explicit constexpr operator x4::segm2d<U>() const noexcept {
			return x4::segm2d<U>(static_cast<U>(this->start), static_cast<U>(this->end));
		}

		[[nodiscard]] friend constexpr bool operator==(const x4::segm2d<T>& l, const x4::segm2d<T>& r) noexcept {
			return ((l.start == r.start) && (l.end == r.end)) || ((l.start == r.end) && (l.end == r.start));
		}

		[[nodiscard]] constexpr std::common_type_t<T, double> angle() const noexcept {
			return this->start.angle_to(this->end);
		}

		[[nodiscard]] constexpr std::common_type_t<T, double> len() const noexcept {
			return this->start.distance_to(this->end);
		}

		[[nodiscard]] constexpr std::common_type_t<T, double> slope() const noexcept {
			return this->start.slope_to(this->end);
		}

		[[nodiscard]] constexpr bool contains(x4::pt2d<T> pt) const noexcept {
			return x4::almosteq(this->start.distance_to(pt) + this->end.distance_to(pt), this->len());
		}

		[[nodiscard]] constexpr bool contains(const x4::line2d<T>&) const noexcept {
			return false;
		}

		[[nodiscard]] constexpr bool contains(const x4::ray2d<T>&) const noexcept {
			return false;
		}

		[[nodiscard]] constexpr bool contains(const x4::segm2d<T>& segm) const noexcept {
			return this->contains(segm.start) && this->contains(segm.end);
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
