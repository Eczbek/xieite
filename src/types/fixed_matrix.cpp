export module xieite:types.FixedMatrix;

import std;

template<template<typename, std::size_t> typename, typename Value, std::size_t...>
struct FixedMatrix
: std::type_identity<Value> {};

template<template<typename, std::size_t> typename FixedContainer, typename Value, std::size_t firstSize, std::size_t... restSizes>
struct FixedMatrix<FixedContainer, Value, firstSize, restSizes...>
: std::type_identity<FixedContainer<typename FixedMatrix<FixedContainer, Value, restSizes...>::type, firstSize>> {};

export namespace xieite::types {
	template<template<typename, std::size_t> typename FixedContainer, typename Value, std::size_t... sizes>
	using FixedMatrix = FixedMatrix<FixedContainer, Value, sizes...>::type;
}
