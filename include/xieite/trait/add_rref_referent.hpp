#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_RREF_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_RREF_REFERENT
#
#	include <type_traits>
#	include "../fn/visitor.hpp"
#	include "../trait/cp_cvref.hpp"
#	include "../trait/rm_cvref.hpp"

namespace DETAIL_XIEITE::add_rref_referent {
	template<typename T>
	struct impl : decltype(xieite::visitor(
		[](...) { return std::type_identity<T>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args...) noexcept(noex)>) { return std::type_identity<Ret(Args...) && noexcept(noex)>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args...) const noexcept(noex)>) { return std::type_identity<Ret(Args...) const && noexcept(noex)>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args...) volatile noexcept(noex)>) { return std::type_identity<Ret(Args...) volatile && noexcept(noex)>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args...) const volatile noexcept(noex)>) { return std::type_identity<Ret(Args...) const volatile && noexcept(noex)>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args...) & noexcept(noex)>) { return std::type_identity<Ret(Args...) noexcept(noex)>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args...) const & noexcept(noex)>) { return std::type_identity<Ret(Args...) const noexcept(noex)>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args...) volatile & noexcept(noex)>) { return std::type_identity<Ret(Args...) volatile noexcept(noex)>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args...) const volatile & noexcept(noex)>) { return std::type_identity<Ret(Args...) const volatile noexcept(noex)>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args..., ...) noexcept(noex)>) { return std::type_identity<Ret(Args..., ...) && noexcept(noex)>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args..., ...) const noexcept(noex)>) { return std::type_identity<Ret(Args..., ...) const && noexcept(noex)>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args..., ...) volatile noexcept(noex)>) { return std::type_identity<Ret(Args..., ...) volatile && noexcept(noex)>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args..., ...) const volatile noexcept(noex)>) { return std::type_identity<Ret(Args..., ...) const volatile && noexcept(noex)>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args..., ...) & noexcept(noex)>) { return std::type_identity<Ret(Args..., ...) noexcept(noex)>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args..., ...) const & noexcept(noex)>) { return std::type_identity<Ret(Args..., ...) const noexcept(noex)>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args..., ...) volatile & noexcept(noex)>) { return std::type_identity<Ret(Args..., ...) volatile noexcept(noex)>(); },
		[]<typename Ret, typename... Args, bool noex>(std::type_identity<Ret(Args..., ...) const volatile & noexcept(noex)>) { return std::type_identity<Ret(Args..., ...) const volatile noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) noexcept(noex)>) { return std::type_identity<Ret(S::*)(Args...) && noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) const noexcept(noex)>) { return std::type_identity<Ret(S::*)(Args...) const && noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) volatile noexcept(noex)>) { return std::type_identity<Ret(S::*)(Args...) volatile && noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) const volatile noexcept(noex)>) { return std::type_identity<Ret(S::*)(Args...) const volatile && noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) & noexcept(noex)>) { return std::type_identity<Ret(S::*)(Args...) noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) const & noexcept(noex)>) { return std::type_identity<Ret(S::*)(Args...) const noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) volatile & noexcept(noex)>) { return std::type_identity<Ret(S::*)(Args...) volatile noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args...) const volatile & noexcept(noex)>) { return std::type_identity<Ret(S::*)(Args...) const volatile noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) noexcept(noex)>) { return std::type_identity<Ret(S::*)(Args..., ...) && noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) const noexcept(noex)>) { return std::type_identity<Ret(S::*)(Args..., ...) const && noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) volatile noexcept(noex)>) { return std::type_identity<Ret(S::*)(Args..., ...) volatile && noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) const volatile noexcept(noex)>) { return std::type_identity<Ret(S::*)(Args..., ...) const volatile && noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) & noexcept(noex)>) { return std::type_identity<Ret(S::*)(Args..., ...) noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) const & noexcept(noex)>) { return std::type_identity<Ret(S::*)(Args..., ...) const noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) volatile & noexcept(noex)>) { return std::type_identity<Ret(S::*)(Args..., ...) volatile noexcept(noex)>(); },
		[]<typename Ret, typename S, typename... Args, bool noex>(std::type_identity<Ret(S::*)(Args..., ...) const volatile & noexcept(noex)>) { return std::type_identity<Ret(S::*)(Args..., ...) const volatile noexcept(noex)>(); }
	)(std::type_identity<xieite::rm_cvref<T>>())) {};
}

namespace xieite {
	template<typename T>
	using add_rref_referent = xieite::cp_cvref<T, typename DETAIL_XIEITE::add_rref_referent::impl<T>::type>;
}

#endif
