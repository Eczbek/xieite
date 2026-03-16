#ifndef DETAIL_XTE_HEADER_TRAIT_REMOVE_PTR
#	define DETAIL_XTE_HEADER_TRAIT_REMOVE_PTR
#
#	include "../meta/wrap_type.hpp"
#	include "../util/types.hpp"

namespace DETAIL_XTE {
	template<typename T, xte::uz>
	struct remove_ptr : xte::wrap_type<T> {};

	template<typename T, xte::uz n>
	requires(n > 0)
	struct remove_ptr<T*, n> : DETAIL_XTE::remove_ptr<T, ~-n> {};

	template<typename T, xte::uz n>
	requires(n > 0)
	struct remove_ptr<T*&, n> : DETAIL_XTE::remove_ptr<T, ~-n> {};

	template<typename T, xte::uz n>
	requires(n > 0)
	struct remove_ptr<T*&&, n> : DETAIL_XTE::remove_ptr<T, ~-n> {};
}

namespace xte {
	template<typename T, xte::uz n = 1>
	using remove_ptr = DETAIL_XtE::remove_ptr<T, n>::type;
}

#endif

// https://gcc.gnu.org/bugzilla/show_bug.cgi?id=123237
