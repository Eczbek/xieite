#ifndef XIEITE_HEADER_TRAITS_IS_TEMPLATE_OF_ALL
#	define XIEITE_HEADER_TRAITS_IS_TEMPLATE_OF_ALL

#	include <type_traits>
#	include "../concepts/template_of_all.hpp"

namespace xieite::traits {
	template<template<typename...> typename Template_, typename... Types_>
	struct IsTemplateOfAll
	: std::bool_constant<xieite::concepts::TemplateOfAll<Template_, Types_...>> {};
}

#endif
