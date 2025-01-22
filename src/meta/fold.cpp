export module xieite:fold;

import :t;

namespace detail::fold {
	template<auto fn, typename T>
	struct impl {
		using type = T;

		template<typename U>
		detail::fold::impl<fn, decltype(fn.template operator()<U, T>())> operator->*(xieite::t<U>) const;
	};
}

export namespace xieite {
	template<auto fn, typename T, typename... Ts>
	using fold = decltype((detail::fold::impl<fn, T>()->*...->*xieite::t<Ts>()))::type;
}
