#ifndef DETAIL_XTE_HEADER_META_WRAP_TYPE
#	define DETAIL_XTE_HEADER_META_WRAP_TYPE

namespace xte {
	template<typename T>
	struct wrap_type {
		using type = T;
	};
}

#endif
