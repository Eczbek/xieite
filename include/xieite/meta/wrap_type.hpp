#ifndef DETAIL_XIEITE_HEADER_META_WRAP_TYPE
#	define DETAIL_XIEITE_HEADER_META_WRAP_TYPE

namespace xieite {
	template<typename T>
	struct wrap_type {
		using type = T;
	};
}

#endif
