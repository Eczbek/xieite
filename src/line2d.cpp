export module xieite:line2d;

import std;
import :is_arith;
import :almost_eq;
import :point2d;

export namespace xieite {
	template<xieite::is_arith>
	struct poly2d;

	template<xieite::is_arith>
	struct ray2d;

	template<xieite::is_arith>
	struct segm2d;

	template<xieite::is_arith T = double>
	struct line2d {
		xieite::point2d<T> start;
		xieite::point2d<T> end;

		constexpr line2d(xieite::point2d<T> start, xieite::point2d<T> end) noexcept
		: start(start), end(end) {}

		constexpr line2d(xieite::point2d<T> start, std::common_type_t<T, double> angle) noexcept
		: start(start), end(std::cos(angle), std::sin(angle)) {}

		template<typename U>
		[[nodiscard]] explicit(false) constexpr operator xieite::line2d<U>() const noexcept {
			return xieite::line2d<U>(this->start, this->end);
		}

		[[nodiscard]] friend constexpr bool operator==(const xieite::line2d<T>& left, const xieite::line2d<T>& right) noexcept {
			return left.contains(right.start) && left.contains(right.end);
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
			return xieite::almost_eq(
				(this->end.x - this->start.x) * (point.y - this->start.y),
				(this->end.y - this->start.y) * (point.x - this->start.x)
			);
		}

		[[nodiscard]] constexpr bool contains(const xieite::line2d<T>& line) const noexcept {
			return *this == line;
		}

		[[nodiscard]] constexpr bool contains(const xieite::ray2d<T>& ray) const noexcept {
			return *this == xieite::line2d<T>(ray.start, ray.end);
		}

		[[nodiscard]] constexpr bool contains(const xieite::segm2d<T>& segm) const noexcept {
			return *this == xieite::line2d<T>(segm.start, segm.end);
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
