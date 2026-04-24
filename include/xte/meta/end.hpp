#ifndef DETAIL_XTE_HEADER_META_END
#	define DETAIL_XTE_HEADER_META_END

namespace DETAIL_XTE {
	template<typename>
	constexpr bool end = false;
}

namespace xte {
	template<typename T>
	concept end = DETAIL_XTE::end<T>;
}

#endif
