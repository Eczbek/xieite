export module xieite:point2d;

import std;
import :is_arith;
import :almost_eq;
import :pi;
import :tau;

export namespace xieite {
	template<xieite::is_arith>
	struct line2d;

	template<xieite::is_arith>
	struct ray2d;

	template<xieite::is_arith>
	struct segm2d;

	template<xieite::is_arith>
	struct poly2d;

	template<xieite::is_arith T = double>
	struct point2d {
		T x;
		T y;

		constexpr point2d() noexcept
		: x(0), y(0) {}

		constexpr point2d(T x, T y) noexcept
		: x(x), y(y) {}

		template<typename U>
		[[nodiscard]] explicit(false) constexpr operator xieite::point2d<U>() const noexcept {
			return xieite::point2d<U>(static_cast<U>(this->x), static_cast<U>(this->y));
		}

		[[nodiscard]] friend constexpr bool operator==(xieite::point2d<T> left, xieite::point2d<T> right) noexcept {
			return xieite::almost_eq(left.x, right.x) && xieite::almost_eq(left.y, right.y);
		}

		[[nodiscard]] constexpr std::common_type_t<T, double> angle_to(xieite::point2d<T> point) const noexcept {
			return std::fmod(std::atan2(this->y - point.y, this->x - point.x) + xieite::pi<std::common_type_t<T, double>>, xieite::tau<T>);
		}

		[[nodiscard]] constexpr std::common_type_t<T, double> distance_to(xieite::point2d<T> point) const noexcept {
			return std::hypot(this->x - point.x, this->y - point.y);
		}

		[[nodiscard]] constexpr std::common_type_t<T, double> slope_to(xieite::point2d<T> point) const noexcept {
			using Result = std::common_type_t<T, double>;
			return xieite::almost_eq(this->x, point.x)
				? std::numeric_limits<Result>::infinity()
				: (static_cast<Result>(point.y - this->y) / static_cast<Result>(point.x - this->x));
		}

		[[nodiscard]] constexpr bool contains(xieite::point2d<T> point) const noexcept {
			return *this == point;
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
			for (xieite::point2d<T> point : poly) {
				if (*this != point) {
					return false;
				}
			}
			return true;
		}
	};
}
