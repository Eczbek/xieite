#ifndef DETAIL_XTE_HEADER_META_VALUE
#	define DETAIL_XTE_HEADER_META_VALUE

namespace xte {
	template<decltype(auto) x>
	constexpr decltype(auto) value = x;
}

#endif
