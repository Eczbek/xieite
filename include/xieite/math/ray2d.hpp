#ifndef DETAIL_XIEITE_HEADER_MATH_RAY2D
#	define DETAIL_XIEITE_HEADER_MATH_RAY2D
#
#	include <cmath>
#	include <limits>
#	include <type_traits>
#	include "../math/point2d.hpp"
#	include "../math/almost_equal.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith>
	struct line2d;

	template<xieite::is_arith>
	struct segment2d;

	template<xieite::is_arith>
	struct polygon2d;

	template<xieite::is_arith Arith = double>
	struct ray2d {
		xieite::point2d<Arith> a;
		xieite::point2d<Arith> b;

		[[nodiscard]] ray2d() = default;

		[[nodiscard]] constexpr ray2d(xieite::point2d<Arith> a, xieite::point2d<Arith> b) noexcept
		: a(a), b(b) {}

		[[nodiscard]] constexpr ray2d(xieite::point2d<Arith> a, std::common_type_t<Arith, double> angle) noexcept
		: a(a), b(std::cos(angle), std::sin(angle)) {}

		template<typename OtherArith>
		[[nodiscard]] explicit constexpr operator xieite::ray2d<OtherArith>() const noexcept {
			return xieite::ray2d<OtherArith>(static_cast<OtherArith>(this->a), static_cast<OtherArith>(this->b));
		}

		[[nodiscard]] friend constexpr bool operator==(const xieite::ray2d<Arith>& lhs, const xieite::ray2d<Arith>& rhs) noexcept {
			return (lhs.a == rhs.a) && xieite::almost_equal(lhs.angle(), rhs.angle());
		}

		[[nodiscard]] constexpr std::common_type_t<Arith, double> angle() const noexcept {
			return this->a.angle_to(this->b);
		}

		[[nodiscard]] constexpr std::common_type_t<Arith, double> length() const noexcept {
			return std::numeric_limits<std::common_type_t<Arith, double>>::infinity();
		}

		[[nodiscard]] constexpr std::common_type_t<Arith, double> slope() const noexcept {
			return this->a.slope_to(this->b);
		}

		[[nodiscard]] constexpr bool contains(xieite::point2d<Arith> point) const noexcept {
			return xieite::almost_equal((this->b.x - this->a.x) * (point.y - this->a.y), (this->b.y - this->a.y) * (point.x - this->a.x)) && ((this->a.x <= this->b.x) == (this->a.x <= point.x)) && ((this->a.y <= this->b.y) == (this->a.y <= point.y));
		}

		[[nodiscard]] constexpr bool contains(const xieite::line2d<Arith>&) const noexcept {
			return false;
		}

		[[nodiscard]] constexpr bool contains(const xieite::ray2d<Arith>& ray) const noexcept {
			return this->contains(ray.a) && xieite::almost_equal(this->angle(), ray.angle());
		}

		[[nodiscard]] constexpr bool contains(const xieite::segment2d<Arith>& segment) const noexcept {
			return this->contains(segment.a) && this->contains(segment.b);
		}

		[[nodiscard]] constexpr bool contains(const xieite::polygon2d<Arith>& polygon) const noexcept {
			for (xieite::point2d<Arith> point : polygon.points) {
				if (!this->contains(point)) {
					return false;
				}
			}
			return true;
		}
	};
}

#endif
