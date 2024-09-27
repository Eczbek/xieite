export module xieite:geometry.Point;

import std;
import :math.almostEqual;
import :math.pi;
import :math.tau;

export namespace xieite::geometry {
	template<xieite::concepts::Arithmetic>
	struct Line;

	template<xieite::concepts::Arithmetic>
	struct Ray;

	template<xieite::concepts::Arithmetic>
	struct Segment;

	template<xieite::concepts::Arithmetic>
	struct Polygon;

	template<xieite::concepts::Arithmetic Arithmetic = double>
	struct Point {
		Arithmetic x;
		Arithmetic y;

		constexpr Point() noexcept
		: Point(0, 0) {}

		constexpr Point(const Arithmetic x, const Arithmetic y) noexcept
		: x(x), y(y) {}

		template<typename OtherArithmetic>
		[[nodiscard]] explicit(false) constexpr operator Point<OtherArithmetic>() const noexcept {
			return Point<OtherArithmetic>(static_cast<OtherArithmetic>(this->x), static_cast<OtherArithmetic>(this->y));
		}

		[[nodiscard]] friend constexpr bool operator==(const Point left, const Point right) noexcept {
			return xieite::math::almostEqual(left.x, right.x) && xieite::math::almostEqual(left.y, right.y);
		}

		[[nodiscard]] constexpr std::conditional_t<std::floating_point<Arithmetic>, Arithmetic, double> angleTo(const Point point) const noexcept {
			return std::fmod(std::atan2(this->y - point.y, this->x - point.x) + xieite::math::pi<std::conditional_t<std::floating_point<Arithmetic>, Arithmetic, double>>, xieite::math::tau<Arithmetic>);
		}

		[[nodiscard]] constexpr std::conditional_t<std::floating_point<Arithmetic>, Arithmetic, double> distanceTo(const Point point) const noexcept {
			return std::hypot(this->x - point.x, this->y - point.y);
		}

		[[nodiscard]] constexpr std::conditional_t<std::floating_point<Arithmetic>, Arithmetic, double> slopeTo(const Point point) const noexcept {
			using Result = std::conditional_t<std::floating_point<Arithmetic>, Arithmetic, double>;
			return xieite::math::almostEqual(this->x, point.x) ? std::numeric_limits<Result>::infinity() : (static_cast<Result>(point.y - this->y) / static_cast<Result>(point.x - this->x));
		}

		[[nodiscard]] constexpr bool contains(const Point point) const noexcept {
			return *this == point;
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Line<Arithmetic>&) const noexcept {
			return false;
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Ray<Arithmetic>&) const noexcept {
			return false;
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Segment<Arithmetic>& segment) const noexcept {
			return (*this == segment.start) && (*this == segment.end);
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Polygon<Arithmetic>& polygon) const noexcept {
			for (const Point point : polygon) {
				if (*this != point) {
					return false;
				}
			}
			return true;
		}
	};
}
