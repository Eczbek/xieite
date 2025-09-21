#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_V_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_V_REFERENT
#
#	include "../meta/wrap_type.hpp"
#	include "../trait/cp_cvref.hpp"
#	include "../trait/rm_cvref.hpp"

namespace DETAIL_XIEITE::rm_v_referent {
	template<typename T>
	struct impl : xieite::wrap_type<T> {};

	template<typename T>
	struct impl<volatile T*> : xieite::wrap_type<T*> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args...) volatile noexcept(noex)> : xieite::wrap_type<Ret(Args...) noexcept(noex)> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args...) const volatile noexcept(noex)> : xieite::wrap_type<Ret(Args...) const noexcept(noex)> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args...) volatile & noexcept(noex)> : xieite::wrap_type<Ret(Args...) & noexcept(noex)> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args...) const volatile & noexcept(noex)> : xieite::wrap_type<Ret(Args...) const & noexcept(noex)> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args...) volatile && noexcept(noex)> : xieite::wrap_type<Ret(Args...) && noexcept(noex)> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args...) const volatile && noexcept(noex)> : xieite::wrap_type<Ret(Args...) const && noexcept(noex)> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args..., ...) volatile noexcept(noex)> : xieite::wrap_type<Ret(Args..., ...) noexcept(noex)> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args..., ...) const volatile noexcept(noex)> : xieite::wrap_type<Ret(Args..., ...) const noexcept(noex)> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args..., ...) volatile & noexcept(noex)> : xieite::wrap_type<Ret(Args..., ...) & noexcept(noex)> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args..., ...) const volatile & noexcept(noex)> : xieite::wrap_type<Ret(Args..., ...) const & noexcept(noex)> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args..., ...) volatile && noexcept(noex)> : xieite::wrap_type<Ret(Args..., ...) && noexcept(noex)> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args..., ...) const volatile && noexcept(noex)> : xieite::wrap_type<Ret(Args..., ...) const && noexcept(noex)> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) volatile noexcept(noex)> : xieite::wrap_type<Ret(S::*)(Args...) noexcept(noex)> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) const volatile noexcept(noex)> : xieite::wrap_type<Ret(S::*)(Args...) const noexcept(noex)> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) volatile & noexcept(noex)> : xieite::wrap_type<Ret(S::*)(Args...) & noexcept(noex)> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) const volatile & noexcept(noex)> : xieite::wrap_type<Ret(S::*)(Args...) const & noexcept(noex)> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) volatile && noexcept(noex)> : xieite::wrap_type<Ret(S::*)(Args...) && noexcept(noex)> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) const volatile && noexcept(noex)> : xieite::wrap_type<Ret(S::*)(Args...) const && noexcept(noex)> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) volatile noexcept(noex)> : xieite::wrap_type<Ret(S::*)(Args..., ...) noexcept(noex)> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) const volatile noexcept(noex)> : xieite::wrap_type<Ret(S::*)(Args..., ...) const noexcept(noex)> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) volatile & noexcept(noex)> : xieite::wrap_type<Ret(S::*)(Args..., ...) & noexcept(noex)> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) const volatile & noexcept(noex)> : xieite::wrap_type<Ret(S::*)(Args..., ...) const & noexcept(noex)> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) volatile && noexcept(noex)> : xieite::wrap_type<Ret(S::*)(Args..., ...) && noexcept(noex)> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) const volatile && noexcept(noex)> : xieite::wrap_type<Ret(S::*)(Args..., ...) const && noexcept(noex)> {};
}

namespace xieite {
	template<typename T>
	using rm_v_referent = xieite::cp_cvref<T, typename DETAIL_XIEITE::rm_v_referent::impl<xieite::rm_cvref<T>>::type>;
}

#endif
