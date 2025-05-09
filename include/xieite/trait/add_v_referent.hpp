#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_V_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_V_REFERENT
#
#	include <type_traits>
#	include "../fn/visitor.hpp"
#	include "../trait/cp_cvref.hpp"
#	include "../trait/rm_cvref.hpp"

namespace DETAIL_XIEITE::add_v_referent {
	template<typename T>
	struct impl : decltype(xieite::visitor(
		[](...) static { return std::type_identity<T>(); },
		[]<typename U>(std::type_identity<U*>) static { return std::type_identity<volatile U*>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) noexcept(noex)>) static { return std::type_identity<Ret(S::*)(Args...) volatile noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) noexcept(noex)>) static { return std::type_identity<Ret(S::*)(Args..., ...) volatile noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) const noexcept(noex)>) static { return std::type_identity<Ret(S::*)(Args...) const volatile noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) const noexcept(noex)>) static { return std::type_identity<Ret(S::*)(Args..., ...) const volatile noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) & noexcept(noex)>) static { return std::type_identity<Ret(S::*)(Args...) volatile & noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) & noexcept(noex)>) static { return std::type_identity<Ret(S::*)(Args..., ...) volatile & noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) const & noexcept(noex)>) static { return std::type_identity<Ret(S::*)(Args...) const volatile & noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) const & noexcept(noex)>) static { return std::type_identity<Ret(S::*)(Args..., ...) const volatile & noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) && noexcept(noex)>) static { return std::type_identity<Ret(S::*)(Args...) volatile && noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) && noexcept(noex)>) static { return std::type_identity<Ret(S::*)(Args..., ...) volatile && noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) const && noexcept(noex)>) static { return std::type_identity<Ret(S::*)(Args...) const volatile && noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) const && noexcept(noex)>) static { return std::type_identity<Ret(S::*)(Args..., ...) const volatile && noexcept(noex)>(); }
	)(std::type_identity<xieite::rm_cvref<T>>())) {};
}

namespace xieite {
	template<typename T>
	using add_v_referent = xieite::cp_cvref<T, typename DETAIL_XIEITE::add_v_referent::impl<T>::type>;
}

#endif
