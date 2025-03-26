#ifndef DETAIL_XIEITE_HEADER_META_VALUE
#	define DETAIL_XIEITE_HEADER_META_VALUE

namespace DETAIL_XIEITE::value {
	template<decltype(auto) x>
	struct impl {
		static constexpr decltype(auto) value = x;
	};
}

namespace xieite {
	template<decltype(auto) x>
	using value = DETAIL_XIEITE::value::impl<x>;
}

#endif
