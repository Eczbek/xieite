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
		[[nodiscard]] explicit(false) constexpr operator xieite::geometry::Point<OtherArithmetic>() const noexcept {
			return xieite::geometry::Point<OtherArithmetic>(static_cast<OtherArithmetic>(this->x), static_cast<OtherArithmetic>(this->y));
		}

		[[nodiscard]] friend constexpr bool operator==(const xieite::geometry::Point<Arithmetic> point1, const xieite::geometry::Point<Arithmetic> point2) noexcept {
			return xieite::math::almostEqual(point1.x, point2.x) && xieite::math::almostEqual(point1.y, point2.y);
		}

		[[nodiscard]] constexpr std::conditional_t<std::floating_point<Arithmetic>, Arithmetic, double> angleTo(const xieite::geometry::Point<Arithmetic> point) const noexcept {
			return std::fmod(std::atan2(this->y - point.y, this->x - point.x) + xieite::math::pi<std::conditional_t<std::floating_point<Arithmetic>, Arithmetic, double>>, xieite::math::tau<Arithmetic>);
		}

		[[nodiscard]] constexpr std::conditional_t<std::floating_point<Arithmetic>, Arithmetic, double> distanceTo(const xieite::geometry::Point<Arithmetic> point) const noexcept {
			return std::hypot(this->x - point.x, this->y - point.y);
		}

		[[nodiscard]] constexpr std::conditional_t<std::floating_point<Arithmetic>, Arithmetic, double> slopeTo(const xieite::geometry::Point<Arithmetic> point) const noexcept {
			using Result = std::conditional_t<std::floating_point<Arithmetic>, Arithmetic, double>;
			return xieite::math::almostEqual(this->x, point.x) ? std::numeric_limits<Result>::infinity() : (static_cast<Result>(point.y - this->y) / static_cast<Result>(point.x - this->x));
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Point<Arithmetic> point) const noexcept {
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
			for (const xieite::geometry::Point<Arithmetic> point : polygon) {
				if (*this != point) {
					return false;
				}
			}
			return true;
		}
	};
}
