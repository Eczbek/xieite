export module xieite:types.FixedMatrix;

import std;

export namespace xieite::types {
	template<template<typename, std::size_t> typename FixedContainer, typename Value, std::size_t... sizes>
	using FixedMatrix = decltype(([]<std::size_t... remaining>(this auto self) {
		if constexpr (sizeof...(remaining)) {
			return ([self]<std::size_t first, std::size_t... rest> {
				return std::type_identity<FixedContainer<typename decltype(self.template operator()<rest...>())::type, first>>();
			}).template operator()<remaining...>();
		} else {
			return std::type_identity<Value>();
		}
	}).template operator()<sizes...>())::type;
}
