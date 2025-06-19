#ifndef DETAIL_XIEITE_HEADER_TRAIT_GET_FN_RET
#	define DETAIL_XIEITE_HEADER_TRAIT_GET_FN_RET
#
#	include <type_traits>
#	include "../fn/visitor.hpp"
#	include "../trait/rm_cvref.hpp"

namespace DETAIL_XIEITE::get_fn_ret {
	template<typename T>
	struct impl : decltype(xieite::visitor(
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(*)(Args...) noexcept(noex)>) { return std::type_identity<Ret>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(*)(Args..., ...) noexcept(noex)>) { return std::type_identity<Ret>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args...) noexcept(noex)>) { return std::type_identity<Ret>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args...) const noexcept(noex)>) { return std::type_identity<Ret>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args...) volatile noexcept(noex)>) { return std::type_identity<Ret>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args...) const volatile noexcept(noex)>) { return std::type_identity<Ret>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args...) & noexcept(noex)>) { return std::type_identity<Ret>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args...) const & noexcept(noex)>) { return std::type_identity<Ret>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args...) volatile & noexcept(noex)>) { return std::type_identity<Ret>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args...) const volatile & noexcept(noex)>) { return std::type_identity<Ret>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args...) && noexcept(noex)>) { return std::type_identity<Ret>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args...) const && noexcept(noex)>) { return std::type_identity<Ret>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args...) volatile && noexcept(noex)>) { return std::type_identity<Ret>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args...) const volatile && noexcept(noex)>) { return std::type_identity<Ret>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args..., ...) noexcept(noex)>) { return std::type_identity<Ret>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args..., ...) const noexcept(noex)>) { return std::type_identity<Ret>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args..., ...) volatile noexcept(noex)>) { return std::type_identity<Ret>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args..., ...) const volatile noexcept(noex)>) { return std::type_identity<Ret>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args..., ...) & noexcept(noex)>) { return std::type_identity<Ret>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args..., ...) const & noexcept(noex)>) { return std::type_identity<Ret>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args..., ...) volatile & noexcept(noex)>) { return std::type_identity<Ret>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args..., ...) const volatile & noexcept(noex)>) { return std::type_identity<Ret>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args..., ...) && noexcept(noex)>) { return std::type_identity<Ret>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args..., ...) const && noexcept(noex)>) { return std::type_identity<Ret>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args..., ...) volatile && noexcept(noex)>) { return std::type_identity<Ret>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args..., ...) const volatile && noexcept(noex)>) { return std::type_identity<Ret>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) noexcept(noex)>) { return std::type_identity<Ret>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) const noexcept(noex)>) { return std::type_identity<Ret>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) volatile noexcept(noex)>) { return std::type_identity<Ret>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) const volatile noexcept(noex)>) { return std::type_identity<Ret>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) & noexcept(noex)>) { return std::type_identity<Ret>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) const & noexcept(noex)>) { return std::type_identity<Ret>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) volatile & noexcept(noex)>) { return std::type_identity<Ret>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) const volatile & noexcept(noex)>) { return std::type_identity<Ret>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) && noexcept(noex)>) { return std::type_identity<Ret>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) const && noexcept(noex)>) { return std::type_identity<Ret>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) volatile && noexcept(noex)>) { return std::type_identity<Ret>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) const volatile && noexcept(noex)>) { return std::type_identity<Ret>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) noexcept(noex)>) { return std::type_identity<Ret>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) const noexcept(noex)>) { return std::type_identity<Ret>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) volatile noexcept(noex)>) { return std::type_identity<Ret>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) const volatile noexcept(noex)>) { return std::type_identity<Ret>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) & noexcept(noex)>) { return std::type_identity<Ret>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) const & noexcept(noex)>) { return std::type_identity<Ret>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) volatile & noexcept(noex)>) { return std::type_identity<Ret>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) const volatile & noexcept(noex)>) { return std::type_identity<Ret>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) && noexcept(noex)>) { return std::type_identity<Ret>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) const && noexcept(noex)>) { return std::type_identity<Ret>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) volatile && noexcept(noex)>) { return std::type_identity<Ret>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) const volatile && noexcept(noex)>) { return std::type_identity<Ret>(); }
	)(std::type_identity<xieite::rm_cvref<T>>())) {};
}

namespace xieite {
	template<typename T>
	using get_fn_ret = DETAIL_XIEITE::get_fn_ret::impl<T>::type;
}

#endif
