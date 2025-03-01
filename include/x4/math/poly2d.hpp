#pragma once

#include <algorithm>
#include <concepts>
#include <cstddef>
#include <ranges>
#include <type_traits>
#include <vector>
#include "../ctnr/rotd.hpp"
#include "../fn/cast.hpp"
#include "../math/intxn2d.hpp"
#include "../math/pt2d.hpp"
#include "../math/segm2d.hpp"
#include "../trait/isarith.hpp"

namespace x4 {
	template<x4::isarith>
	struct line2d;

	template<x4::isarith>
	struct ray2d;

	template<x4::isarith T = double>
	struct poly2d {
		std::vector<x4::pt2d<T>> pts;

		[[nodiscard]] poly2d() = default;

		template<std::ranges::input_range R = std::vector<x4::pt2d<T>>>
		requires(std::convertible_to<std::ranges::range_value_t<R>, x4::pt2d<T>>)
		[[nodiscard]] explicit constexpr poly2d(R&& pts) noexcept
		: pts(std::ranges::begin(pts), std::ranges::end(pts)) {}

		template<typename U>
		[[nodiscard]] explicit constexpr operator x4::poly2d<U>() const noexcept {
			auto other_pts = std::vector<x4::pt2d<U>>(this->pts.size());
			std::ranges::transform(this->pts, other_pts.begin(), x4::cast<x4::pt2d<U>>);
			return x4::poly2d<U>(other_pts);
		}

		[[nodiscard]] friend constexpr bool operator==(const x4::poly2d<T>& l, const x4::poly2d<T>& r) noexcept {
			return x4::rotd(l.pts, r.pts) || x4::rotd(l.pts, std::views::reverse(r.pts));
		}

		[[nodiscard]] static constexpr x4::poly2d<T> rect(x4::pt2d<T> start, x4::pt2d<T> end) noexcept {
			return x4::poly2d<T>(std::vector<x4::pt2d<T>> { start, x4::pt2d<T>(start.x, end.y), end, x4::pt2d<T>(end.x, start.y) });
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
			for (const x4::segm2d<T>& side : this->sides()) {
				perim += side.length();
			}
			return perim;
		}

		[[nodiscard]] constexpr std::vector<x4::segm2d<T>> sides() const noexcept {
			std::vector<x4::segm2d<T>> sides;
			sides.reserve(this->pts.size());
			for (std::size_t i = 0; i < this->pts.size(); ++i) {
				sides.push_back(x4::segm2d<T>(this->pts[i], this->pts[(i + 1) % this->pts.size()]));
			}
			return sides;
		}

		[[nodiscard]] constexpr bool contains(x4::pt2d<T> pt) const noexcept {
			bool odd = false;
			for (std::size_t i = 0; i < this->pts.size(); ++i) {
				const std::size_t j = (i + 1) % this->pts.size();
				odd ^= (((this->pts[i].y < pt.y) && (this->pts[j].y >= pt.y)) || ((this->pts[j].y < pt.y) && (this->pts[i].y >= pt.y))) && ((this->pts[i].x <= pt.x) || (this->pts[j].x <= pt.x)) && (this->pts[i].x + (pt.y - this->pts[i].y) / (this->pts[j].y - this->pts[i].y) * (this->pts[j].x - this->pts[i].x) < pt.x);
			}
			if (odd) {
				return true;
			}
			for (const x4::segm2d<T>& side : this->sides()) {
				if (side.contains(pt)) {
					return true;
				}
			}
			return false;
		}

		[[nodiscard]] constexpr bool contains(const x4::line2d<T>&) const noexcept {
			return false;
		}

		[[nodiscard]] constexpr bool contains(const x4::ray2d<T>&) const noexcept {
			return false;
		}

		[[nodiscard]] constexpr bool contains(const x4::segm2d<T>& segm) const noexcept {
			return this->contains(segm.start) && this->contains(segm.end) && (x4::intxn2d(*this, segm).size() < 2);
		}

		[[nodiscard]] constexpr bool contains(const x4::poly2d<T>& poly) const noexcept {
			return poly.pts.size() && this->contains(poly.pts[0]) && (x4::intxn2d(*this, poly).size() < 2);
		}
	};
}
