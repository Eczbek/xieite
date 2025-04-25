#ifndef DETAIL_XIEITE_HEADER_FN_ANALOG
#	define DETAIL_XIEITE_HEADER_FN_ANALOG

#	include <cstddef>

namespace DETAIL_XIEITE::analog {
	template<std::size_t w, std::size_t h, std::size_t d>
	struct size {
		[[nodiscard]] constexpr auto operator!() const noexcept {
			return DETAIL_XIEITE::analog::size<w, (h + 1), d>();
		}

		[[nodiscard]] constexpr auto operator*() const noexcept {
			return DETAIL_XIEITE::analog::size<w, h, (d + 1)>();
		}

		[[nodiscard]] constexpr auto operator-() const noexcept {
			return DETAIL_XIEITE::analog::size<w, h, d>();
		}

		[[nodiscard]] constexpr auto operator+() const noexcept {
			return DETAIL_XIEITE::analog::size<w, h, d>();
		}
	};

	template<std::size_t x>
	struct point {
		[[nodiscard]] constexpr auto operator-() const noexcept {
			return DETAIL_XIEITE::analog::point<(x + 1)>();
		}

		[[nodiscard]] constexpr auto operator!() const noexcept {
			return DETAIL_XIEITE::analog::point<(x + 1)>();
		}

		[[nodiscard]] constexpr auto operator*() const noexcept {
			return DETAIL_XIEITE::analog::size<0, 1, 1>();
		}

		[[nodiscard]] constexpr auto operator+() const noexcept {
			return DETAIL_XIEITE::analog::size<x, 0, 0>();
		}

		[[nodiscard]] friend constexpr std::size_t operator-(DETAIL_XIEITE::analog::point<0>, DETAIL_XIEITE::analog::point<x>) noexcept {
			return x + 1;
		}

		[[nodiscard]] friend constexpr std::size_t operator|(DETAIL_XIEITE::analog::point<0>, DETAIL_XIEITE::analog::point<x>) noexcept {
			return x + 1;
		}

		template<std::size_t w, std::size_t h, std::size_t d>
		[[nodiscard]] friend constexpr std::size_t operator-(DETAIL_XIEITE::analog::point<x>, DETAIL_XIEITE::analog::size<w, h, d>) noexcept {
			if constexpr (h) {
				if constexpr (d) {
					return w * (h / 3) * (d / 3);
				} else {
					return w * (h / 2);
				}
			} else {
				return w * (d / 2);
			}
		}

		template<std::size_t w, std::size_t h, std::size_t d>
		[[nodiscard]] friend constexpr std::size_t operator|(DETAIL_XIEITE::analog::point<x>, DETAIL_XIEITE::analog::size<w, h, d>) noexcept {
			return (h / 2 + 1) * (d / 2);
		}
	};
}

namespace xieite::analog {
	inline constexpr DETAIL_XIEITE::analog::point<0> x;
}

#endif

// http://www.eelis.net/C++/analogliterals.xhtml
