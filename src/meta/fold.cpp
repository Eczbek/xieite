export module xieite:fold;

import std;

template<auto fn, typename T>
struct fold_helper : std::type_identity<T> {
	template<typename U>
	fold_helper<fn, decltype(fn.template operator()<U, T>())> operator->*(const U&) const;
};

export namespace xieite {
	template<auto fn, typename T, typename... Ts>
	using fold = decltype((fold_helper<fn, T>()->*...->*std::declval<Ts>()))::type;
}
