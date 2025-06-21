#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_NOEX_INVOC
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_NOEX_INVOC
#
#	include <type_traits>
#	include "../meta/type.hpp"

namespace xieite {
	template<typename T, typename Sig = void()>
	concept is_noex_invoc = ([]<typename Ret, typename... Args>(xieite::type<Ret(Args...)>) static {
		return std::is_nothrow_invocable_r_v<Ret, T, Args...>;
	})(xieite::type<Sig>());
}

#endif

// https://cplusplus.github.io/CWG/issues/2988.html
