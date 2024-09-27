export module xieite:geometry.Segment;

import std;
import :concepts.Arithmetic;
import :geometry.Point;
import :math.almostEqual;

export namespace xieite::geometry {
	template<xieite::concepts::Arithmetic>
	struct Line;

	template<xieite::concepts::Arithmetic>
	struct Ray;

	template<xieite::concepts::Arithmetic>
	struct Polygon;

	template<xieite::concepts::Arithmetic Arithmetic = double>
	struct Segment {
		xieite::geometry::Point<Arithmetic> start;
		xieite::geometry::Point<Arithmetic> end;

		constexpr Segment(const xieite::geometry::Point<Arithmetic> start, const xieite::geometry::Point<Arithmetic> end) noexcept
		: start(start), end(end) {}

		template<typename OtherArithmetic>
		[[nodiscard]] explicit(false) constexpr operator Segment<OtherArithmetic>() const noexcept {
			return Segment<OtherArithmetic>(this->start, this->end);
		}

		[[nodiscard]] friend constexpr bool operator==(const Segment& left, const Segment& right) noexcept {
			return ((left.start == right.start) && (left.end == right.end)) || ((left.start == right.end) && (left.end == right.start));
		}

		[[nodiscard]] constexpr std::conditional_t<std::floating_point<Arithmetic>, Arithmetic, double> angle() const noexcept {
			return this->start.angleTo(this->end);
		}

		[[nodiscard]] constexpr std::conditional_t<std::floating_point<Arithmetic>, Arithmetic, double> length() const noexcept {
			return this->start.distanceTo(this->end);
		}

		[[nodiscard]] constexpr std::conditional_t<std::floating_point<Arithmetic>, Arithmetic, double> slope() const noexcept {
			return this->start.slopeTo(this->end);
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Point<Arithmetic> point) const noexcept {
			return xieite::math::almostEqual(this->start.distanceTo(point) + this->end.distanceTo(point), this->length());
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Line<Arithmetic>&) const noexcept {
			return false;
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Ray<Arithmetic>&) const noexcept {
			return false;
		}

		[[nodiscard]] constexpr bool contains(const Segment& segment) const noexcept {
			return this->contains(segment.start) && this->contains(segment.end);
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Polygon<Arithmetic>& polygon) const noexcept {
			for (const xieite::geometry::Point<Arithmetic>& point : polygon.points) {
				if (!this->contains(point)) {
					return false;
				}
			}
			return true;
		}
	};
}
