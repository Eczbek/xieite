#ifndef XIEITE_HEADER_TYPES_DYNAMIC_MATRIX
#	define XIEITE_HEADER_TYPES_DYNAMIC_MATRIX

#	include <cstddef>
#	include <type_traits>

namespace xieite::detail {
	template<template<typename> typename DynamicContainer_, typename Value_, std::size_t dimensions_>
	struct DynamicMatrix
	: std::type_identity<DynamicContainer_<typename xieite::detail::DynamicMatrix<DynamicContainer_, Value_, dimensions_ - 1>::type>> {};

	template<template<typename> typename DynamicContainer_, typename Value_>
	struct DynamicMatrix<DynamicContainer_, Value_, 0>
	: std::type_identity<Value_> {};
}

namespace xieite::types {
	template<template<typename> typename DynamicContainer_, typename Value_, std::size_t dimensions_>
	using DynamicMatrix = xieite::detail::DynamicMatrix<DynamicContainer_, Value_, dimensions_>::type;
}

#endif
