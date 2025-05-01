#ifndef DETAIL_XIEITE_HEADER_META_FOLD_FOR
#	define DETAIL_XIEITE_HEADER_META_FOLD_FOR
#
#	include <cstddef>
#	include <type_traits>
#	include "../fn/unroll.hpp"
#	include "../meta/fold.hpp"
#	include "../meta/value.hpp"

namespace DETAIL_XIEITE::fold_for {
	template<auto fn, typename T>
	constexpr auto impl = []<std::size_t... i> static {
		return xieite::fold<
			[]<typename Prev, typename Idx> static {
				return std::type_identity<decltype(fn.template operator()<typename Prev::type, Idx::value>())>();
			},
			std::type_identity<T>,
			xieite::value<i>...
		>();
	};
}

namespace xieite {
	template<auto fn, typename T, std::size_t count>
	using fold_for = decltype(xieite::unroll<count>(DETAIL_XIEITE::fold_for::impl<fn, T>))::type;
}

#endif
