#ifndef DETAIL_XTE_HEADER_TRAIT_REMOVE_V
#	define DETAIL_XTE_HEADER_TRAIT_REMOVE_V
#
#	include "../meta/wrap_type.hpp"

namespace DETAIL_XTE {
	template<typename T> struct remove_v               : xte::wrap_type<T>   {};
	template<typename T> struct remove_v<volatile T>   : xte::wrap_type<T>   {};
	template<typename T> struct remove_v<volatile T&>  : xte::wrap_type<T&>  {};
	template<typename T> struct remove_v<volatile T&&> : xte::wrap_type<T&&> {};
}

namespace xte {
	template<typename T>
	using remove_v = DETAIL_XTE::remove_v<T>::type;
}

#endif
