export module xieite:types.DynamicMatrix;

import std;

export namespace xieite::types {
	template<template<typename> typename DynamicContainer, typename Value, std::size_t dimensions>
	using DynamicMatrix = decltype(([]<std::size_t remaining>(this auto self) {
		if constexpr (remaining) {
			return std::type_identity<DynamicContainer<typename decltype(self.template operator()<remaining - 1>())::type>>();
		} else {
			return std::type_identity<Value>();
		}
	}).template operator()<dimensions>())::type;
}
