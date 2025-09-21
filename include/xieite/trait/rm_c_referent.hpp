#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_C_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_C_REFERENT
#
#	include "../meta/wrap_type.hpp"
#	include "../trait/cp_cvref.hpp"
#	include "../trait/rm_cvref.hpp"

namespace DETAIL_XIEITE::rm_c_referent {
	template<typename T>
	struct impl : xieite::wrap_type<T> {};

	template<typename T>
	struct impl<const T*> : xieite::wrap_type<T*> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args...) const noexcept(noex)> : xieite::wrap_type<Ret(Args...) noexcept(noex)> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args...) const volatile noexcept(noex)> : xieite::wrap_type<Ret(Args...) volatile noexcept(noex)> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args...) const & noexcept(noex)> : xieite::wrap_type<Ret(Args...) & noexcept(noex)> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args...) const volatile & noexcept(noex)> : xieite::wrap_type<Ret(Args...) volatile & noexcept(noex)> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args...) const && noexcept(noex)> : xieite::wrap_type<Ret(Args...) && noexcept(noex)> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args...) const volatile && noexcept(noex)> : xieite::wrap_type<Ret(Args...) volatile && noexcept(noex)> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args..., ...) const noexcept(noex)> : xieite::wrap_type<Ret(Args..., ...) noexcept(noex)> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args..., ...) const volatile noexcept(noex)> : xieite::wrap_type<Ret(Args..., ...) volatile noexcept(noex)> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args..., ...) const & noexcept(noex)> : xieite::wrap_type<Ret(Args..., ...) & noexcept(noex)> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args..., ...) const volatile & noexcept(noex)> : xieite::wrap_type<Ret(Args..., ...) volatile & noexcept(noex)> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args..., ...) const && noexcept(noex)> : xieite::wrap_type<Ret(Args..., ...) && noexcept(noex)> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args..., ...) const volatile && noexcept(noex)> : xieite::wrap_type<Ret(Args..., ...) volatile && noexcept(noex)> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) const noexcept(noex)> : xieite::wrap_type<Ret(S::*)(Args...) noexcept(noex)> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) const volatile noexcept(noex)> : xieite::wrap_type<Ret(S::*)(Args...) volatile noexcept(noex)> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) const & noexcept(noex)> : xieite::wrap_type<Ret(S::*)(Args...) & noexcept(noex)> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) const volatile & noexcept(noex)> : xieite::wrap_type<Ret(S::*)(Args...) volatile & noexcept(noex)> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) const && noexcept(noex)> : xieite::wrap_type<Ret(S::*)(Args...) && noexcept(noex)> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) const volatile && noexcept(noex)> : xieite::wrap_type<Ret(S::*)(Args...) volatile && noexcept(noex)> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) const noexcept(noex)> : xieite::wrap_type<Ret(S::*)(Args..., ...) noexcept(noex)> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) const volatile noexcept(noex)> : xieite::wrap_type<Ret(S::*)(Args..., ...) volatile noexcept(noex)> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) const & noexcept(noex)> : xieite::wrap_type<Ret(S::*)(Args..., ...) & noexcept(noex)> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) const volatile & noexcept(noex)> : xieite::wrap_type<Ret(S::*)(Args..., ...) volatile & noexcept(noex)> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) const && noexcept(noex)> : xieite::wrap_type<Ret(S::*)(Args..., ...) && noexcept(noex)> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) const volatile && noexcept(noex)> : xieite::wrap_type<Ret(S::*)(Args..., ...) volatile && noexcept(noex)> {};
}

namespace xieite {
	template<typename T>
	using rm_c_referent = xieite::cp_cvref<T, typename DETAIL_XIEITE::rm_c_referent::impl<xieite::rm_cvref<T>>::type>;
}

#endif
