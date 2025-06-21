#ifndef DETAIL_XIEITE_HEADER_TRAIT_GET_FN_RET
#	define DETAIL_XIEITE_HEADER_TRAIT_GET_FN_RET
#
#	include "../meta/type.hpp"
#	include "../trait/rm_cvref.hpp"

namespace DETAIL_XIEITE::get_fn_ret {
	template<typename T>
	struct impl : xieite::type<T> {};
	
	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(*)(Args...) noexcept(noex)> : xieite::type<Ret> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(*)(Args..., ...) noexcept(noex)> : xieite::type<Ret> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args...) noexcept(noex)> : xieite::type<Ret> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args...) const noexcept(noex)> : xieite::type<Ret> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args...) volatile noexcept(noex)> : xieite::type<Ret> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args...) const volatile noexcept(noex)> : xieite::type<Ret> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args...) & noexcept(noex)> : xieite::type<Ret> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args...) const & noexcept(noex)> : xieite::type<Ret> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args...) volatile & noexcept(noex)> : xieite::type<Ret> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args...) const volatile & noexcept(noex)> : xieite::type<Ret> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args...) && noexcept(noex)> : xieite::type<Ret> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args...) const && noexcept(noex)> : xieite::type<Ret> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args...) volatile && noexcept(noex)> : xieite::type<Ret> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args...) const volatile && noexcept(noex)> : xieite::type<Ret> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args..., ...) noexcept(noex)> : xieite::type<Ret> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args..., ...) const noexcept(noex)> : xieite::type<Ret> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args..., ...) volatile noexcept(noex)> : xieite::type<Ret> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args..., ...) const volatile noexcept(noex)> : xieite::type<Ret> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args..., ...) & noexcept(noex)> : xieite::type<Ret> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args..., ...) const & noexcept(noex)> : xieite::type<Ret> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args..., ...) volatile & noexcept(noex)> : xieite::type<Ret> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args..., ...) const volatile & noexcept(noex)> : xieite::type<Ret> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args..., ...) && noexcept(noex)> : xieite::type<Ret> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args..., ...) const && noexcept(noex)> : xieite::type<Ret> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args..., ...) volatile && noexcept(noex)> : xieite::type<Ret> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args..., ...) const volatile && noexcept(noex)> : xieite::type<Ret> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) noexcept(noex)> : xieite::type<Ret> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) const noexcept(noex)> : xieite::type<Ret> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) volatile noexcept(noex)> : xieite::type<Ret> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) const volatile noexcept(noex)> : xieite::type<Ret> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) & noexcept(noex)> : xieite::type<Ret> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) const & noexcept(noex)> : xieite::type<Ret> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) volatile & noexcept(noex)> : xieite::type<Ret> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) const volatile & noexcept(noex)> : xieite::type<Ret> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) && noexcept(noex)> : xieite::type<Ret> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) const && noexcept(noex)> : xieite::type<Ret> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) volatile && noexcept(noex)> : xieite::type<Ret> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) const volatile && noexcept(noex)> : xieite::type<Ret> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) noexcept(noex)> : xieite::type<Ret> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) const noexcept(noex)> : xieite::type<Ret> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) volatile noexcept(noex)> : xieite::type<Ret> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) const volatile noexcept(noex)> : xieite::type<Ret> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) & noexcept(noex)> : xieite::type<Ret> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) const & noexcept(noex)> : xieite::type<Ret> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) volatile & noexcept(noex)> : xieite::type<Ret> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) const volatile & noexcept(noex)> : xieite::type<Ret> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) && noexcept(noex)> : xieite::type<Ret> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) const && noexcept(noex)> : xieite::type<Ret> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) volatile && noexcept(noex)> : xieite::type<Ret> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) const volatile && noexcept(noex)> : xieite::type<Ret> {};
}

namespace xieite {
	template<typename T>
	using get_fn_ret = DETAIL_XIEITE::get_fn_ret::impl<xieite::rm_cvref<T>>::type;
}

#endif
