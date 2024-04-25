#ifndef XIEITE_HEADER_TYPES_FIXED_MATRIX
#	define XIEITE_HEADER_TYPES_FIXED_MATRIX

#	include <cstddef>
#	include "../types/type_wrapper.hpp"

namespace xieite::detail {
	template<template<typename, std::size_t> typename, typename, std::size_t...>
	struct FixedMatrix;

	template<template<typename, std::size_t> typename FixedContainer_, typename Value_, std::size_t sizesFirst_, std::size_t... sizesRest_>
	struct FixedMatrix<FixedContainer_, Value_, sizesFirst_, sizesRest_...>
	: xieite::types::TypeWrapper<FixedContainer_<typename xieite::detail::FixedMatrix<FixedContainer_, Value_, sizesRest_...>::Type, sizesFirst_>> {};

	template<template<typename, std::size_t> typename FixedContainer_, typename Value_, std::size_t size_>
	struct FixedMatrix<FixedContainer_, Value_, size_>
	: xieite::types::TypeWrapper<FixedContainer_<Value_, size_>> {};

	template<template<typename, std::size_t> typename FixedContainer_, typename Value_>
	struct FixedMatrix<FixedContainer_, Value_>
	: xieite::types::TypeWrapper<Value_> {};
};

namespace xieite::types {
	template<template<typename, std::size_t> typename FixedContainer_, typename Value_, std::size_t... sizes_>
	using FixedMatrix = xieite::detail::FixedMatrix<FixedContainer_, Value_, sizes_...>::Type;
}

#endif
