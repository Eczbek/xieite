#ifndef XIEITE_HEADER__TYPES__FIXED_MATRIX
#	define XIEITE_HEADER__TYPES__FIXED_MATRIX

namespace xieite::types {
	template<template<typename, std::size_t> typename, typename, std::size_t...>
	struct FixedMatrix;

	template<template<typename, std::size_t> typename FixedContainer, typename Value, std::size_t sizesFirst, std::size_t... sizesRest>
	struct FixedMatrix<FixedContainer, Value, sizesFirst, sizesRest...> {
		using Type = FixedMatrix<FixedContainer, FixedContainer<Value, sizesFirst>, sizesRest...>::Type;
	};

	template<template<typename, std::size_t> typename FixedContainer, typename Value, std::size_t size>
	struct FixedMatrix<FixedContainer, Value, size> {
		using Type = FixedContainer<Value, size>;
	};

	template<template<typename, std::size_t> typename FixedContainer, typename Value>
	struct FixedMatrix<FixedContainer, Value> {
		using Type = Value;
	};
}

#endif
