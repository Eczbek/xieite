#ifndef DETAIL_XTE_HEADER_META_SEQ
#	define DETAIL_XTE_HEADER_META_SEQ
#
#	include "../util/types.hpp"
#	include <tuple>

namespace xte {
	template<decltype(auto)... xs>
	struct seq {
		template<xte::uz index>
		[[nodiscard]] constexpr decltype(auto) get() const noexcept {
			return xs...[index];
		}
	};
}

template<xte::uz... xs>
struct std::tuple_size<xte::seq<xs...>> {
	static constexpr xte::uz value = sizeof...(xs);
};

template<xte::uz index, decltype(auto)... xs>
struct std::tuple_element<index, xte::seq<xs...>> {
	using type = decltype(xs...[index]);
};

#endif
