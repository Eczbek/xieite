#ifndef DETAIL_XTE_HEADER_META_SEQ
#	define DETAIL_XTE_HEADER_META_SEQ
#
#	include "../aliases.hpp"
#	include <tuple>
#	include <utility>

namespace xte {
	template<decltype(auto)... values>
	struct seq {
		template<xte::uz index>
		[[nodiscard]] constexpr decltype(auto) get() const noexcept {
			return values...[index];
		}
	};

	template<xte::uz size>
	constexpr auto make_seq = ([]<xte::uz... i>(std::index_sequence<i...>) {
		return xte::seq<i...>();
	})(std::make_index_sequence<size>());
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
