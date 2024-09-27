export module xieite:geometry.Line;

import std;
import :geometry.Point;
import :math.almostEqual;

export namespace xieite::geometry {
	template<xieite::concepts::Arithmetic>
	struct Polygon;

	template<xieite::concepts::Arithmetic>
	struct Ray;

	template<xieite::concepts::Arithmetic>
	struct Segment;

	template<xieite::concepts::Arithmetic Arithmetic = double>
	struct Line {
		xieite::geometry::Point<Arithmetic> start;
		xieite::geometry::Point<Arithmetic> end;

		constexpr Line(const xieite::geometry::Point<Arithmetic> start, const xieite::geometry::Point<Arithmetic> end) noexcept
		: start(start), end(end) {}

		constexpr Line(const xieite::geometry::Point<Arithmetic> start, const std::conditional_t<std::floating_point<Arithmetic>, Arithmetic, double> angle) noexcept
		: start(start), end(std::cos(angle), std::sin(angle)) {}

		template<typename OtherArithmetic>
		[[nodiscard]] explicit(false) constexpr operator Line<OtherArithmetic>() const noexcept {
			return Line<OtherArithmetic>(this->start, this->end);
		}

		[[nodiscard]] friend constexpr bool operator==(const Line& left, const Line& right) noexcept {
			return left.contains(right.start) && left.contains(right.end);
		}

		[[nodiscard]] constexpr std::conditional_t<std::floating_point<Arithmetic>, Arithmetic, double> angle() const noexcept {
			return this->start.angleTo(this->end);
		}

		[[nodiscard]] constexpr std::conditional_t<std::floating_point<Arithmetic>, Arithmetic, double> length() const noexcept {
			return std::numeric_limits<std::conditional_t<std::floating_point<Arithmetic>, Arithmetic, double>>::infinity();
		}

		[[nodiscard]] constexpr std::conditional_t<std::floating_point<Arithmetic>, Arithmetic, double> slope() const noexcept {
			return this->start.slopeTo(this->end);
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Point<Arithmetic> point) const noexcept {
			return xieite::math::almostEqual((this->end.x - this->start.x) * (point.y - this->start.y), (this->end.y - this->start.y) * (point.x - this->start.x));
		}

		[[nodiscard]] constexpr bool contains(const Line& line) const noexcept {
			return *this == line;
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Ray<Arithmetic>& ray) const noexcept {
			return *this == Line(ray.start, ray.end);
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Segment<Arithmetic>& segment) const noexcept {
			return *this == Line(segment.start, segment.end);
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Polygon<Arithmetic>& polygon) const noexcept {
			for (const xieite::geometry::Point<Arithmetic> point : polygon.points) {
				if (!this->contains(point)) {
					return false;
				}
			}
			return true;
		}
	};
}
