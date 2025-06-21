#ifndef DETAIL_XIEITE_HEADER_META_TYPE
#	define DETAIL_XIEITE_HEADER_META_TYPE

namespace DETAIL_XIEITE::type {
	template<typename T>
	struct impl {
		using type = T;
	};
}

namespace xieite {
	template<typename T>
	using type = DETAIL_XIEITE::type::impl<T>;
}

#endif
