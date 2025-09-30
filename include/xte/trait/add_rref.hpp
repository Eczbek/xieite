#ifndef DETAIL_XTE_HEADER_TRAIT_ADD_RREF
#	define DETAIL_XTE_HEADER_TRAIT_ADD_RREF
#
#	include "../meta/wrap_type.hpp"
#	include "../trait/is_same_unqual.hpp"

namespace DETAIL_XTE {
	template<typename T>
	struct add_rref : xte::wrap_type<T> {};

	template<typename T>
	requires(not xte::is_same_unqual<T, void>)
	struct add_rref<T> : xte::wrap_type<T&&> {};
}

namespace xte {
	template<typename T>
	using add_rref = DETAIL_XTE::add_rref<T>::type;
}

#endif
