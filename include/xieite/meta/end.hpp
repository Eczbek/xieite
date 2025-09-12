#ifndef DETAIL_XIEITE_HEADER_META_END
#	define DETAIL_XIEITE_HEADER_META_END
#
#	include <concepts>

namespace DETAIL_XIEITE::end {
	struct impl {};
}

namespace xieite {
	template<typename T>
	concept end = std::same_as<T, DETAIL_XIEITE::end::impl>;
}

#endif
