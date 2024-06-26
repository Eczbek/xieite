#ifndef XIEITE_HEADER_TRAITS_IS_TEMPLATE_OF_ANY
#	define XIEITE_HEADER_TRAITS_IS_TEMPLATE_OF_ANY

#	include <type_traits>
#	include "../concepts/template_of_any.hpp"

namespace xieite::traits {
	template<template<typename...> typename Template_, typename... Types_>
	struct IsTemplateOfAny
	: std::bool_constant<xieite::concepts::TemplateOfAny<Template_, Types_...>> {};
}

#endif
