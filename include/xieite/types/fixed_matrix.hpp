#ifndef XIEITE_HEADER_TYPES_FIXED_MATRIX
#	define XIEITE_HEADER_TYPES_FIXED_MATRIX

#	include <cstddef>

namespace xieite::detail {
	template<template<typename, std::size_t> typename, typename, std::size_t...>
	struct FixedMatrix;

	template<template<typename, std::size_t> typename FixedContainer, typename Value, std::size_t sizesFirst, std::size_t... sizesRest>
	struct FixedMatrix<FixedContainer, Value, sizesFirst, sizesRest...> {
		using Type = FixedContainer<typename xieite::detail::FixedMatrix<FixedContainer, Value, sizesRest...>::Type, sizesFirst>;
	};

	template<template<typename, std::size_t> typename FixedContainer, typename Value, std::size_t size>
	struct FixedMatrix<FixedContainer, Value, size> {
		using Type = FixedContainer<Value, size>;
	};

	template<template<typename, std::size_t> typename FixedContainer, typename Value>
	struct FixedMatrix<FixedContainer, Value> {
		using Type = Value;
	};
};

namespace xieite::types {
	template<template<typename, std::size_t> typename Container, typename Value, std::size_t... sizes>
	using FixedMatrix = xieite::detail::FixedMatrix<Container, Value, sizes...>::Type;
}

#endif
