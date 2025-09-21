#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_INVOC
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_INVOC
#
#	include <type_traits>
#	include "../meta/wrap_type.hpp"

namespace xieite {
	template<typename T, typename Sig = void()>
	concept is_invoc = ([]<typename Ret, typename... Args>(xieite::wrap_type<Ret(Args...)>) {
		return std::is_invocable_r_v<Ret, T, Args...>;
	})(xieite::wrap_type<Sig>());
}

#endif

// https://cplusplus.github.io/CWG/issues/2988.html
