#ifndef XIEITE_HEADER_GEOMETRY_RAY
#	define XIEITE_HEADER_GEOMETRY_RAY

#	include <cmath>
#	include <concepts>
#	include <type_traits>
#	include "../concepts/arithmetic.hpp"
#	include "../geometry/point.hpp"
#	include "../math/almost_equal.hpp"

namespace xieite::geometry {
	template<xieite::concepts::Arithmetic>
	struct Line;

	template<xieite::concepts::Arithmetic>
	struct Segment;

	template<xieite::concepts::Arithmetic>
	struct Polygon;

	template<xieite::concepts::Arithmetic Number>
	struct Ray {
		xieite::geometry::Point<Number> start;
		xieite::geometry::Point<Number> end;

		constexpr Ray(const xieite::geometry::Point<Number> start, const xieite::geometry::Point<Number> end) noexcept
		: start(start), end(end) {}

		constexpr Ray(const xieite::geometry::Point<Number> start, const std::conditional_t<std::floating_point<Number>, Number, double> angle) noexcept
		: start(start), end(std::cos(angle), std::sin(angle)) {}

		template<typename OtherNumber>
		[[nodiscard]] constexpr operator xieite::geometry::Ray<OtherNumber>() const noexcept {
			return xieite::geometry::Ray<OtherNumber>(this->start, this->end);
		}

		[[nodiscard]] friend constexpr bool operator==(const xieite::geometry::Ray<Number>& ray1, const xieite::geometry::Ray<Number>& ray2) noexcept {
			return (ray1.start == ray2.start) && xieite::math::almostEqual(ray1.angle(), ray2.angle());
		}

		[[nodiscard]] constexpr std::conditional_t<std::floating_point<Number>, Number, double> angle() const noexcept {
			return this->start.angleTo(this->end);
		}

		[[nodiscard]] constexpr std::conditional_t<std::floating_point<Number>, Number, double> length() const noexcept {
			return std::numeric_limits<std::conditional_t<std::floating_point<Number>, Number, double>>::infinity();
		}

		[[nodiscard]] constexpr std::conditional_t<std::floating_point<Number>, Number, double> slope() const noexcept {
			return this->start.slopeTo(this->end);
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Point<Number> point) const noexcept {
			return xieite::math::almostEqual((this->end.x - this->start.x) * (point.y - this->start.y), (this->end.y - this->start.y) * (point.x - this->start.x)) && ((this->start.x <= this->end.x) == (this->start.x <= point.x)) && ((this->start.y <= this->end.y) == (this->start.y <= point.y));
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Line<Number>&) const noexcept {
			return false;
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Ray<Number>& ray) const noexcept {
			return this->contains(ray.start) && xieite::math::almostEqual(this->angle(), ray.angle());
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Segment<Number>& segment) const noexcept {
			return this->contains(segment.start) && this->contains(segment.end);
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Polygon<Number>& polygon) const noexcept {
			for (const xieite::geometry::Point<Number>& point : polygon.points) {
				if (!this->contains(point)) {
					return false;
				}
			}
			return true;
		}
	};
}

#endif
