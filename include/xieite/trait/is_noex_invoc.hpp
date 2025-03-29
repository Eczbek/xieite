#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_NOEX_INVOC
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_NOEX_INVOC
#
#	include <type_traits>

namespace DETAIL_XIEITE::is_noex_invoc {
	template<typename, typename>
	constexpr bool impl = false;

	template<typename T, typename Ret, typename... Args>
	constexpr bool impl<T, Ret(Args...)> = std::is_nothrow_invocable_r_v<Ret, T, Args...>;
}

namespace xieite {
	template<typename T, typename Sig = void()>
	concept is_noex_invoc = DETAIL_XIEITE::is_noex_invoc::impl<T, Sig>;
}

#endif
