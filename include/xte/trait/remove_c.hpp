#ifndef DETAIL_XTE_HEADER_TRAIT_REMOVE_C
#	define DETAIL_XTE_HEADER_TRAIT_REMOVE_C
#
#	include "../meta/wrap_type.hpp"

namespace DETAIL_XTE {
	template<typename T>
	struct remove_c : xte::wrap_type<T> {};

	template<typename T>
	struct remove_c<const T> : xte::wrap_type<T> {};

	template<typename T>
	struct remove_c<const T&> : xte::wrap_type<T&> {};

	template<typename T>
	struct remove_c<const T&&> : xte::wrap_type<T&&> {};
}

namespace xte {
	template<typename T>
	using remove_c = DETAIL_XTE::remove_c<T>::type;
}

#endif

// https://gcc.gnu.org/bugzilla/show_bug.cgi?id=123237
