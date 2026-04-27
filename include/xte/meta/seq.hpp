#ifndef DETAIL_XTE_HEADER_META_SEQ
#	define DETAIL_XTE_HEADER_META_SEQ
#
#	include "../util/numbers.hpp"
#	include <tuple>

namespace xte {
	template<decltype(auto)... values>
	struct seq {
		template<xte::uz index>
		[[nodiscard]] constexpr decltype(auto) get() const noexcept {
			return values...[index];
		}
	};
}

template<xte::uz... values>
struct std::tuple_size<xte::seq<values...>> {
	static constexpr xte::uz value = sizeof...(values);
};

template<xte::uz index, decltype(auto)... values>
struct std::tuple_element<index, xte::seq<values...>> {
	using type = decltype(values...[index]);
};

#endif
