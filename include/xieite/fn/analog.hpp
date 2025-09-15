#ifndef DETAIL_XIEITE_HEADER_FN_ANALOG
#	define DETAIL_XIEITE_HEADER_FN_ANALOG
#
#	include <cstddef>

namespace DETAIL_XIEITE::analog {
	template<std::size_t w, std::size_t h, std::size_t l>
	struct impl {
		static constexpr std::size_t width = w ? (h ? (w / (3 - !l)) : (!!l * w / 2)) : (!!h * l / 2);
		static constexpr std::size_t height = h ? (w ? (h / (3 - !l)) : (!!l * h / 2)) : (!!w * l / 2);
		static constexpr std::size_t length = w ? (h ? (l / 3) : (!l * w)) : (h ? (!l * h) : l);
		static constexpr std::size_t area = w ? (h ? (l ? ((w / 3 * h / 3 + w / 3 * l / 3 + h / 3 * l / 3) * 2) : (w / 2 * h / 2)) : (w / 2 * l / 2)) : (h / 2 * l / 2);
		static constexpr std::size_t volume = w / 3 * h / 3 * l / 3;

		[[nodiscard]] constexpr auto operator-() const noexcept {
			return DETAIL_XIEITE::analog::impl<(w + 1), h, l>();
		}

		[[nodiscard]] constexpr auto operator!() const noexcept {
			return DETAIL_XIEITE::analog::impl<w, (h + 1), l>();
		}

		[[nodiscard]] constexpr auto operator*() const noexcept {
			return DETAIL_XIEITE::analog::impl<w, h, (l + 1)>();
		}

		[[nodiscard]] constexpr auto operator+() const noexcept {
			return DETAIL_XIEITE::analog::impl<w, h, l>();
		}

		[[nodiscard]] friend constexpr auto operator-(DETAIL_XIEITE::analog::impl<0, 0, 0>, DETAIL_XIEITE::analog::impl<w, h, l> x) noexcept {
			return -x;
		}

		[[nodiscard]] friend constexpr auto operator|(DETAIL_XIEITE::analog::impl<0, 0, 0>, DETAIL_XIEITE::analog::impl<w, h, l> x) noexcept {
			return !x;
		}

		[[nodiscard]] friend constexpr auto operator*(DETAIL_XIEITE::analog::impl<0, 0, 0>, DETAIL_XIEITE::analog::impl<w, h, l> x) noexcept {
			return *x;
		}
	};
}

namespace xieite::analog {
	inline constexpr DETAIL_XIEITE::analog::impl<0, 0, 0> x;
}

#endif

// http://www.eelis.net/C++/analogliterals.xhtml
