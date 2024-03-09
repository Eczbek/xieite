#ifndef XIEITE_HEADER_GEOMETRY_SEGMENT
#	define XIEITE_HEADER_GEOMETRY_SEGMENT

#	include <concepts>
#	include <type_traits>
#	include "../concepts/arithmetic.hpp"
#	include "../geometry/point.hpp"
#	include "../math/almost_equal.hpp"

namespace xieite::geometry {
	template<xieite::concepts::Arithmetic>
	struct Line;

	template<xieite::concepts::Arithmetic>
	struct Ray;

	template<xieite::concepts::Arithmetic>
	struct Polygon;

	template<xieite::concepts::Arithmetic Number = double>
	struct Segment {
		xieite::geometry::Point<Number> start;
		xieite::geometry::Point<Number> end;

		constexpr Segment(const xieite::geometry::Point<Number> start, const xieite::geometry::Point<Number> end) noexcept
		: start(start), end(end) {}

		template<typename OtherNumber>
		[[nodiscard]] constexpr operator xieite::geometry::Segment<OtherNumber>() const noexcept {
			return xieite::geometry::Segment<OtherNumber>(this->start, this->end);
		}

		[[nodiscard]] friend constexpr bool operator==(const xieite::geometry::Segment<Number>& segment1, const xieite::geometry::Segment<Number>& segment2) noexcept {
			return (segment1.start == segment2.start) && (segment1.end == segment2.end) || (segment1.start == segment2.end) && (segment1.end == segment2.start);
		}

		[[nodiscard]] constexpr std::conditional_t<std::floating_point<Number>, Number, double> angle() const noexcept {
			return this->start.angleTo(this->end);
		}

		[[nodiscard]] constexpr std::conditional_t<std::floating_point<Number>, Number, double> length() const noexcept {
			return this->start.distanceTo(this->end);
		}

		[[nodiscard]] constexpr std::conditional_t<std::floating_point<Number>, Number, double> slope() const noexcept {
			return this->start.slopeTo(this->end);
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Point<Number> point) const noexcept {
			return xieite::math::almostEqual(this->start.distanceTo(point) + this->end.distanceTo(point), this->length());
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Line<Number>&) const noexcept {
			return false;
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Ray<Number>&) const noexcept {
			return false;
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
