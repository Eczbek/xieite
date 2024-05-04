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

	template<xieite::concepts::Arithmetic Arithmetic_ = double>
	struct Segment {
		xieite::geometry::Point<Arithmetic_> start;
		xieite::geometry::Point<Arithmetic_> end;

		constexpr Segment(const xieite::geometry::Point<Arithmetic_> start, const xieite::geometry::Point<Arithmetic_> end) noexcept
		: start(start), end(end) {}

		template<typename OtherArithmetic_>
		[[nodiscard]] constexpr operator xieite::geometry::Segment<OtherArithmetic_>() const noexcept {
			return xieite::geometry::Segment<OtherArithmetic_>(this->start, this->end);
		}

		[[nodiscard]] friend constexpr bool operator==(const xieite::geometry::Segment<Arithmetic_>& segment1, const xieite::geometry::Segment<Arithmetic_>& segment2) noexcept {
			return (segment1.start == segment2.start) && (segment1.end == segment2.end) || (segment1.start == segment2.end) && (segment1.end == segment2.start);
		}

		[[nodiscard]] constexpr std::conditional_t<std::floating_point<Arithmetic_>, Arithmetic_, double> angle() const noexcept {
			return this->start.angleTo(this->end);
		}

		[[nodiscard]] constexpr std::conditional_t<std::floating_point<Arithmetic_>, Arithmetic_, double> length() const noexcept {
			return this->start.distanceTo(this->end);
		}

		[[nodiscard]] constexpr std::conditional_t<std::floating_point<Arithmetic_>, Arithmetic_, double> slope() const noexcept {
			return this->start.slopeTo(this->end);
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Point<Arithmetic_> point) const noexcept {
			return xieite::math::almostEqual(this->start.distanceTo(point) + this->end.distanceTo(point), this->length());
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Line<Arithmetic_>&) const noexcept {
			return false;
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Ray<Arithmetic_>&) const noexcept {
			return false;
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Segment<Arithmetic_>& segment) const noexcept {
			return this->contains(segment.start) && this->contains(segment.end);
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Polygon<Arithmetic_>& polygon) const noexcept {
			for (const xieite::geometry::Point<Arithmetic_>& point : polygon.points) {
				if (!this->contains(point)) {
					return false;
				}
			}
			return true;
		}
	};
}

#endif
