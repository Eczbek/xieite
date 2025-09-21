#ifndef DETAIL_XIEITE_HEADER_META_FOLD_FOR
#	define DETAIL_XIEITE_HEADER_META_FOLD_FOR
#
#	include <cstddef>
#	include "../fn/unroll.hpp"
#	include "../meta/fold.hpp"
#	include "../meta/wrap_type.hpp"
#	include "../meta/wrap_value.hpp"

namespace DETAIL_XIEITE::fold_for {
	template<auto fn, typename T>
	constexpr auto impl = []<std::size_t... i> {
		return xieite::fold<
			[]<typename Prev, typename Idx> { return xieite::wrap_type<decltype(fn.template operator()<typename Prev::type, Idx::value>())>(); },
			xieite::wrap_type<T>,
			xieite::wrap_value<i>...
		>();
	};
}

namespace xieite {
	template<auto fn, typename T, std::size_t count>
	using fold_for = decltype(xieite::unroll<count>(DETAIL_XIEITE::fold_for::impl<fn, T>))::type;
}

#endif
