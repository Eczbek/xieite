export module xieite:partial;

export namespace xieite {
	template<template<typename...> typename M, typename... Ts>
	struct partial {
		template<typename... Us>
		using append = M<Ts..., Us...>;

		template<typename... Us>
		using prepend = M<Us..., Ts...>;
	};
}
