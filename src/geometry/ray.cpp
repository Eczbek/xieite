export module xieite:geometry.Ray;

import std;
import :concepts.Arithmetic;
import :geometry.Point;
import :math.almostEqual;

export namespace xieite::geometry {
	template<xieite::concepts::Arithmetic>
	struct Line;

	template<xieite::concepts::Arithmetic>
	struct Segment;

	template<xieite::concepts::Arithmetic>
	struct Polygon;

	template<xieite::concepts::Arithmetic Arithmetic = double>
	struct Ray {
		xieite::geometry::Point<Arithmetic> start;
		xieite::geometry::Point<Arithmetic> end;

		constexpr Ray(const xieite::geometry::Point<Arithmetic> start, const xieite::geometry::Point<Arithmetic> end) noexcept
		: start(start), end(end) {}

		constexpr Ray(const xieite::geometry::Point<Arithmetic> start, const std::conditional_t<std::floating_point<Arithmetic>, Arithmetic, double> angle) noexcept
		: start(start), end(std::cos(angle), std::sin(angle)) {}

		template<typename OtherArithmetic>
		[[nodiscard]] explicit(false) constexpr operator xieite::geometry::Ray<OtherArithmetic>() const noexcept {
			return xieite::geometry::Ray<OtherArithmetic>(this->start, this->end);
		}

		[[nodiscard]] friend constexpr bool operator==(const xieite::geometry::Ray<Arithmetic>& ray1, const xieite::geometry::Ray<Arithmetic>& ray2) noexcept {
			return (ray1.start == ray2.start) && xieite::math::almostEqual(ray1.angle(), ray2.angle());
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
			return xieite::math::almostEqual((this->end.x - this->start.x) * (point.y - this->start.y), (this->end.y - this->start.y) * (point.x - this->start.x)) && ((this->start.x <= this->end.x) == (this->start.x <= point.x)) && ((this->start.y <= this->end.y) == (this->start.y <= point.y));
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Line<Arithmetic>&) const noexcept {
			return false;
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Ray<Arithmetic>& ray) const noexcept {
			return this->contains(ray.start) && xieite::math::almostEqual(this->angle(), ray.angle());
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Segment<Arithmetic>& segment) const noexcept {
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
