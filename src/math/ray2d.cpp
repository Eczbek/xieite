export module xieite:ray2d;

import std;
import :almost_eq;
import :is_arith;
import :pt2d;

export namespace xieite {
	template<xieite::is_arith>
	struct line2d;

	template<xieite::is_arith>
	struct segm2d;

	template<xieite::is_arith>
	struct poly2d;

	template<xieite::is_arith T = double>
	struct ray2d {
		xieite::pt2d<T> a;
		xieite::pt2d<T> b;

		[[nodiscard]] ray2d() = default;

		[[nodiscard]] constexpr ray2d(xieite::pt2d<T> a, xieite::pt2d<T> b) noexcept
		: a(a), b(b) {}

		[[nodiscard]] constexpr ray2d(xieite::pt2d<T> a, std::common_type_t<T, double> angle) noexcept
		: a(a), b(std::cos(angle), std::sin(angle)) {}

		template<typename U>
		[[nodiscard]] constexpr operator xieite::ray2d<U>() const noexcept {
			return xieite::ray2d<U>(this->a, this->b);
		}

		[[nodiscard]] friend constexpr bool operator==(const xieite::ray2d<T>& left, const xieite::ray2d<T>& right) noexcept {
			return (left.a == right.a) && xieite::almost_eq(left.angle(), right.angle());
		}

		[[nodiscard]] constexpr std::common_type_t<T, double> angle() const noexcept {
			return this->a.angle_to(this->b);
		}

		[[nodiscard]] constexpr std::common_type_t<T, double> len() const noexcept {
			return std::numeric_limits<std::common_type_t<T, double>>::infinity();
		}

		[[nodiscard]] constexpr std::common_type_t<T, double> slope() const noexcept {
			return this->a.slope_to(this->b);
		}

		[[nodiscard]] constexpr bool contains(xieite::pt2d<T> pt) const noexcept {
			return xieite::almost_eq((this->b.x - this->a.x) * (pt.y - this->a.y), (this->b.y - this->a.y) * (pt.x - this->a.x)) && ((this->a.x <= this->b.x) == (this->a.x <= pt.x)) && ((this->a.y <= this->b.y) == (this->a.y <= pt.y));
		}

		[[nodiscard]] constexpr bool contains(const xieite::line2d<T>&) const noexcept {
			return false;
		}

		[[nodiscard]] constexpr bool contains(const xieite::ray2d<T>& ray) const noexcept {
			return this->contains(ray.a) && xieite::almost_eq(this->angle(), ray.angle());
		}

		[[nodiscard]] constexpr bool contains(const xieite::segm2d<T>& segm) const noexcept {
			return this->contains(segm.a) && this->contains(segm.b);
		}

		[[nodiscard]] constexpr bool contains(const xieite::poly2d<T>& poly) const noexcept {
			for (xieite::pt2d<T> pt : poly.pts) {
				if (!this->contains(pt)) {
					return false;
				}
			}
			return true;
		}
	};
}
