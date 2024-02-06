#ifndef XIEITE_HEADER_GEOMETRY_LINE
#	define XIEITE_HEADER_GEOMETRY_LINE

#	include <cmath>
#	include <concepts>
#	include <limits>
#	include <type_traits>
#	include "../concepts/same_as_any.hpp"
#	include "../geometry/point.hpp"
#	include "../math/almost_equal.hpp"

namespace xieite::geometry {
	template<xieite::concepts::Arithmetic>
	struct Polygon;

	template<xieite::concepts::Arithmetic>
	struct Ray;

	template<xieite::concepts::Arithmetic>
	struct Segment;

	template<xieite::concepts::Arithmetic Number>
	struct Line {
		xieite::geometry::Point<Number> start;
		xieite::geometry::Point<Number> end;

		constexpr Line(const xieite::geometry::Point<Number> start, const xieite::geometry::Point<Number> end) noexcept
		: start(start), end(end) {}

		constexpr Line(const xieite::geometry::Point<Number> start, const std::conditional_t<std::floating_point<Number>, Number, double> angle) noexcept
		: start(start), end(std::cos(angle), std::sin(angle)) {}

		template<typename OtherNumber>
		[[nodiscard]] constexpr operator xieite::geometry::Line<OtherNumber>() const noexcept {
			return xieite::geometry::Line<OtherNumber>(this->start, this->end);
		}

		[[nodiscard]] friend constexpr bool operator==(const xieite::geometry::Line<Number>& line1, const xieite::geometry::Line<Number>& line2) noexcept {
			return line1.contains(line2.start) && line1.contains(line2.end);
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
			return xieite::math::almostEqual((this->end.x - this->start.x) * (point.y - this->start.y), (this->end.y - this->start.y) * (point.x - this->start.x));
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Line<Number>& line) const noexcept {
			return *this == line;
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Ray<Number>& ray) const noexcept {
			return *this == xieite::geometry::Line<Number>(ray.start, ray.end);
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Segment<Number>& segment) const noexcept {
			return *this == xieite::geometry::Line<Number>(segment.start, segment.end);
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Polygon<Number>& polygon) const noexcept {
			for (const xieite::geometry::Point<Number> point : polygon.points) {
				if (!this->contains(point)) {
					return false;
				}
			}
			return true;
		}
	};
}

#endif
