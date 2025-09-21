#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_NOEX_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_NOEX_REFERENT
#
#	include "../meta/wrap_type.hpp"
#	include "../trait/cp_cvref.hpp"
#	include "../trait/rm_cvref.hpp"

namespace DETAIL_XIEITE::add_noex_referent {
	template<typename T>
	struct impl : xieite::wrap_type<T> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(*)(Args...)> : xieite::wrap_type<Ret(*)(Args...) noexcept> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(*)(Args..., ...)> : xieite::wrap_type<Ret(*)(Args..., ...) noexcept> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args...)> : xieite::wrap_type<Ret(Args...) noexcept> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args...) const> : xieite::wrap_type<Ret(Args...) const noexcept> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args...) volatile> : xieite::wrap_type<Ret(Args...) volatile noexcept> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args...) const volatile> : xieite::wrap_type<Ret(Args...) const volatile noexcept> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args...) &> : xieite::wrap_type<Ret(Args...) & noexcept> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args...) const &> : xieite::wrap_type<Ret(Args...) const & noexcept> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args...) volatile &> : xieite::wrap_type<Ret(Args...) volatile & noexcept> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args...) const volatile &> : xieite::wrap_type<Ret(Args...) const volatile & noexcept> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args...) &&> : xieite::wrap_type<Ret(Args...) && noexcept> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args...) const &&> : xieite::wrap_type<Ret(Args...) const && noexcept> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args...) volatile &&> : xieite::wrap_type<Ret(Args...) volatile && noexcept> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args...) const volatile &&> : xieite::wrap_type<Ret(Args...) const volatile && noexcept> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args..., ...)> : xieite::wrap_type<Ret(Args..., ...) noexcept> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args..., ...) const> : xieite::wrap_type<Ret(Args..., ...) const noexcept> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args..., ...) volatile> : xieite::wrap_type<Ret(Args..., ...) volatile noexcept> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args..., ...) const volatile> : xieite::wrap_type<Ret(Args..., ...) const volatile noexcept> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args..., ...) &> : xieite::wrap_type<Ret(Args..., ...) & noexcept> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args..., ...) const &> : xieite::wrap_type<Ret(Args..., ...) const & noexcept> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args..., ...) volatile &> : xieite::wrap_type<Ret(Args..., ...) volatile & noexcept> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args..., ...) const volatile &> : xieite::wrap_type<Ret(Args..., ...) const volatile & noexcept> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args..., ...) &&> : xieite::wrap_type<Ret(Args..., ...) && noexcept> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args..., ...) const &&> : xieite::wrap_type<Ret(Args..., ...) const && noexcept> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args..., ...) volatile &&> : xieite::wrap_type<Ret(Args..., ...) volatile && noexcept> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args..., ...) const volatile &&> : xieite::wrap_type<Ret(Args..., ...) const volatile && noexcept> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args...)> : xieite::wrap_type<Ret(S::*)(Args...) noexcept> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args...) const> : xieite::wrap_type<Ret(S::*)(Args...) const noexcept> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args...) volatile> : xieite::wrap_type<Ret(S::*)(Args...) volatile noexcept> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args...) const volatile> : xieite::wrap_type<Ret(S::*)(Args...) const volatile noexcept> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args...) &> : xieite::wrap_type<Ret(S::*)(Args...) & noexcept> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args...) const &> : xieite::wrap_type<Ret(S::*)(Args...) const & noexcept> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args...) volatile &> : xieite::wrap_type<Ret(S::*)(Args...) volatile & noexcept> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args...) const volatile &> : xieite::wrap_type<Ret(S::*)(Args...) const volatile & noexcept> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args...) &&> : xieite::wrap_type<Ret(S::*)(Args...) && noexcept> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args...) const &&> : xieite::wrap_type<Ret(S::*)(Args...) const && noexcept> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args...) volatile &&> : xieite::wrap_type<Ret(S::*)(Args...) volatile && noexcept> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args...) const volatile &&> : xieite::wrap_type<Ret(S::*)(Args...) const volatile && noexcept> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args..., ...)> : xieite::wrap_type<Ret(S::*)(Args..., ...) noexcept> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args..., ...) const> : xieite::wrap_type<Ret(S::*)(Args..., ...) const noexcept> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args..., ...) volatile> : xieite::wrap_type<Ret(S::*)(Args..., ...) volatile noexcept> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args..., ...) const volatile> : xieite::wrap_type<Ret(S::*)(Args..., ...) const volatile noexcept> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args..., ...) &> : xieite::wrap_type<Ret(S::*)(Args..., ...) & noexcept> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args..., ...) const &> : xieite::wrap_type<Ret(S::*)(Args..., ...) const & noexcept> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args..., ...) volatile &> : xieite::wrap_type<Ret(S::*)(Args..., ...) volatile & noexcept> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args..., ...) const volatile &> : xieite::wrap_type<Ret(S::*)(Args..., ...) const volatile & noexcept> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args..., ...) &&> : xieite::wrap_type<Ret(S::*)(Args..., ...) && noexcept> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args..., ...) const &&> : xieite::wrap_type<Ret(S::*)(Args..., ...) const && noexcept> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args..., ...) volatile &&> : xieite::wrap_type<Ret(S::*)(Args..., ...) volatile && noexcept> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args..., ...) const volatile &&> : xieite::wrap_type<Ret(S::*)(Args..., ...) const volatile && noexcept> {};
}

namespace xieite {
	template<typename T>
	using add_noex_referent = xieite::cp_cvref<T, typename DETAIL_XIEITE::add_noex_referent::impl<xieite::rm_cvref<T>>::type>;
}

#endif
