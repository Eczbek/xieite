export module xieite:fixed_md_ctnr;

import std;

export namespace xieite {
	template<template<typename, std::size_t> typename Ctnr, typename V, std::size_t... sizes>
	using fixed_md_ctnr = decltype(([]<std::size_t... curr>(this auto self) {
		if constexpr (sizeof...(curr)) {
			return ([self]<std::size_t first, std::size_t... rest> {
				return std::type_identity<Ctnr<typename decltype(self.template operator()<rest...>())::type, first>>();
			}).template operator()<rest...>();
		} else {
			return std::type_identity<V>();
		}
	}).template operator()<sizes...>())::type;
}
