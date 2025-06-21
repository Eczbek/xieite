#ifndef DETAIL_XIEITE_HEADER_TRAIT_GET_MEMBER_PTR_CLASS
#	define DETAIL_XIEITE_HEADER_TRAIT_GET_MEMBER_PTR_CLASS
#
#	include "../meta/type.hpp"
#	include "../trait/rm_cvref.hpp"

namespace DETAIL_XIEITE::get_member_ptr_class {
	template<typename T>
	struct impl : xieite::type<T> {};
	
	template<typename T, typename S>
	struct impl<T S::*> : xieite::type<S> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) noexcept(noex)> : xieite::type<S> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) const noexcept(noex)> : xieite::type<S> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) volatile noexcept(noex)> : xieite::type<S> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) const volatile noexcept(noex)> : xieite::type<S> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) & noexcept(noex)> : xieite::type<S> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) const & noexcept(noex)> : xieite::type<S> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) volatile & noexcept(noex)> : xieite::type<S> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) const volatile & noexcept(noex)> : xieite::type<S> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) && noexcept(noex)> : xieite::type<S> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) const && noexcept(noex)> : xieite::type<S> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) volatile && noexcept(noex)> : xieite::type<S> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args...) const volatile && noexcept(noex)> : xieite::type<S> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) noexcept(noex)> : xieite::type<S> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) const noexcept(noex)> : xieite::type<S> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) volatile noexcept(noex)> : xieite::type<S> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) const volatile noexcept(noex)> : xieite::type<S> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) & noexcept(noex)> : xieite::type<S> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) const & noexcept(noex)> : xieite::type<S> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) volatile & noexcept(noex)> : xieite::type<S> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) const volatile & noexcept(noex)> : xieite::type<S> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) && noexcept(noex)> : xieite::type<S> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) const && noexcept(noex)> : xieite::type<S> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) volatile && noexcept(noex)> : xieite::type<S> {};

	template<typename Ret, typename S, typename... Args, bool noex>
	struct impl<Ret(S::*)(Args..., ...) const volatile && noexcept(noex)> : xieite::type<S> {};
}

namespace xieite {
	template<typename T>
	using get_member_ptr_class = DETAIL_XIEITE::get_member_ptr_class::impl<xieite::rm_cvref<T>>::type;
}

#endif
