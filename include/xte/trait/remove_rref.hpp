#ifndef DETAIL_XTE_HEADER_TRAIT_REMOVE_RREF
#	define DETAIL_XTE_HEADER_TRAIT_REMOVE_RREF
#
#	include "../meta/wrap_type.hpp"

namespace DETAIL_XTE {
	template<typename T>
	struct remove_rref : xte::wrap_type<T> {};

	template<typename T>
	struct remove_rref<T&&> : xte::wrap_type<T> {};
}

namespace xte {
	template<typename T>
	using remove_rref = DETAIL_XTE::remove_rref<T>::type;
}

#endif
