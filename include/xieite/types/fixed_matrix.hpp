#ifndef XIEITE_HEADER_TYPES_FIXED_MATRIX
#	define XIEITE_HEADER_TYPES_FIXED_MATRIX

#	include <cstddef>
#	include <type_traits>

namespace xieite::detail {
	template<template<typename, std::size_t> typename, typename Value, std::size_t...>
	struct FixedMatrix
	: std::type_identity<Value> {};

	template<template<typename, std::size_t> typename FixedContainer, typename Value, std::size_t firstSize, std::size_t... restSizes>
	struct FixedMatrix<FixedContainer, Value, firstSize, restSizes...>
	: std::type_identity<FixedContainer<typename xieite::detail::FixedMatrix<FixedContainer, Value, restSizes...>::type, firstSize>> {};
};

namespace xieite::types {
	template<template<typename, std::size_t> typename FixedContainer, typename Value, std::size_t... sizes>
	using FixedMatrix = xieite::detail::FixedMatrix<FixedContainer, Value, sizes...>::type;
}

#endif
