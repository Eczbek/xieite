#ifndef DETAIL_XTE_HEADER_META_SAD
#	define DETAIL_XTE_HEADER_META_SAD

namespace DETAIL_XTE {
	template<typename>
	constexpr bool sad = false;
}

namespace xte {
	template<typename T>
	concept sad = DETAIL_XTE::sad<T>;
}

#endif
