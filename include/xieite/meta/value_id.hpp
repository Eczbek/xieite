#ifndef DETAIL_XIEITE_HEADER_META_VALUE
#	define DETAIL_XIEITE_HEADER_META_VALUE

namespace xieite {
	template<decltype(auto) x>
	struct value_id {
		static constexpr decltype(auto) value = x;
	};
}

#endif
