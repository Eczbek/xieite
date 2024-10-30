export module xieite:segm2d;

import std;
import :is_arith;
import :point2d;
import :almost_eq;

export namespace xieite {
	template<xieite::is_arith>
	struct line2d;

	template<xieite::is_arith>
	struct ray2d;

	template<xieite::is_arith>
	struct poly2d;

	template<xieite::is_arith T = double>
	struct segm2d {
		xieite::point2d<T> start;
		xieite::point2d<T> end;

		constexpr segm2d(xieite::point2d<T> start, xieite::point2d<T> end) noexcept
		: start(start), end(end) {}

		template<typename U>
		[[nodiscard]] explicit(false) constexpr operator xieite::segm2d<U>() const noexcept {
			return xieite::segm2d<U>(this->start, this->end);
		}

		[[nodiscard]] friend constexpr bool operator==(const xieite::segm2d<T>& left, const xieite::segm2d<T>& right) noexcept {
			return ((left.start == right.start) && (left.end == right.end)) || ((left.start == right.end) && (left.end == right.start));
		}

		[[nodiscard]] constexpr std::common_type_t<T, double> angle() const noexcept {
			return this->start.angle_to(this->end);
		}

		[[nodiscard]] constexpr std::common_type_t<T, double> length() const noexcept {
			return this->start.distance_to(this->end);
		}

		[[nodiscard]] constexpr std::common_type_t<T, double> slope() const noexcept {
			return this->start.slope_to(this->end);
		}

		[[nodiscard]] constexpr bool contains(xieite::point2d<T> point) const noexcept {
			return xieite::almost_eq(this->start.distance_to(point) + this->end.distance_to(point), this->length());
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
			for (xieite::point2d<T> point : poly.points) {
				if (!this->contains(point)) {
					return false;
				}
			}
			return true;
		}
	};
}
