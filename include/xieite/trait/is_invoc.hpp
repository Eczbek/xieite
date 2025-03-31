#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_INVOC
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_INVOC
#
#	include <type_traits>

namespace xieite {
	template<typename T, typename Sig = void()>
	concept is_invoc = ([]<typename Ret, typename... Args>(std::type_identity<Ret(Args...)>) static {
		return std::is_invocable_r_v<Ret, T, Args...>;
	})(std::type_identity<Sig>());
}

#endif

// https://cplusplus.github.io/CWG/issues/2988.html
