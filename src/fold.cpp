export module xieite:fold;

import std;

template<auto fn, typename T>
struct fold_helper : T {
	template<typename U>
	fold_helper<fn, decltype(fn.template operator()<U::type, T::type>())> operator->*(U) const;
};

export namespace xieite {
	template<auto fn, typename T, typename... Ts>
	using fold = decltype((fold_helper<fn, std::type_identity<T>>()->*...->*std::type_identity<Ts>()))::type;
}
