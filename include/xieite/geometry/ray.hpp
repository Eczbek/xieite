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

	template<xieite::concepts::Arithmetic Arithmetic_ = double>
	struct Ray {
		xieite::geometry::Point<Arithmetic_> start;
		xieite::geometry::Point<Arithmetic_> end;

		constexpr Ray(const xieite::geometry::Point<Arithmetic_> start, const xieite::geometry::Point<Arithmetic_> end) noexcept
		: start(start), end(end) {}

		constexpr Ray(const xieite::geometry::Point<Arithmetic_> start, const std::conditional_t<std::floating_point<Arithmetic_>, Arithmetic_, double> angle) noexcept
		: start(start), end(std::cos(angle), std::sin(angle)) {}

		template<typename OtherArithmetic_>
		[[nodiscard]] constexpr operator xieite::geometry::Ray<OtherArithmetic_>() const noexcept {
			return xieite::geometry::Ray<OtherArithmetic_>(this->start, this->end);
		}

		[[nodiscard]] friend constexpr bool operator==(const xieite::geometry::Ray<Arithmetic_>& ray1, const xieite::geometry::Ray<Arithmetic_>& ray2) noexcept {
			return (ray1.start == ray2.start) && xieite::math::almostEqual(ray1.angle(), ray2.angle());
		}

		[[nodiscard]] constexpr std::conditional_t<std::floating_point<Arithmetic_>, Arithmetic_, double> angle() const noexcept {
			return this->start.angleTo(this->end);
		}

		[[nodiscard]] constexpr std::conditional_t<std::floating_point<Arithmetic_>, Arithmetic_, double> length() const noexcept {
			return std::numeric_limits<std::conditional_t<std::floating_point<Arithmetic_>, Arithmetic_, double>>::infinity();
		}

		[[nodiscard]] constexpr std::conditional_t<std::floating_point<Arithmetic_>, Arithmetic_, double> slope() const noexcept {
			return this->start.slopeTo(this->end);
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Point<Arithmetic_> point) const noexcept {
			return xieite::math::almostEqual((this->end.x - this->start.x) * (point.y - this->start.y), (this->end.y - this->start.y) * (point.x - this->start.x)) && ((this->start.x <= this->end.x) == (this->start.x <= point.x)) && ((this->start.y <= this->end.y) == (this->start.y <= point.y));
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Line<Arithmetic_>&) const noexcept {
			return false;
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Ray<Arithmetic_>& ray) const noexcept {
			return this->contains(ray.start) && xieite::math::almostEqual(this->angle(), ray.angle());
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
