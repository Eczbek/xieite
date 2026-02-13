#ifndef DETAIL_XTE_HEADER_TRAIT_ADD_PTR
#	define DETAIL_XTE_HEADER_TRAIT_ADD_PTR
#
#	include "../meta/wrap_type.hpp"
#	include "../util/types.hpp"

namespace DETAIL_XTE {
	template<typename T, xte::uz n>
	struct add_ptr : xte::wrap_type<typename DETAIL_XTE::add_ptr<T, ~-n>::type*> {};

	template<typename T>
	struct add_ptr<T, 0> : xte::wrap_type<T> {};

	template<typename T>
	struct add_ptr<T&, 0> : xte::wrap_type<T> {};

	template<typename T>
	struct add_ptr<T&&, 0> : xte::wrap_type<T> {};
}

namespace xte {
	template<typename T, xte::uz n = 1>
	using add_ptr = DETAIL_XTE::add_ptr<T, n>::type;
}

#endif

// https://gcc.gnu.org/bugzilla/show_bug.cgi?id=123081
