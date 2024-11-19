export module xieite:fold;

import std;

template<auto fn, typename T>
struct fold_helper {
	using type = T;

	template<typename U>
	fold_helper<fn, decltype(fn.template operator()<U, T>())> operator->*(std::type_identity<U>) const;
};

export namespace xieite {
	template<auto fn, typename T, typename... Ts>
	using fold = decltype((fold_helper<fn, T>()->*...->*std::type_identity<Ts>()))::type;
}
