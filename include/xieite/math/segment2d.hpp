#ifndef DETAIL_XIEITE_HEADER_MATH_SEGM2D
#	define DETAIL_XIEITE_HEADER_MATH_SEGM2D
#
#	include <type_traits>
#	include "../math/almost_equal.hpp"
#	include "../math/point2d.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith>
	struct line2d;

	template<xieite::is_arith>
	struct ray2d;

	template<xieite::is_arith>
	struct polygon2d;

	template<xieite::is_arith Arith = double>
	struct segment2d {
		xieite::point2d<Arith> start;
		xieite::point2d<Arith> end;

		[[nodiscard]] segment2d() = default;

		[[nodiscard]] constexpr segment2d(xieite::point2d<Arith> start, xieite::point2d<Arith> end) noexcept
		: start(start), end(end) {}

		template<typename OtherArith>
		[[nodiscard]] explicit constexpr operator xieite::segment2d<OtherArith>() const noexcept {
			return xieite::segment2d<OtherArith>(static_cast<OtherArith>(this->start), static_cast<OtherArith>(this->end));
		}

		[[nodiscard]] friend constexpr bool operator==(const xieite::segment2d<Arith>& lhs, const xieite::segment2d<Arith>& rhs) noexcept {
			return ((lhs.start == rhs.start) && (lhs.end == rhs.end)) || ((lhs.start == rhs.end) && (lhs.end == rhs.start));
		}

		[[nodiscard]] constexpr std::common_type_t<Arith, double> angle() const noexcept {
			return this->start.angle_to(this->end);
		}

		[[nodiscard]] constexpr std::common_type_t<Arith, double> length() const noexcept {
			return this->start.distance_to(this->end);
		}

		[[nodiscard]] constexpr std::common_type_t<Arith, double> slope() const noexcept {
			return this->start.slope_to(this->end);
		}

		[[nodiscard]] constexpr bool contains(xieite::point2d<Arith> point) const noexcept {
			return xieite::almost_equal(this->start.distance_to(point) + this->end.distance_to(point), this->length());
		}

		[[nodiscard]] constexpr bool contains(const xieite::line2d<Arith>&) const noexcept {
			return false;
		}

		[[nodiscard]] constexpr bool contains(const xieite::ray2d<Arith>&) const noexcept {
			return false;
		}

		[[nodiscard]] constexpr bool contains(const xieite::segment2d<Arith>& segm) const noexcept {
			return this->contains(segm.start) && this->contains(segm.end);
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
