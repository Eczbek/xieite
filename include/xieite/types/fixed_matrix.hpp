#ifndef XIEITE_HEADER_TYPES_FIXED_MATRIX
#	define XIEITE_HEADER_TYPES_FIXED_MATRIX

#	include <cstddef>
#	include "../types/type_wrapper.hpp"

namespace xieite::detail {
	template<template<typename, std::size_t> typename, typename Value_, std::size_t...>
	struct FixedMatrix
	: xieite::types::TypeWrapper<Value_> {};

	template<template<typename, std::size_t> typename FixedContainer_, typename Value_, std::size_t firstSize_, std::size_t... restSizes_>
	struct FixedMatrix<FixedContainer_, Value_, firstSize_, restSizes_...>
	: xieite::types::TypeWrapper<FixedContainer_<typename xieite::detail::FixedMatrix<FixedContainer_, Value_, restSizes_...>::Type, firstSize_>> {};
};

namespace xieite::types {
	template<template<typename, std::size_t> typename FixedContainer_, typename Value_, std::size_t... sizes_>
	using FixedMatrix = xieite::detail::FixedMatrix<FixedContainer_, Value_, sizes_...>::Type;
}

#endif
