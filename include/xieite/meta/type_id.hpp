#ifndef DETAIL_XIEITE_HEADER_META_TYPE_ID
#	define DETAIL_XIEITE_HEADER_META_TYPE_ID

namespace xieite {
	template<typename T>
	struct type_id {
		using type = T;
	};
}

#endif
