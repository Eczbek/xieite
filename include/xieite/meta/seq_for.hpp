#ifndef DETAIL_XIEITE_HEADER_META_SEQ_FOR
#	define DETAIL_XIEITE_HEADER_META_SEQ_FOR
#
#	include "../meta/make_seq.hpp"

namespace xieite {
	template<typename... Ts>
	constexpr auto seq_for = xieite::make_seq<sizeof...(Ts)>;
}

#endif
