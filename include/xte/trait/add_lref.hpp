#ifndef DETAIL_XTE_HEADER_TRAIT_ADD_LREF
#	define DETAIL_XTE_HEADER_TRAIT_ADD_LREF
#
#	include "../meta/wrap_type.hpp"
#	include "../trait/is_same_unqual.hpp"

namespace DETAIL_XTE {
	template<typename T>
	struct add_lref : xte::wrap_type<T> {};

	template<typename T>
	requires(not xte::is_same_unqual<T, void>)
	struct add_lref<T> : xte::wrap_type<T&> {};
}

namespace xte {
	template<typename T>
	using add_lref = DETAIL_XTE::add_lref<T>::type;
}

#endif
