#ifndef DETAIL_XTE_HEADER_TRAIT_IS_INVOCABLE
#	define DETAIL_XTE_HEADER_TRAIT_IS_INVOCABLE
#
#	include <type_traits>

namespace DETAIL_XTE {
	template<typename, typename>
	constexpr bool is_invocable = false;

	template<typename Func, typename Return, typename... Args>
	constexpr bool is_invocable<Func, Return(Args...)> = std::is_invocable_r_v<Return, Func, Args...>;
}

namespace xte {
	template<typename Func, typename Signature>
	concept is_invocable = DETAIL_XTE::is_invocable<Func, Signature>;
}

#endif
