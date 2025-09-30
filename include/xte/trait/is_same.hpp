#ifndef DETAIL_XTE_HEADER_TRAIT_IS_SAME
#	define DETAIL_XTE_HEADER_TRAIT_IS_SAME
#
#	include "../meta/type.hpp"
#	include "../meta/wrap_type.hpp"

namespace xte {
	template<typename T, typename... Us>
	concept is_same = (... && requires (xte::type<int(xte::wrap_type<T>)>& f) {
		f(xte::wrap_type<Us>());
	});
}

#endif
