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

	template<xieite::concepts::Arithmetic Arithmetic_ = double>
	struct Point {
		Arithmetic_ x;
		Arithmetic_ y;

		constexpr Point(const Arithmetic_ x = 0, const Arithmetic_ y = 0) noexcept
		: x(x), y(y) {}

		template<typename OtherArithmetic_>
		[[nodiscard]] constexpr operator xieite::geometry::Point<OtherArithmetic_>() const noexcept {
			return xieite::geometry::Point<OtherArithmetic_>(static_cast<OtherArithmetic_>(this->x), static_cast<OtherArithmetic_>(this->y));
		}

		[[nodiscard]] friend constexpr bool operator==(const xieite::geometry::Point<Arithmetic_> point1, const xieite::geometry::Point<Arithmetic_> point2) noexcept {
			return xieite::math::almostEqual(point1.x, point2.x) && xieite::math::almostEqual(point1.y, point2.y);
		}

		[[nodiscard]] constexpr std::conditional_t<std::floating_point<Arithmetic_>, Arithmetic_, double> angleTo(const xieite::geometry::Point<Arithmetic_> point) const noexcept {
			return std::fmod(std::atan2(this->y - point.y, this->x - point.x) + xieite::math::pi<std::conditional_t<std::floating_point<Arithmetic_>, Arithmetic_, double>>, xieite::math::tau<Arithmetic_>);
		}

		[[nodiscard]] constexpr std::conditional_t<std::floating_point<Arithmetic_>, Arithmetic_, double> distanceTo(const xieite::geometry::Point<Arithmetic_> point) const noexcept {
			return std::hypot(this->x - point.x, this->y - point.y);
		}

		[[nodiscard]] constexpr std::conditional_t<std::floating_point<Arithmetic_>, Arithmetic_, double> slopeTo(const xieite::geometry::Point<Arithmetic_> point) const noexcept {
			return xieite::math::almostEqual(this->x, point.x) ? std::numeric_limits<std::conditional_t<std::floating_point<Arithmetic_>, Arithmetic_, double>>::infinity() : ((point.y - this->y) / (point.x - this->x));
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Point<Arithmetic_> point) const noexcept {
			return *this == point;
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Line<Arithmetic_>&) const noexcept {
			return false;
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Ray<Arithmetic_>&) const noexcept {
			return false;
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Segment<Arithmetic_>& segment) const noexcept {
			return (*this == segment.start) && (*this == segment.end);
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Polygon<Arithmetic_>& polygon) const noexcept {
			for (const xieite::geometry::Point<Arithmetic_> point : polygon) {
				if (*this != point) {
					return false;
				}
			}
			return true;
		}
	};
}

#endif
