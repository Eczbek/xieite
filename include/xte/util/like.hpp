#ifndef DETAIL_XTE_HEADER_UTIL_LIKE
#	define DETAIL_XTE_HEADER_UTIL_LIKE
#
#	include "../func/noop.hpp"
#	include "../trait/is_const.hpp"
#	include "../trait/is_lvalue_ref.hpp"
#	include "../trait/is_volatile.hpp"
#	include "../util/as_const.hpp"
#	include "../util/as_volatile.hpp"
#	include "../util/as_xvalue.hpp"

namespace xte {
	template<typename T>
	constexpr auto like = [][[nodiscard]](auto&& x) static noexcept -> auto&& {
		return [:xte::is_volatile<T> ? ^^xte::as_volatile : ^^xte::noop:]([:xte::is_const<T> ? ^^xte::as_const : ^^xte::noop:]([:xte::is_lvalue_ref<T> ? ^^xte::noop : ^^xte::as_xvalue:](x)));
	};
}

#endif
