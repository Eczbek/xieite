#ifndef DETAIL_XIEITE_HEADER_MATH_POLYGON2D
#	define DETAIL_XIEITE_HEADER_MATH_POLYGON2D
#
#	include <algorithm>
#	include <concepts>
#	include <cstddef>
#	include <ranges>
#	include <type_traits>
#	include <vector>
#	include "../data/rotated.hpp"
#	include "../fn/cast.hpp"
#	include "../math/intersection2d.hpp"
#	include "../math/point2d.hpp"
#	include "../math/segment2d.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith>
	struct line2d;

	template<xieite::is_arith>
	struct ray2d;

	template<xieite::is_arith Arith = double>
	struct polygon2d {
		std::vector<xieite::point2d<Arith>> points;

		[[nodiscard]] polygon2d() = default;

		template<std::ranges::input_range Range = std::vector<xieite::point2d<Arith>>>
		requires(std::convertible_to<std::ranges::range_value_t<Range>, xieite::point2d<Arith>>)
		[[nodiscard]] explicit constexpr polygon2d(Range&& points) noexcept
		: points(std::ranges::begin(points), std::ranges::end(points)) {}

		template<typename OtherArith>
		[[nodiscard]] explicit constexpr operator xieite::polygon2d<OtherArith>() const noexcept {
			auto other_pts = std::vector<xieite::point2d<OtherArith>>(this->points.size());
			std::ranges::transform(this->points, other_pts.begin(), xieite::cast<xieite::point2d<OtherArith>>);
			return xieite::polygon2d<OtherArith>(other_pts);
		}

		[[nodiscard]] friend constexpr bool operator==(const xieite::polygon2d<Arith>& lhs, const xieite::polygon2d<Arith>& rhs) noexcept {
			return xieite::rotated(lhs.points, rhs.points) || xieite::rotated(lhs.points, std::views::reverse(rhs.points));
		}

		[[nodiscard]] static constexpr xieite::polygon2d<Arith> rect(xieite::point2d<Arith> start, xieite::point2d<Arith> end) noexcept {
			return xieite::polygon2d<Arith>(std::vector<xieite::point2d<Arith>> { start, xieite::point2d<Arith>(start.x, end.y), end, xieite::point2d<Arith>(end.x, start.y) });
		}

		[[nodiscard]] constexpr std::common_type_t<Arith, double> area() const noexcept {
			std::common_type_t<Arith, double> area = 0;
			for (std::size_t i = 0; i < this->points.size(); ++i) {
				const std::size_t j = (i + 1) % this->points.size();
				area += this->points[i].x * this->points[j].y - this->points[j].x * this->points[i].y;
			}
			return area / 2;
		}

		[[nodiscard]] constexpr std::common_type_t<Arith, double> perim() const noexcept {
			std::common_type_t<Arith, double> perim = 0;
			for (const xieite::segment2d<Arith>& side : this->sides()) {
				perim += side.length();
			}
			return perim;
		}

		[[nodiscard]] constexpr std::vector<xieite::segment2d<Arith>> sides() const noexcept {
			std::vector<xieite::segment2d<Arith>> sides;
			sides.reserve(this->points.size());
			for (std::size_t i = 0; i < this->points.size(); ++i) {
				sides.push_back(xieite::segment2d<Arith>(this->points[i], this->points[(i + 1) % this->points.size()]));
			}
			return sides;
		}

		[[nodiscard]] constexpr bool contains(xieite::point2d<Arith> point) const noexcept {
			bool odd = false;
			for (std::size_t i = 0; i < this->points.size(); ++i) {
				const std::size_t j = (i + 1) % this->points.size();
				odd ^= (((this->points[i].y < point.y) && (this->points[j].y >= point.y)) || ((this->points[j].y < point.y) && (this->points[i].y >= point.y))) && ((this->points[i].x <= point.x) || (this->points[j].x <= point.x)) && (this->points[i].x + (point.y - this->points[i].y) / (this->points[j].y - this->points[i].y) * (this->points[j].x - this->points[i].x) < point.x);
			}
			if (odd) {
				return true;
			}
			for (const xieite::segment2d<Arith>& side : this->sides()) {
				if (side.contains(point)) {
					return true;
				}
			}
			return false;
		}

		[[nodiscard]] constexpr bool contains(const xieite::line2d<Arith>&) const noexcept {
			return false;
		}

		[[nodiscard]] constexpr bool contains(const xieite::ray2d<Arith>&) const noexcept {
			return false;
		}

		[[nodiscard]] constexpr bool contains(const xieite::segment2d<Arith>& segm) const noexcept {
			return this->contains(segm.start) && this->contains(segm.end) && (xieite::intersection2d(*this, segm).size() < 2);
		}

		[[nodiscard]] constexpr bool contains(const xieite::polygon2d<Arith>& polygon) const noexcept {
			return polygon.points.size() && this->contains(polygon.points[0]) && (xieite::intersection2d(*this, polygon).size() < 2);
		}
	};
}

#endif
