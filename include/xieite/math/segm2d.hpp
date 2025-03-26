#ifndef DETAIL_XIEITE_HEADER_MATH_SEGM2D
#	define DETAIL_XIEITE_HEADER_MATH_SEGM2D
#
#	include <type_traits>
#	include "../math/almost_eq.hpp"
#	include "../math/pt2d.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith>
	struct line2d;

	template<xieite::is_arith>
	struct ray2d;

	template<xieite::is_arith>
	struct poly2d;

	template<xieite::is_arith T = double>
	struct segm2d {
		xieite::pt2d<T> start;
		xieite::pt2d<T> end;

		[[nodiscard]] segm2d() = default;

		[[nodiscard]] constexpr segm2d(xieite::pt2d<T> start, xieite::pt2d<T> end) noexcept
		: start(start), end(end) {}

		template<typename U>
		[[nodiscard]] explicit constexpr operator xieite::segm2d<U>() const noexcept {
			return xieite::segm2d<U>(static_cast<U>(this->start), static_cast<U>(this->end));
		}

		[[nodiscard]] friend constexpr bool operator==(const xieite::segm2d<T>& l, const xieite::segm2d<T>& r) noexcept {
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

		[[nodiscard]] constexpr bool contains(xieite::pt2d<T> pt) const noexcept {
			return xieite::almost_eq(this->start.distance_to(pt) + this->end.distance_to(pt), this->len());
		}

		[[nodiscard]] constexpr bool contains(const xieite::line2d<T>&) const noexcept {
			return false;
		}

		[[nodiscard]] constexpr bool contains(const xieite::ray2d<T>&) const noexcept {
			return false;
		}

		[[nodiscard]] constexpr bool contains(const xieite::segm2d<T>& segm) const noexcept {
			return this->contains(segm.start) && this->contains(segm.end);
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

#endif
