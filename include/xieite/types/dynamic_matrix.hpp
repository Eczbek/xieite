#ifndef XIEITE_HEADER_TYPES_DYNAMIC_MATRIX
#	define XIEITE_HEADER_TYPES_DYNAMIC_MATRIX

#	include <cstddef>
#	include "../types/type_wrapper.hpp"

namespace xieite::detail {
	template<template<typename> typename DynamicContainer_, typename Value_, std::size_t dimensions_>
	struct DynamicMatrix
	: xieite::types::TypeWrapper<xieite::detail::DynamicMatrix<DynamicContainer_, DynamicContainer_<Value_>, dimensions_ - 1>> {};

	template<template<typename> typename DynamicContainer_, typename Value_>
	struct DynamicMatrix<DynamicContainer_, Value_, 0>
	: xieite::types::TypeWrapper<Value_> {};
}

namespace xieite::types {
	template<template<typename> typename DynamicContainer_, typename Value_, std::size_t dimensions_>
	using DynamicMatrix = xieite::detail::DynamicMatrix<DynamicContainer_, Value_, dimensions_>::Type_;
}

#endif
