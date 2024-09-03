export module xieite:types.DynamicMatrix;

import std;

template<template<typename> typename DynamicContainer, typename Value, std::size_t dimensions>
struct DynamicMatrix
: std::type_identity<DynamicContainer<typename DynamicMatrix<DynamicContainer, Value, dimensions - 1>::type>> {};

template<template<typename> typename DynamicContainer, typename Value>
struct DynamicMatrix<DynamicContainer, Value, 0>
: std::type_identity<Value> {};

export namespace xieite::types {
	template<template<typename> typename DynamicContainer, typename Value, std::size_t dimensions>
	using DynamicMatrix = DynamicMatrix<DynamicContainer, Value, dimensions>::type;
}
