module;

#include <xieite/fn.hpp>

export module xieite:poly2d;

import std;
import :ranges_rotated;
import :is_arith;
import :intxn2d;
import :point2d;
import :segm2d;

export namespace xieite {
	template<xieite::is_arith>
	struct line2d;

	template<xieite::is_arith>
	struct ray2d;

	template<xieite::is_arith T = double>
	struct poly2d {
		std::vector<xieite::point2d<T>> points;

		template<std::ranges::input_range R = std::vector<xieite::point2d<T>>>
		requires(std::convertible_to<std::ranges::range_value_t<R>, xieite::point2d<T>>)
		explicit constexpr poly2d(R&& points) noexcept
		: points(std::ranges::begin(points), std::ranges::end(points)) {}

		template<typename U>
		[[nodiscard]] explicit(false) constexpr operator xieite::poly2d<U>() const noexcept {
			auto other_points = std::vector<xieite::point2d<U>>(this->points.size());
			std::ranges::transform(this->points, other_points.begin(), XIEITE_FN(static_cast<xieite::point2d<U>>($0)));
			return xieite::poly2d<U>(other_points);
		}

		[[nodiscard]] friend constexpr bool operator==(const xieite::poly2d<T>& left, const xieite::poly2d<T>& right) noexcept {
			return xieite::ranges_rotated(left.points, right.points) || xieite::ranges_rotated(left.points, std::views::reverse(right.points));
		}

		[[nodiscard]] static constexpr xieite::poly2d<T> rect(xieite::point2d<T> start, xieite::point2d<T> end) noexcept {
			return xieite::poly2d<T>(std::vector<xieite::point2d<T>> { start, xieite::point2d<T>(start.x, end.y), end, xieite::point2d<T>(end.x, start.y) });
		}

		[[nodiscard]] constexpr std::common_type_t<T, double> area() const noexcept {
			std::common_type_t<T, double> area = 0;
			for (std::size_t i = 0; i < this->points.size(); ++i) {
				const std::size_t j = (i + 1) % this->points.size();
				area += this->points[i].x * this->points[j].y - this->points[j].x * this->points[i].y;
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
			sides.reserve(this->points.size());
			for (std::size_t i = 0; i < this->points.size(); ++i) {
				sides.push_back(xieite::segm2d<T>(this->points[i], this->points[(i + 1) % this->points.size()]));
			}
			return sides;
		}

		[[nodiscard]] constexpr bool contains(xieite::point2d<T> point) const noexcept {
			bool odd = false;
			for (std::size_t i = 0; i < this->points.size(); ++i) {
				const std::size_t j = (i + 1) % this->points.size();
				odd ^= ((this->points[i].y < point.y) && (this->points[j].y >= point.y) || (this->points[j].y < point.y) && (this->points[i].y >= point.y)) && ((this->points[i].x <= point.x) || (this->points[j].x <= point.x)) && (this->points[i].x + (point.y - this->points[i].y) / (this->points[j].y - this->points[i].y) * (this->points[j].x - this->points[i].x) < point.x);
			}
			if (odd) {
				return true;
			}
			for (const xieite::segm2d<T>& side : this->sides()) {
				if (side.contains(point)) {
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
			return poly.points.size() && this->contains(poly.points[0]) && (xieite::intxn2d(*this, poly).size() < 2);
		}
	};
}
