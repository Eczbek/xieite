#ifndef DETAIL_XIEITE_HEADER_TRAIT_GET_FN_ARGS
#	define DETAIL_XIEITE_HEADER_TRAIT_GET_FN_ARGS
#
#	include <tuple>
#	include <type_traits>
#	include "../fn/visitor.hpp"
#	include "../trait/rm_cvref.hpp"

namespace DETAIL_XIEITE::get_fn_args {
	template<typename T>
	struct impl : decltype(xieite::visitor(
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(*)(Args...) noexcept(noex)>) { return std::type_identity<std::tuple<Args...>>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(*)(Args..., ...) noexcept(noex)>) { return std::type_identity<std::tuple<Args...>>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args...) noexcept(noex)>) { return std::type_identity<std::tuple<Args...>>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args...) const noexcept(noex)>) { return std::type_identity<std::tuple<Args...>>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args...) volatile noexcept(noex)>) { return std::type_identity<std::tuple<Args...>>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args...) const volatile noexcept(noex)>) { return std::type_identity<std::tuple<Args...>>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args...) & noexcept(noex)>) { return std::type_identity<std::tuple<Args...>>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args...) const & noexcept(noex)>) { return std::type_identity<std::tuple<Args...>>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args...) volatile & noexcept(noex)>) { return std::type_identity<std::tuple<Args...>>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args...) const volatile & noexcept(noex)>) { return std::type_identity<std::tuple<Args...>>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args...) && noexcept(noex)>) { return std::type_identity<std::tuple<Args...>>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args...) const && noexcept(noex)>) { return std::type_identity<std::tuple<Args...>>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args...) volatile && noexcept(noex)>) { return std::type_identity<std::tuple<Args...>>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args...) const volatile && noexcept(noex)>) { return std::type_identity<std::tuple<Args...>>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args..., ...) noexcept(noex)>) { return std::type_identity<std::tuple<Args...>>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args..., ...) const noexcept(noex)>) { return std::type_identity<std::tuple<Args...>>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args..., ...) volatile noexcept(noex)>) { return std::type_identity<std::tuple<Args...>>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args..., ...) const volatile noexcept(noex)>) { return std::type_identity<std::tuple<Args...>>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args..., ...) & noexcept(noex)>) { return std::type_identity<std::tuple<Args...>>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args..., ...) const & noexcept(noex)>) { return std::type_identity<std::tuple<Args...>>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args..., ...) volatile & noexcept(noex)>) { return std::type_identity<std::tuple<Args...>>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args..., ...) const volatile & noexcept(noex)>) { return std::type_identity<std::tuple<Args...>>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args..., ...) && noexcept(noex)>) { return std::type_identity<std::tuple<Args...>>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args..., ...) const && noexcept(noex)>) { return std::type_identity<std::tuple<Args...>>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args..., ...) volatile && noexcept(noex)>) { return std::type_identity<std::tuple<Args...>>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args..., ...) const volatile && noexcept(noex)>) { return std::type_identity<std::tuple<Args...>>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) noexcept(noex)>) { return std::type_identity<std::tuple<Args...>>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) const noexcept(noex)>) { return std::type_identity<std::tuple<Args...>>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) volatile noexcept(noex)>) { return std::type_identity<std::tuple<Args...>>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) const volatile noexcept(noex)>) { return std::type_identity<std::tuple<Args...>>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) & noexcept(noex)>) { return std::type_identity<std::tuple<Args...>>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) const & noexcept(noex)>) { return std::type_identity<std::tuple<Args...>>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) volatile & noexcept(noex)>) { return std::type_identity<std::tuple<Args...>>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) const volatile & noexcept(noex)>) { return std::type_identity<std::tuple<Args...>>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) && noexcept(noex)>) { return std::type_identity<std::tuple<Args...>>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) const && noexcept(noex)>) { return std::type_identity<std::tuple<Args...>>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) volatile && noexcept(noex)>) { return std::type_identity<std::tuple<Args...>>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) const volatile && noexcept(noex)>) { return std::type_identity<std::tuple<Args...>>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) noexcept(noex)>) { return std::type_identity<std::tuple<Args...>>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) const noexcept(noex)>) { return std::type_identity<std::tuple<Args...>>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) volatile noexcept(noex)>) { return std::type_identity<std::tuple<Args...>>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) const volatile noexcept(noex)>) { return std::type_identity<std::tuple<Args...>>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) & noexcept(noex)>) { return std::type_identity<std::tuple<Args...>>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) const & noexcept(noex)>) { return std::type_identity<std::tuple<Args...>>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) volatile & noexcept(noex)>) { return std::type_identity<std::tuple<Args...>>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) const volatile & noexcept(noex)>) { return std::type_identity<std::tuple<Args...>>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) && noexcept(noex)>) { return std::type_identity<std::tuple<Args...>>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) const && noexcept(noex)>) { return std::type_identity<std::tuple<Args...>>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) volatile && noexcept(noex)>) { return std::type_identity<std::tuple<Args...>>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) const volatile && noexcept(noex)>) { return std::type_identity<std::tuple<Args...>>(); }
	)(std::type_identity<xieite::rm_cvref<T>>())) {};
}

namespace xieite {
	template<typename T>
	using get_fn_args = DETAIL_XIEITE::get_fn_args::impl<T>::type;
}

#endif
