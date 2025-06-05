#ifndef DETAIL_XIEITE_HEADER_MATH_LINE2D
#	define DETAIL_XIEITE_HEADER_MATH_LINE2D
#
#	include <cmath>
#	include <type_traits>
#	include "../math/point2d.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith>
	struct polygon2d;

	template<xieite::is_arith>
	struct ray2d;

	template<xieite::is_arith>
	struct segment2d;

	template<xieite::is_arith Arith = double>
	struct line2d {
		xieite::point2d<Arith> a;
		xieite::point2d<Arith> b;

		line2d() = default;

		[[nodiscard]] constexpr line2d(xieite::point2d<Arith> a, xieite::point2d<Arith> b) noexcept
		: a(a), b(b) {}

		[[nodiscard]] constexpr line2d(xieite::point2d<Arith> a, std::common_type_t<Arith, double> angle) noexcept
		: a(a), b(std::cos(angle), std::sin(angle)) {}

		template<typename OtherArith>
		[[nodiscard]] explicit constexpr operator xieite::line2d<OtherArith>() const noexcept {
			return xieite::line2d<OtherArith>(static_cast<OtherArith>(this->a), static_cast<OtherArith>(this->b));
		}

		[[nodiscard]] friend constexpr bool operator==(const xieite::line2d<Arith>& lhs, const xieite::line2d<Arith>& rhs) noexcept {
			return lhs.contains(rhs.a) && lhs.contains(rhs.b);
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
			return xieite::almost_equal(
				(this->b.x - this->a.x) * (point.y - this->a.y),
				(this->b.y - this->a.y) * (point.x - this->a.x)
			);
		}

		[[nodiscard]] constexpr bool contains(const xieite::line2d<Arith>& line) const noexcept {
			return *this == line;
		}

		[[nodiscard]] constexpr bool contains(const xieite::ray2d<Arith>& ray) const noexcept {
			return *this == xieite::line2d<Arith>(ray.a, ray.b);
		}

		[[nodiscard]] constexpr bool contains(const xieite::segment2d<Arith>& segment) const noexcept {
			return *this == xieite::line2d<Arith>(segment.a, segment.b);
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
