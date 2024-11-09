export module xieite:dyn_md_ctnr;

import std;

export namespace xieite {
	template<template<typename> typename Ctnr, typename V, std::size_t rank>
	using dyn_md_ctnr = decltype(([]<std::size_t curr>(this auto self) {
		if constexpr (curr) {
			return std::type_identity<Ctnr<typename decltype(self.template operator()<curr - 1>())::type>>();
		} else {
			return std::type_identity<V>();
		}
	}).template operator()<rank>())::type;
}
