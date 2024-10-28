export module xieite:dynamic_md_container;

import std;

export namespace xieite {
	template<template<typename> typename C, typename V, std::size_t dimensions>
	using dynamic_md_container = decltype(([]<std::size_t remaining>(this auto self) {
		if constexpr (remaining) {
			return std::type_identity<C<typename decltype(self.template operator()<remaining - 1>())::type>>();
		} else {
			return std::type_identity<V>();
		}
	}).template operator()<dimensions>())::type;
}
