#ifndef DETAIL_XTE_HEADER_TRAIT_ADD_V
#	define DETAIL_XTE_HEADER_TRAIT_ADD_V
#
#	include "../meta/wrap_type.hpp"

namespace DETAIL_XTE {
	template<typename T>
	struct add_v : xte::wrap_type<volatile T> {};

	template<typename T>
	struct add_v<T&> : xte::wrap_type<volatile T&> {};

	template<typename T>
	struct add_v<T&&> : xte::wrap_type<volatile T&&> {};
}

namespace xte {
	template<typename T>
	using add_v = DETAIL_XTE::add_v<T>::type;
}

#endif

// https://gcc.gnu.org/bugzilla/show_bug.cgi?id=123081
