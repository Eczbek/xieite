#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_V_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_V_REFERENT
#
#	include "../meta/wrap_type.hpp"
#	include "../trait/cp_cvref.hpp"
#	include "../trait/rm_cvref.hpp"

namespace DETAIL_XIEITE::add_v_referent {
	template<typename T>
	struct impl : xieite::wrap_type<T> {};

	template<typename T>
	struct impl<T*> : xieite::wrap_type<const T*> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args...) noexcept(noex)> : xieite::wrap_type<Ret(Args...) volatile noexcept(noex)> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args...) const noexcept(noex)> : xieite::wrap_type<Ret(Args...) const volatile noexcept(noex)> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args...) & noexcept(noex)> : xieite::wrap_type<Ret(Args...) volatile & noexcept(noex)> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args...) const & noexcept(noex)> : xieite::wrap_type<Ret(Args...) const volatile & noexcept(noex)> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args...) && noexcept(noex)> : xieite::wrap_type<Ret(Args...) volatile && noexcept(noex)> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args...) const && noexcept(noex)> : xieite::wrap_type<Ret(Args...) const volatile && noexcept(noex)> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args..., ...) noexcept(noex)> : xieite::wrap_type<Ret(Args..., ...) volatile noexcept(noex)> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args..., ...) const noexcept(noex)> : xieite::wrap_type<Ret(Args..., ...) const volatile noexcept(noex)> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args..., ...) & noexcept(noex)> : xieite::wrap_type<Ret(Args..., ...) volatile & noexcept(noex)> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args..., ...) const & noexcept(noex)> : xieite::wrap_type<Ret(Args..., ...) const volatile & noexcept(noex)> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args..., ...) && noexcept(noex)> : xieite::wrap_type<Ret(Args..., ...) volatile && noexcept(noex)> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args..., ...) const && noexcept(noex)> : xieite::wrap_type<Ret(Args..., ...) const volatile && noexcept(noex)> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) noexcept(noex)> : xieite::wrap_type<Ret(S::*)(Args...) volatile noexcept(noex)> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) const noexcept(noex)> : xieite::wrap_type<Ret(S::*)(Args...) const volatile noexcept(noex)> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) & noexcept(noex)> : xieite::wrap_type<Ret(S::*)(Args...) volatile & noexcept(noex)> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) const & noexcept(noex)> : xieite::wrap_type<Ret(S::*)(Args...) const volatile & noexcept(noex)> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) && noexcept(noex)> : xieite::wrap_type<Ret(S::*)(Args...) volatile && noexcept(noex)> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) const && noexcept(noex)> : xieite::wrap_type<Ret(S::*)(Args...) const volatile && noexcept(noex)> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) noexcept(noex)> : xieite::wrap_type<Ret(S::*)(Args..., ...) volatile noexcept(noex)> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) const noexcept(noex)> : xieite::wrap_type<Ret(S::*)(Args..., ...) const volatile noexcept(noex)> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) & noexcept(noex)> : xieite::wrap_type<Ret(S::*)(Args..., ...) volatile & noexcept(noex)> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) const & noexcept(noex)> : xieite::wrap_type<Ret(S::*)(Args..., ...) const volatile & noexcept(noex)> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) && noexcept(noex)> : xieite::wrap_type<Ret(S::*)(Args..., ...) volatile && noexcept(noex)> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) const && noexcept(noex)> : xieite::wrap_type<Ret(S::*)(Args..., ...) const volatile && noexcept(noex)> {};
}

namespace xieite {
	template<typename T>
	using add_v_referent = xieite::cp_cvref<T, typename DETAIL_XIEITE::add_v_referent::impl<xieite::rm_cvref<T>>::type>;
}

#endif
