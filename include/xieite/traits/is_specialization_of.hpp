#ifndef XIEITE_HEADER_TRAITS_IS_SPECIALIZATION_OF
#	define XIEITE_HEADER_TRAITS_IS_SPECIALIZATION_OF

#	include <type_traits>

namespace xieite::traits {
	template<typename, template<typename...> typename>
	struct IsSpecializationOf
	: std::false_type {};

	template<template<typename...> typename Template_, typename... Arguments_>
	struct IsSpecializationOf<Template_<Arguments_...>, Template_>
	: std::true_type {};
}

#endif
