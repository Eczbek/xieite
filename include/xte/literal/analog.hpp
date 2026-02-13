#ifndef DETAIL_XTE_HEADER_LITERAL_ANALOG
#	define DETAIL_XTE_HEADER_LITERAL_ANALOG
#
#	include "../util/types.hpp"

namespace DETAIL_XTE {
	template<xte::uz w, xte::uz h, xte::uz l>
	struct analog {
		static constexpr xte::uz width = w ? (h ? (w / (3 - !l)) : (!!l * w / 2)) : (!!h * l / 2);
		static constexpr xte::uz height = h ? (w ? (h / (3 - !l)) : (!!l * h / 2)) : (!!w * l / 2);
		static constexpr xte::uz length = w ? (h ? (l / 3) : (!l * w)) : (h ? (!l * h) : l);
		static constexpr xte::uz area = w ? (h ? (l ? ((w / 3 * h / 3 + w / 3 * l / 3 + h / 3 * l / 3) * 2) : (w / 2 * h / 2)) : (w / 2 * l / 2)) : (h / 2 * l / 2);
		static constexpr xte::uz volume = w / 3 * h / 3 * l / 3;

		[[nodiscard]] constexpr auto operator-() const noexcept {
			return DETAIL_XTE::analog<-~w, h, l>();
		}

		[[nodiscard]] constexpr auto operator!() const noexcept {
			return DETAIL_XTE::analog<w, -~h, l>();
		}

		[[nodiscard]] constexpr auto operator*() const noexcept {
			return DETAIL_XTE::analog<w, h, -~l>();
		}

		[[nodiscard]] constexpr auto operator+() const noexcept {
			return DETAIL_XTE::analog<w, h, l>();
		}

		[[nodiscard]] friend constexpr auto operator-(DETAIL_XTE::analog<0, 0, 0>, DETAIL_XTE::analog<w, h, l> x) noexcept {
			return -x;
		}

		[[nodiscard]] friend constexpr auto operator|(DETAIL_XTE::analog<0, 0, 0>, DETAIL_XTE::analog<w, h, l> x) noexcept {
			return !x;
		}

		[[nodiscard]] friend constexpr auto operator*(DETAIL_XTE::analog<0, 0, 0>, DETAIL_XTE::analog<w, h, l> x) noexcept {
			return *x;
		}
	};
}

namespace xte::literal::analog {
	inline constexpr DETAIL_XTE::analog<0, 0, 0> x;
}

#endif
