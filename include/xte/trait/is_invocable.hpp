#ifndef DETAIL_XTE_HEADER_TRAIT_IS_INVOCABLE
#	define DETAIL_XTE_HEADER_TRAIT_IS_INVOCABLE
#
#	include <type_traits>

namespace DETAIL_XTE::is_invocable {
	template<typename, typename>
	constexpr bool impl = false;

	template<typename Func, typename Return, typename... Args>
	constexpr bool impl<Func, Return(Args...)> = std::is_invocable_r_v<Return, Func, Args...>;
}

namespace xte {
	template<typename Func, typename Signature>
	concept is_invocable = DETAIL_XTE::is_invocable::impl<Func, Signature>;
}

#endif
