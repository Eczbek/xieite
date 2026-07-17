#ifndef DETAIL_XTE_HEADER_META_END
#	define DETAIL_XTE_HEADER_META_END

namespace DETAIL_XTE::end {
	template<typename>
	constexpr bool always_false = false;
}

namespace xte {
	template<typename T>
	concept end = DETAIL_XTE::end::always_false<T>;
}

#endif
