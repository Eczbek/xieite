#ifndef XIEITE_HEADER_TRAITS_IS_SPECIALIZATION_OF
#	define XIEITE_HEADER_TRAITS_IS_SPECIALIZATION_OF

#	include <type_traits>

namespace xieite::traits {
	template<typename, template<typename...> typename>
	struct IsSpecializationOf
	: std::false_type {};

	template<template<typename...> typename Template, typename... Arguments>
	struct IsSpecializationOf<Template<Arguments...>, Template>
	: std::true_type {};
}

#endif
