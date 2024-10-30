export module xieite:fixed_md_ctnr;

import std;

export namespace xieite {
	template<template<typename, std::size_t> typename C, typename V, std::size_t... sizes>
	using fixed_md_ctnr = decltype(([]<std::size_t... remaining>(this auto self) {
		if constexpr (sizeof...(remaining)) {
			return ([self]<std::size_t first, std::size_t... rest> {
				return std::type_identity<C<typename decltype(self.template operator()<rest...>())::type, first>>();
			}).template operator()<remaining...>();
		} else {
			return std::type_identity<V>();
		}
	}).template operator()<sizes...>())::type;
}
