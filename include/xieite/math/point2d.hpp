#ifndef DETAIL_XIEITE_HEADER_MATH_POINT2D
#	define DETAIL_XIEITE_HEADER_MATH_POINT2D
#
#	include <cmath>
#	include <limits>
#	include <type_traits>
#	include "../math/almost_equal.hpp"
#	include "../math/pi.hpp"
#	include "../math/tau.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith>
	struct line2d;

	template<xieite::is_arith>
	struct ray2d;

	template<xieite::is_arith>
	struct segment2d;

	template<xieite::is_arith>
	struct polygon2d;

	template<xieite::is_arith Arith = double>
	struct point2d {
		Arith x = 0;
		Arith y = 0;

		[[nodiscard]] point2d() = default;

		[[nodiscard]] constexpr point2d(Arith x, Arith y) noexcept
		: x(x), y(y) {}

		template<typename OtherArith>
		[[nodiscard]] explicit constexpr operator xieite::point2d<OtherArith>() const noexcept {
			return xieite::point2d<OtherArith>(static_cast<OtherArith>(this->x), static_cast<OtherArith>(this->y));
		}

		[[nodiscard]] friend constexpr bool operator==(xieite::point2d<Arith> lhs, xieite::point2d<Arith> rhs) noexcept {
			return xieite::almost_equal(lhs.x, rhs.x) && xieite::almost_equal(lhs.y, rhs.y);
		}

		[[nodiscard]] constexpr std::common_type_t<Arith, double> angle_to(xieite::point2d<Arith> point) const noexcept {
			return std::fmod(std::atan2(this->y - point.y, this->x - point.x) + xieite::pi<std::common_type_t<Arith, double>>, xieite::tau<Arith>);
		}

		[[nodiscard]] constexpr std::common_type_t<Arith, double> dist_to(xieite::point2d<Arith> point) const noexcept {
			return std::hypot(this->x - point.x, this->y - point.y);
		}

		[[nodiscard]] constexpr std::common_type_t<Arith, double> slope_to(xieite::point2d<Arith> point) const noexcept {
			using Result = std::common_type_t<Arith, double>;
			return xieite::almost_equal(this->x, point.x)
				? std::numeric_limits<Result>::infinity()
				: (static_cast<Result>(point.y - this->y) / static_cast<Result>(point.x - this->x));
		}

		[[nodiscard]] constexpr bool contains(xieite::point2d<Arith> point) const noexcept {
			return *this == point;
		}

		[[nodiscard]] constexpr bool contains(const xieite::line2d<Arith>&) const noexcept {
			return false;
		}

		[[nodiscard]] constexpr bool contains(const xieite::ray2d<Arith>&) const noexcept {
			return false;
		}

		[[nodiscard]] constexpr bool contains(const xieite::segment2d<Arith>& segm) const noexcept {
			return (*this == segm.start) && (*this == segm.end);
		}

		[[nodiscard]] constexpr bool contains(const xieite::polygon2d<Arith>& polygon) const noexcept {
			for (xieite::point2d<Arith> point : polygon.points) {
				if (*this != point) {
					return false;
				}
			}
			return true;
		}
	};
}

#endif
