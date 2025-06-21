#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_LREF_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_LREF_REFERENT
#
#	include "../meta/type.hpp"
#	include "../trait/cp_cvref.hpp"
#	include "../trait/rm_cvref.hpp"

namespace DETAIL_XIEITE::add_lref_referent {
	template<typename T>
	struct impl : xieite::type<T> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args...) noexcept(noex)> : xieite::type<Ret(Args...) & noexcept(noex)> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args...) const noexcept(noex)> : xieite::type<Ret(Args...) const & noexcept(noex)> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args...) volatile noexcept(noex)> : xieite::type<Ret(Args...) volatile & noexcept(noex)> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args...) const volatile noexcept(noex)> : xieite::type<Ret(Args...) const volatile & noexcept(noex)> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args...) && noexcept(noex)> : xieite::type<Ret(Args...) noexcept(noex)> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args...) const && noexcept(noex)> : xieite::type<Ret(Args...) const noexcept(noex)> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args...) volatile && noexcept(noex)> : xieite::type<Ret(Args...) volatile noexcept(noex)> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args...) const volatile && noexcept(noex)> : xieite::type<Ret(Args...) const volatile noexcept(noex)> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args..., ...) noexcept(noex)> : xieite::type<Ret(Args..., ...) & noexcept(noex)> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args..., ...) const noexcept(noex)> : xieite::type<Ret(Args..., ...) const & noexcept(noex)> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args..., ...) volatile noexcept(noex)> : xieite::type<Ret(Args..., ...) volatile & noexcept(noex)> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args..., ...) const volatile noexcept(noex)> : xieite::type<Ret(Args..., ...) const volatile & noexcept(noex)> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args..., ...) && noexcept(noex)> : xieite::type<Ret(Args..., ...) noexcept(noex)> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args..., ...) const && noexcept(noex)> : xieite::type<Ret(Args..., ...) const noexcept(noex)> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args..., ...) volatile && noexcept(noex)> : xieite::type<Ret(Args..., ...) volatile noexcept(noex)> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args..., ...) const volatile && noexcept(noex)> : xieite::type<Ret(Args..., ...) const volatile noexcept(noex)> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) noexcept(noex)> : xieite::type<Ret(S::*)(Args...) & noexcept(noex)> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) const noexcept(noex)> : xieite::type<Ret(S::*)(Args...) const & noexcept(noex)> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) volatile noexcept(noex)> : xieite::type<Ret(S::*)(Args...) volatile & noexcept(noex)> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) const volatile noexcept(noex)> : xieite::type<Ret(S::*)(Args...) const volatile & noexcept(noex)> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) && noexcept(noex)> : xieite::type<Ret(S::*)(Args...) noexcept(noex)> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) const && noexcept(noex)> : xieite::type<Ret(S::*)(Args...) const noexcept(noex)> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) volatile && noexcept(noex)> : xieite::type<Ret(S::*)(Args...) volatile noexcept(noex)> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) const volatile && noexcept(noex)> : xieite::type<Ret(S::*)(Args...) const volatile noexcept(noex)> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) noexcept(noex)> : xieite::type<Ret(S::*)(Args..., ...) & noexcept(noex)> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) const noexcept(noex)> : xieite::type<Ret(S::*)(Args..., ...) const & noexcept(noex)> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) volatile noexcept(noex)> : xieite::type<Ret(S::*)(Args..., ...) volatile & noexcept(noex)> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) const volatile noexcept(noex)> : xieite::type<Ret(S::*)(Args..., ...) const volatile & noexcept(noex)> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) && noexcept(noex)> : xieite::type<Ret(S::*)(Args..., ...) noexcept(noex)> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) const && noexcept(noex)> : xieite::type<Ret(S::*)(Args..., ...) const noexcept(noex)> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) volatile && noexcept(noex)> : xieite::type<Ret(S::*)(Args..., ...) volatile noexcept(noex)> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) const volatile && noexcept(noex)> : xieite::type<Ret(S::*)(Args..., ...) const volatile noexcept(noex)> {};
}

namespace xieite {
	template<typename T>
	using add_lref_referent = xieite::cp_cvref<T, typename DETAIL_XIEITE::add_lref_referent::impl<xieite::rm_cvref<T>>::type>;
}

#endif
