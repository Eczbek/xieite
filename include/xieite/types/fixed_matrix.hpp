#ifndef XIEITE_HEADER_TYPES_FIXED_MATRIX
#	define XIEITE_HEADER_TYPES_FIXED_MATRIX

#	include <cstddef>
#	include <type_traits>

namespace xieite::detail {
	template<template<typename, std::size_t> typename, typename Value_, std::size_t...>
	struct FixedMatrix
	: std::type_identity<Value_> {};

	template<template<typename, std::size_t> typename FixedContainer_, typename Value_, std::size_t firstSize_, std::size_t... restSizes_>
	struct FixedMatrix<FixedContainer_, Value_, firstSize_, restSizes_...>
	: std::type_identity<FixedContainer_<typename xieite::detail::FixedMatrix<FixedContainer_, Value_, restSizes_...>::type, firstSize_>> {};
};

namespace xieite::types {
	template<template<typename, std::size_t> typename FixedContainer_, typename Value_, std::size_t... sizes_>
	using FixedMatrix = xieite::detail::FixedMatrix<FixedContainer_, Value_, sizes_...>::type;
}

#endif
