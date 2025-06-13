#ifndef DETAIL_XIEITE_HEADER_FN_ANALOG
#	define DETAIL_XIEITE_HEADER_FN_ANALOG

#	include <cstddef>

namespace DETAIL_XIEITE::analog {
	template<std::size_t w, std::size_t h, std::size_t l>
	struct size {
		static constexpr std::size_t width = w;
		static constexpr std::size_t height = h;
		static constexpr std::size_t length = l;
		static constexpr std::size_t area = w ? (w * (h ? (h / 2) : (l / 2))) : ((h / 2) * (l / 2));
		static constexpr std::size_t volume = w * (h / 3) * (l / 3);

		[[nodiscard]] constexpr auto operator!() const noexcept {
			return DETAIL_XIEITE::analog::size<w, (h + 1), l>();
		}

		[[nodiscard]] constexpr auto operator*() const noexcept {
			return DETAIL_XIEITE::analog::size<w, h, (l + 1)>();
		}

		[[nodiscard]] constexpr auto operator-() const noexcept {
			return DETAIL_XIEITE::analog::size<w, h, l>();
		}

		[[nodiscard]] constexpr auto operator+() const noexcept {
			return DETAIL_XIEITE::analog::size<w, h, l>();
		}
	};

	template<std::size_t x, std::size_t y>
	struct point {
		static constexpr std::size_t width = x;
		static constexpr std::size_t height = y;
		static constexpr std::size_t length = x + y;
		static constexpr std::size_t area = 0;
		static constexpr std::size_t volume = 0;

		[[nodiscard]] constexpr auto operator-() const noexcept {
			return DETAIL_XIEITE::analog::point<(x + 1), y>();
		}

		[[nodiscard]] constexpr auto operator!() const noexcept {
			return DETAIL_XIEITE::analog::point<x, (y + 1)>();
		}

		[[nodiscard]] constexpr auto operator*() const noexcept {
			return DETAIL_XIEITE::analog::size<0, 1, 1>();
		}

		[[nodiscard]] constexpr auto operator+() const noexcept {
			return DETAIL_XIEITE::analog::size<x, 0, 0>();
		}

		[[nodiscard]] friend constexpr auto operator-(DETAIL_XIEITE::analog::point<0, 0>, DETAIL_XIEITE::analog::point<x, y>) noexcept {
			return DETAIL_XIEITE::analog::point<(x + 1), y>();
		}

		[[nodiscard]] friend constexpr auto operator|(DETAIL_XIEITE::analog::point<0, 0>, DETAIL_XIEITE::analog::point<x, y>) noexcept {
			return DETAIL_XIEITE::analog::point<x, (y + 1)>();
		}

		template<std::size_t w, std::size_t h, std::size_t l>
		[[nodiscard]] friend constexpr auto operator-(DETAIL_XIEITE::analog::point<x, y>, DETAIL_XIEITE::analog::size<w, h, l>) noexcept {
			return DETAIL_XIEITE::analog::size<w, h, l>();
		}

		template<std::size_t w, std::size_t h, std::size_t l>
		[[nodiscard]] friend constexpr auto operator|(DETAIL_XIEITE::analog::point<x, y>, DETAIL_XIEITE::analog::size<w, h, l>) noexcept {
			return DETAIL_XIEITE::analog::size<w, (h + 1), l>();
		}

		template<std::size_t h, std::size_t l>
		[[nodiscard]] friend constexpr auto operator*(DETAIL_XIEITE::analog::point<x, y>, DETAIL_XIEITE::analog::size<0, h, l>) noexcept {
			return DETAIL_XIEITE::analog::point<(x + y + h + l), 0>();
		}
	};
}

namespace xieite::analog {
	inline constexpr DETAIL_XIEITE::analog::point<0, 0> x;
}

#endif

// http://www.eelis.net/C++/analogliterals.xhtml
