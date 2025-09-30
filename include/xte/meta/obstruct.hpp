#ifndef DETAIL_XTE_HEADER_META_OBSTRUCT
#	define DETAIL_XTE_HEADER_META_OBSTRUCT
#
#	include "../meta/wrap_type.hpp"

namespace xte {
	template<typename T>
	using obstruct = xte::wrap_type<T>::type;
}

#endif
