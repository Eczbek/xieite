#ifndef DETAIL_XIEITE_HEADER_MATH_POLY2D
#	define DETAIL_XIEITE_HEADER_MATH_POLY2D
#
#	include <algorithm>
#	include <concepts>
#	include <cstddef>
#	include <ranges>
#	include <type_traits>
#	include <vector>
#	include "../ctnr/rotated.hpp"
#	include "../fn/cast.hpp"
#	include "../math/intxn2d.hpp"
#	include "../math/pt2d.hpp"
#	include "../math/segm2d.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith>
	struct line2d;

	template<xieite::is_arith>
	struct ray2d;

	template<xieite::is_arith T = double>
	struct poly2d {
		std::vector<xieite::pt2d<T>> pts;

		[[nodiscard]] poly2d() = default;

		template<std::ranges::input_range R = std::vector<xieite::pt2d<T>>>
		requires(std::convertible_to<std::ranges::range_value_t<R>, xieite::pt2d<T>>)
		[[nodiscard]] explicit constexpr poly2d(R&& pts) noexcept
		: pts(std::ranges::begin(pts), std::ranges::end(pts)) {}

		template<typename U>
		[[nodiscard]] explicit constexpr operator xieite::poly2d<U>() const noexcept {
			auto other_pts = std::vector<xieite::pt2d<U>>(this->pts.size());
			std::ranges::transform(this->pts, other_pts.begin(), xieite::cast<xieite::pt2d<U>>);
			return xieite::poly2d<U>(other_pts);
		}

		[[nodiscard]] friend constexpr bool operator==(const xieite::poly2d<T>& l, const xieite::poly2d<T>& r) noexcept {
			return xieite::rotated(l.pts, r.pts) || xieite::rotated(l.pts, std::views::reverse(r.pts));
		}

		[[nodiscard]] static constexpr xieite::poly2d<T> rect(xieite::pt2d<T> start, xieite::pt2d<T> end) noexcept {
			return xieite::poly2d<T>(std::vector<xieite::pt2d<T>> { start, xieite::pt2d<T>(start.x, end.y), end, xieite::pt2d<T>(end.x, start.y) });
		}

		[[nodiscard]] constexpr std::common_type_t<T, double> area() const noexcept {
			std::common_type_t<T, double> area = 0;
			for (std::size_t i = 0; i < this->pts.size(); ++i) {
				const std::size_t j = (i + 1) % this->pts.size();
				area += this->pts[i].x * this->pts[j].y - this->pts[j].x * this->pts[i].y;
			}
			return area / 2;
		}

		[[nodiscard]] constexpr std::common_type_t<T, double> perim() const noexcept {
			std::common_type_t<T, double> perim = 0;
			for (const xieite::segm2d<T>& side : this->sides()) {
				perim += side.length();
			}
			return perim;
		}

		[[nodiscard]] constexpr std::vector<xieite::segm2d<T>> sides() const noexcept {
			std::vector<xieite::segm2d<T>> sides;
			sides.reserve(this->pts.size());
			for (std::size_t i = 0; i < this->pts.size(); ++i) {
				sides.push_back(xieite::segm2d<T>(this->pts[i], this->pts[(i + 1) % this->pts.size()]));
			}
			return sides;
		}

		[[nodiscard]] constexpr bool contains(xieite::pt2d<T> pt) const noexcept {
			bool odd = false;
			for (std::size_t i = 0; i < this->pts.size(); ++i) {
				const std::size_t j = (i + 1) % this->pts.size();
				odd ^= (((this->pts[i].y < pt.y) && (this->pts[j].y >= pt.y)) || ((this->pts[j].y < pt.y) && (this->pts[i].y >= pt.y))) && ((this->pts[i].x <= pt.x) || (this->pts[j].x <= pt.x)) && (this->pts[i].x + (pt.y - this->pts[i].y) / (this->pts[j].y - this->pts[i].y) * (this->pts[j].x - this->pts[i].x) < pt.x);
			}
			if (odd) {
				return true;
			}
			for (const xieite::segm2d<T>& side : this->sides()) {
				if (side.contains(pt)) {
					return true;
				}
			}
			return false;
		}

		[[nodiscard]] constexpr bool contains(const xieite::line2d<T>&) const noexcept {
			return false;
		}

		[[nodiscard]] constexpr bool contains(const xieite::ray2d<T>&) const noexcept {
			return false;
		}

		[[nodiscard]] constexpr bool contains(const xieite::segm2d<T>& segm) const noexcept {
			return this->contains(segm.start) && this->contains(segm.end) && (xieite::intxn2d(*this, segm).size() < 2);
		}

		[[nodiscard]] constexpr bool contains(const xieite::poly2d<T>& poly) const noexcept {
			return poly.pts.size() && this->contains(poly.pts[0]) && (xieite::intxn2d(*this, poly).size() < 2);
		}
	};
}

#endif
