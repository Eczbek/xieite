#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_NOEX_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_NOEX_REFERENT
#
#	include "../meta/type.hpp"
#	include "../trait/cp_cvref.hpp"
#	include "../trait/rm_cvref.hpp"

namespace DETAIL_XIEITE::rm_noex_referent {
	template<typename T>
	struct impl : xieite::type<T> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(*)(Args...) noexcept> : xieite::type<Ret(*)(Args...)> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(*)(Args..., ...) noexcept> : xieite::type<Ret(*)(Args..., ...)> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args...) noexcept> : xieite::type<Ret(Args...)> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args...) const noexcept> : xieite::type<Ret(Args...) const> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args...) volatile noexcept> : xieite::type<Ret(Args...) volatile> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args...) const volatile noexcept> : xieite::type<Ret(Args...) const volatile> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args...) & noexcept> : xieite::type<Ret(Args...) &> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args...) const & noexcept> : xieite::type<Ret(Args...) const &> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args...) volatile & noexcept> : xieite::type<Ret(Args...) volatile &> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args...) const volatile & noexcept> : xieite::type<Ret(Args...) const volatile &> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args...) && noexcept> : xieite::type<Ret(Args...) &&> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args...) const && noexcept> : xieite::type<Ret(Args...) const &&> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args...) volatile && noexcept> : xieite::type<Ret(Args...) volatile &&> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args...) const volatile && noexcept> : xieite::type<Ret(Args...) const volatile &&> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args..., ...) noexcept> : xieite::type<Ret(Args..., ...)> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args..., ...) const noexcept> : xieite::type<Ret(Args..., ...) const> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args..., ...) volatile noexcept> : xieite::type<Ret(Args..., ...) volatile> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args..., ...) const volatile noexcept> : xieite::type<Ret(Args..., ...) const volatile> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args..., ...) & noexcept> : xieite::type<Ret(Args..., ...) &> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args..., ...) const & noexcept> : xieite::type<Ret(Args..., ...) const &> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args..., ...) volatile & noexcept> : xieite::type<Ret(Args..., ...) volatile &> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args..., ...) const volatile & noexcept> : xieite::type<Ret(Args..., ...) const volatile &> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args..., ...) && noexcept> : xieite::type<Ret(Args..., ...) &&> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args..., ...) const && noexcept> : xieite::type<Ret(Args..., ...) const &&> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args..., ...) volatile && noexcept> : xieite::type<Ret(Args..., ...) volatile &&> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args..., ...) const volatile && noexcept> : xieite::type<Ret(Args..., ...) const volatile &&> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args...) noexcept> : xieite::type<Ret(S::*)(Args...)> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args...) const noexcept> : xieite::type<Ret(S::*)(Args...) const> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args...) volatile noexcept> : xieite::type<Ret(S::*)(Args...) volatile> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args...) const volatile noexcept> : xieite::type<Ret(S::*)(Args...) const volatile> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args...) & noexcept> : xieite::type<Ret(S::*)(Args...) &> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args...) const & noexcept> : xieite::type<Ret(S::*)(Args...) const &> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args...) volatile & noexcept> : xieite::type<Ret(S::*)(Args...) volatile &> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args...) const volatile & noexcept> : xieite::type<Ret(S::*)(Args...) const volatile &> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args...) && noexcept> : xieite::type<Ret(S::*)(Args...) &&> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args...) const && noexcept> : xieite::type<Ret(S::*)(Args...) const &&> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args...) volatile && noexcept> : xieite::type<Ret(S::*)(Args...) volatile &&> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args...) const volatile && noexcept> : xieite::type<Ret(S::*)(Args...) const volatile &&> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args..., ...) noexcept> : xieite::type<Ret(S::*)(Args..., ...)> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args..., ...) const noexcept> : xieite::type<Ret(S::*)(Args..., ...) const> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args..., ...) volatile noexcept> : xieite::type<Ret(S::*)(Args..., ...) volatile> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args..., ...) const volatile noexcept> : xieite::type<Ret(S::*)(Args..., ...) const volatile> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args..., ...) & noexcept> : xieite::type<Ret(S::*)(Args..., ...) &> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args..., ...) const & noexcept> : xieite::type<Ret(S::*)(Args..., ...) const &> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args..., ...) volatile & noexcept> : xieite::type<Ret(S::*)(Args..., ...) volatile &> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args..., ...) const volatile & noexcept> : xieite::type<Ret(S::*)(Args..., ...) const volatile &> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args..., ...) && noexcept> : xieite::type<Ret(S::*)(Args..., ...) &&> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args..., ...) const && noexcept> : xieite::type<Ret(S::*)(Args..., ...) const &&> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args..., ...) volatile && noexcept> : xieite::type<Ret(S::*)(Args..., ...) volatile &&> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args..., ...) const volatile && noexcept> : xieite::type<Ret(S::*)(Args..., ...) const volatile &&> {};
}

namespace xieite {
	template<typename T>
	using rm_noex_referent = xieite::cp_cvref<T, typename DETAIL_XIEITE::rm_noex_referent::impl<xieite::rm_cvref<T>>::type>;
}

#endif
