export module xieite:ray2d;

import std;
import :is_arith;
import :point2d;
import :almost_eq;

export namespace xieite {
	template<xieite::is_arith>
	struct line2d;

	template<xieite::is_arith>
	struct segm2d;

	template<xieite::is_arith>
	struct poly2d;

	template<xieite::is_arith T = double>
	struct ray2d {
		xieite::point2d<T> start;
		xieite::point2d<T> end;

		constexpr ray2d(xieite::point2d<T> start, xieite::point2d<T> end) noexcept
		: start(start), end(end) {}

		constexpr ray2d(xieite::point2d<T> start, std::common_type_t<T, double> angle) noexcept
		: start(start), end(std::cos(angle), std::sin(angle)) {}

		template<typename U>
		[[nodiscard]] explicit(false) constexpr operator xieite::ray2d<U>() const noexcept {
			return xieite::ray2d<U>(this->start, this->end);
		}

		[[nodiscard]] friend constexpr bool operator==(const xieite::ray2d<T>& left, const xieite::ray2d<T>& right) noexcept {
			return (left.start == right.start) && xieite::almost_eq(left.angle(), right.angle());
		}

		[[nodiscard]] constexpr std::common_type_t<T, double> angle() const noexcept {
			return this->start.angle_to(this->end);
		}

		[[nodiscard]] constexpr std::common_type_t<T, double> length() const noexcept {
			return std::numeric_limits<std::common_type_t<T, double>>::infinity();
		}

		[[nodiscard]] constexpr std::common_type_t<T, double> slope() const noexcept {
			return this->start.slope_to(this->end);
		}

		[[nodiscard]] constexpr bool contains(xieite::point2d<T> point) const noexcept {
			return xieite::almost_eq((this->end.x - this->start.x) * (point.y - this->start.y), (this->end.y - this->start.y) * (point.x - this->start.x)) && ((this->start.x <= this->end.x) == (this->start.x <= point.x)) && ((this->start.y <= this->end.y) == (this->start.y <= point.y));
		}

		[[nodiscard]] constexpr bool contains(const xieite::line2d<T>&) const noexcept {
			return false;
		}

		[[nodiscard]] constexpr bool contains(const xieite::ray2d<T>& ray) const noexcept {
			return this->contains(ray.start) && xieite::almost_eq(this->angle(), ray.angle());
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
