#ifndef DETAIL_XTE_HEADER_TRAIT_ADD_C
#	define DETAIL_XTE_HEADER_TRAIT_ADD_C
#
#	include "../meta/wrap_type.hpp"

namespace DETAIL_XTE {
	template<typename T>
	struct add_c : xte::wrap_type<const T> {};

	template<typename T>
	struct add_c<T&> : xte::wrap_type<const T&> {};

	template<typename T>
	struct add_c<T&&> : xte::wrap_type<const T&&> {};
}

namespace xte {
	template<typename T>
	using add_c = DETAIL_XTE::add_c<T>::type;
}

#endif

// https://gcc.gnu.org/bugzilla/show_bug.cgi?id=123081
