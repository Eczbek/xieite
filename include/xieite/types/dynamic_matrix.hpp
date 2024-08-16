#ifndef XIEITE_HEADER_TYPES_DYNAMIC_MATRIX
#	define XIEITE_HEADER_TYPES_DYNAMIC_MATRIX

#	include <cstddef>
#	include <type_traits>

namespace xieite::detail {
	template<template<typename> typename DynamicContainer, typename Value, std::size_t dimensions>
	struct DynamicMatrix
	: std::type_identity<DynamicContainer<typename xieite::detail::DynamicMatrix<DynamicContainer, Value, dimensions - 1>::type>> {};

	template<template<typename> typename DynamicContainer, typename Value>
	struct DynamicMatrix<DynamicContainer, Value, 0>
	: std::type_identity<Value> {};
}

namespace xieite::types {
	template<template<typename> typename DynamicContainer, typename Value, std::size_t dimensions>
	using DynamicMatrix = xieite::detail::DynamicMatrix<DynamicContainer, Value, dimensions>::type;
}

#endif
