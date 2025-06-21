#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_NOEX_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_NOEX_REFERENT
#
#	include "../meta/type.hpp"
#	include "../trait/cp_cvref.hpp"
#	include "../trait/rm_cvref.hpp"

namespace DETAIL_XIEITE::add_noex_referent {
	template<typename T>
	struct impl : xieite::type<T> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(*)(Args...)> : xieite::type<Ret(*)(Args...) noexcept> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(*)(Args..., ...)> : xieite::type<Ret(*)(Args..., ...) noexcept> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args...)> : xieite::type<Ret(Args...) noexcept> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args...) const> : xieite::type<Ret(Args...) const noexcept> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args...) volatile> : xieite::type<Ret(Args...) volatile noexcept> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args...) const volatile> : xieite::type<Ret(Args...) const volatile noexcept> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args...) &> : xieite::type<Ret(Args...) & noexcept> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args...) const &> : xieite::type<Ret(Args...) const & noexcept> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args...) volatile &> : xieite::type<Ret(Args...) volatile & noexcept> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args...) const volatile &> : xieite::type<Ret(Args...) const volatile & noexcept> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args...) &&> : xieite::type<Ret(Args...) && noexcept> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args...) const &&> : xieite::type<Ret(Args...) const && noexcept> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args...) volatile &&> : xieite::type<Ret(Args...) volatile && noexcept> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args...) const volatile &&> : xieite::type<Ret(Args...) const volatile && noexcept> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args..., ...)> : xieite::type<Ret(Args..., ...) noexcept> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args..., ...) const> : xieite::type<Ret(Args..., ...) const noexcept> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args..., ...) volatile> : xieite::type<Ret(Args..., ...) volatile noexcept> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args..., ...) const volatile> : xieite::type<Ret(Args..., ...) const volatile noexcept> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args..., ...) &> : xieite::type<Ret(Args..., ...) & noexcept> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args..., ...) const &> : xieite::type<Ret(Args..., ...) const & noexcept> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args..., ...) volatile &> : xieite::type<Ret(Args..., ...) volatile & noexcept> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args..., ...) const volatile &> : xieite::type<Ret(Args..., ...) const volatile & noexcept> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args..., ...) &&> : xieite::type<Ret(Args..., ...) && noexcept> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args..., ...) const &&> : xieite::type<Ret(Args..., ...) const && noexcept> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args..., ...) volatile &&> : xieite::type<Ret(Args..., ...) volatile && noexcept> {};

	template<typename Ret, typename... Args>
	struct impl<Ret(Args..., ...) const volatile &&> : xieite::type<Ret(Args..., ...) const volatile && noexcept> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args...)> : xieite::type<Ret(S::*)(Args...) noexcept> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args...) const> : xieite::type<Ret(S::*)(Args...) const noexcept> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args...) volatile> : xieite::type<Ret(S::*)(Args...) volatile noexcept> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args...) const volatile> : xieite::type<Ret(S::*)(Args...) const volatile noexcept> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args...) &> : xieite::type<Ret(S::*)(Args...) & noexcept> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args...) const &> : xieite::type<Ret(S::*)(Args...) const & noexcept> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args...) volatile &> : xieite::type<Ret(S::*)(Args...) volatile & noexcept> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args...) const volatile &> : xieite::type<Ret(S::*)(Args...) const volatile & noexcept> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args...) &&> : xieite::type<Ret(S::*)(Args...) && noexcept> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args...) const &&> : xieite::type<Ret(S::*)(Args...) const && noexcept> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args...) volatile &&> : xieite::type<Ret(S::*)(Args...) volatile && noexcept> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args...) const volatile &&> : xieite::type<Ret(S::*)(Args...) const volatile && noexcept> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args..., ...)> : xieite::type<Ret(S::*)(Args..., ...) noexcept> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args..., ...) const> : xieite::type<Ret(S::*)(Args..., ...) const noexcept> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args..., ...) volatile> : xieite::type<Ret(S::*)(Args..., ...) volatile noexcept> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args..., ...) const volatile> : xieite::type<Ret(S::*)(Args..., ...) const volatile noexcept> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args..., ...) &> : xieite::type<Ret(S::*)(Args..., ...) & noexcept> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args..., ...) const &> : xieite::type<Ret(S::*)(Args..., ...) const & noexcept> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args..., ...) volatile &> : xieite::type<Ret(S::*)(Args..., ...) volatile & noexcept> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args..., ...) const volatile &> : xieite::type<Ret(S::*)(Args..., ...) const volatile & noexcept> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args..., ...) &&> : xieite::type<Ret(S::*)(Args..., ...) && noexcept> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args..., ...) const &&> : xieite::type<Ret(S::*)(Args..., ...) const && noexcept> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args..., ...) volatile &&> : xieite::type<Ret(S::*)(Args..., ...) volatile && noexcept> {};

	template<typename Ret, typename S, typename... Args>
	struct impl<Ret(S::*)(Args..., ...) const volatile &&> : xieite::type<Ret(S::*)(Args..., ...) const volatile && noexcept> {};
}

namespace xieite {
	template<typename T>
	using add_noex_referent = xieite::cp_cvref<T, typename DETAIL_XIEITE::add_noex_referent::impl<xieite::rm_cvref<T>>::type>;
}

#endif
