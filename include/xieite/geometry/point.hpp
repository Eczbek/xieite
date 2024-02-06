#ifndef XIEITE_HEADER_GEOMETRY_POINT
#	define XIEITE_HEADER_GEOMETRY_POINT

#	include <cmath>
#	include "../math/almost_equal.hpp"
#	include "../math/pi.hpp"
#	include "../math/tau.hpp"

namespace xieite::geometry {
	template<xieite::concepts::Arithmetic>
	struct Line;

	template<xieite::concepts::Arithmetic>
	struct Ray;

	template<xieite::concepts::Arithmetic>
	struct Segment;

	template<xieite::concepts::Arithmetic>
	struct Polygon;

	template<xieite::concepts::Arithmetic Number>
	struct Point {
		Number x;
		Number y;

		constexpr Point(const Number x = 0, const Number y = 0) noexcept
		: x(x), y(y) {}

		template<typename OtherNumber>
		[[nodiscard]] constexpr operator xieite::geometry::Point<OtherNumber>() const noexcept {
			return xieite::geometry::Point<OtherNumber>(static_cast<OtherNumber>(this->x), static_cast<OtherNumber>(this->y));
		}

		[[nodiscard]] friend constexpr bool operator==(const xieite::geometry::Point<Number> point1, const xieite::geometry::Point<Number> point2) noexcept {
			return xieite::math::almostEqual(point1.x, point2.x) && xieite::math::almostEqual(point1.y, point2.y);
		}

		[[nodiscard]] constexpr std::conditional_t<std::floating_point<Number>, Number, double> angleTo(const xieite::geometry::Point<Number> point) const noexcept {
			return std::fmod(std::atan2(this->y - point.y, this->x - point.x) + xieite::math::pi<Number>, xieite::math::tau<Number>);
		}

		[[nodiscard]] constexpr std::conditional_t<std::floating_point<Number>, Number, double> distanceTo(const xieite::geometry::Point<Number> point) const noexcept {
			return std::hypot(this->x - point.x, this->y - point.y);
		}

		[[nodiscard]] constexpr std::conditional_t<std::floating_point<Number>, Number, double> slopeTo(const xieite::geometry::Point<Number> point) const noexcept {
			return xieite::math::almostEqual(this->x, point.x) ? std::numeric_limits<std::conditional_t<std::floating_point<Number>, Number, double>>::infinity() : ((point.y - this->y) / (point.x - this->x));
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Point<Number> point) const noexcept {
			return *this == point;
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Line<Number>&) const noexcept {
			return false;
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Ray<Number>&) const noexcept {
			return false;
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Segment<Number>& segment) const noexcept {
			return (*this == segment.start) && (*this == segment.end);
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Polygon<Number>& polygon) const noexcept {
			for (const xieite::geometry::Point<Number> point : polygon) {
				if (*this != point) {
					return false;
				}
			}
			return true;
		}
	};
}

#endif
