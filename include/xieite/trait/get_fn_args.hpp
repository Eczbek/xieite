#ifndef DETAIL_XIEITE_HEADER_TRAIT_GET_FN_ARGS
#	define DETAIL_XIEITE_HEADER_TRAIT_GET_FN_ARGS
#
#	include <tuple>
#	include "../meta/wrap_type.hpp"
#	include "../trait/rm_cvref.hpp"

namespace DETAIL_XIEITE::get_fn_args {
	template<typename T>
	struct impl : xieite::wrap_type<T> {};
	
	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(*)(Args...) noexcept(noex)> : xieite::wrap_type<std::tuple<Args...>> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(*)(Args..., ...) noexcept(noex)> : xieite::wrap_type<std::tuple<Args...>> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args...) noexcept(noex)> : xieite::wrap_type<std::tuple<Args...>> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args...) const noexcept(noex)> : xieite::wrap_type<std::tuple<Args...>> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args...) volatile noexcept(noex)> : xieite::wrap_type<std::tuple<Args...>> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args...) const volatile noexcept(noex)> : xieite::wrap_type<std::tuple<Args...>> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args...) & noexcept(noex)> : xieite::wrap_type<std::tuple<Args...>> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args...) const & noexcept(noex)> : xieite::wrap_type<std::tuple<Args...>> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args...) volatile & noexcept(noex)> : xieite::wrap_type<std::tuple<Args...>> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args...) const volatile & noexcept(noex)> : xieite::wrap_type<std::tuple<Args...>> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args...) && noexcept(noex)> : xieite::wrap_type<std::tuple<Args...>> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args...) const && noexcept(noex)> : xieite::wrap_type<std::tuple<Args...>> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args...) volatile && noexcept(noex)> : xieite::wrap_type<std::tuple<Args...>> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args...) const volatile && noexcept(noex)> : xieite::wrap_type<std::tuple<Args...>> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args..., ...) noexcept(noex)> : xieite::wrap_type<std::tuple<Args...>> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args..., ...) const noexcept(noex)> : xieite::wrap_type<std::tuple<Args...>> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args..., ...) volatile noexcept(noex)> : xieite::wrap_type<std::tuple<Args...>> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args..., ...) const volatile noexcept(noex)> : xieite::wrap_type<std::tuple<Args...>> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args..., ...) & noexcept(noex)> : xieite::wrap_type<std::tuple<Args...>> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args..., ...) const & noexcept(noex)> : xieite::wrap_type<std::tuple<Args...>> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args..., ...) volatile & noexcept(noex)> : xieite::wrap_type<std::tuple<Args...>> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args..., ...) const volatile & noexcept(noex)> : xieite::wrap_type<std::tuple<Args...>> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args..., ...) && noexcept(noex)> : xieite::wrap_type<std::tuple<Args...>> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args..., ...) const && noexcept(noex)> : xieite::wrap_type<std::tuple<Args...>> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args..., ...) volatile && noexcept(noex)> : xieite::wrap_type<std::tuple<Args...>> {};

	template<typename Ret, typename... Args, bool noex>
	struct impl<Ret(Args..., ...) const volatile && noexcept(noex)> : xieite::wrap_type<std::tuple<Args...>> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) noexcept(noex)> : xieite::wrap_type<std::tuple<Args...>> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) const noexcept(noex)> : xieite::wrap_type<std::tuple<Args...>> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) volatile noexcept(noex)> : xieite::wrap_type<std::tuple<Args...>> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) const volatile noexcept(noex)> : xieite::wrap_type<std::tuple<Args...>> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) & noexcept(noex)> : xieite::wrap_type<std::tuple<Args...>> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) const & noexcept(noex)> : xieite::wrap_type<std::tuple<Args...>> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) volatile & noexcept(noex)> : xieite::wrap_type<std::tuple<Args...>> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) const volatile & noexcept(noex)> : xieite::wrap_type<std::tuple<Args...>> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) && noexcept(noex)> : xieite::wrap_type<std::tuple<Args...>> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) const && noexcept(noex)> : xieite::wrap_type<std::tuple<Args...>> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) volatile && noexcept(noex)> : xieite::wrap_type<std::tuple<Args...>> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) const volatile && noexcept(noex)> : xieite::wrap_type<std::tuple<Args...>> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) noexcept(noex)> : xieite::wrap_type<std::tuple<Args...>> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) const noexcept(noex)> : xieite::wrap_type<std::tuple<Args...>> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) volatile noexcept(noex)> : xieite::wrap_type<std::tuple<Args...>> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) const volatile noexcept(noex)> : xieite::wrap_type<std::tuple<Args...>> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) & noexcept(noex)> : xieite::wrap_type<std::tuple<Args...>> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) const & noexcept(noex)> : xieite::wrap_type<std::tuple<Args...>> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) volatile & noexcept(noex)> : xieite::wrap_type<std::tuple<Args...>> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) const volatile & noexcept(noex)> : xieite::wrap_type<std::tuple<Args...>> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) && noexcept(noex)> : xieite::wrap_type<std::tuple<Args...>> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) const && noexcept(noex)> : xieite::wrap_type<std::tuple<Args...>> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) volatile && noexcept(noex)> : xieite::wrap_type<std::tuple<Args...>> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) const volatile && noexcept(noex)> : xieite::wrap_type<std::tuple<Args...>> {};
}

namespace xieite {
	template<typename T>
	using get_fn_args = DETAIL_XIEITE::get_fn_args::impl<xieite::rm_cvref<T>>::type;
}

#endif
