#ifndef DETAIL_XTE_HEADER_TRAIT_REMOVE_LREF
#	define DETAIL_XTE_HEADER_TRAIT_REMOVE_LREF
#
#	include "../meta/wrap_type.hpp"

namespace DETAIL_XTE {
	template<typename T>
	struct remove_lref : xte::wrap_type<T> {};

	template<typename T>
	struct remove_lref<T&> : xte::wrap_type<T> {};
}

namespace xte {
	template<typename T>
	using remove_lref = DETAIL_XTE::remove_lref<T>::type;
}

#endif
