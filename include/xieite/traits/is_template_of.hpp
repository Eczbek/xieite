#ifndef XIEITE_HEADER_TRAITS_IS_TEMPLATE_OF
#	define XIEITE_HEADER_TRAITS_IS_TEMPLATE_OF

#	include <type_traits>
#	include "../concepts/template_of.hpp"

namespace xieite::traits {
	template<template<typename...> typename Template_, typename Type_>
	struct IsTemplateOf
	: std::bool_constant<xieite::concepts::TemplateOf<Template_, Type_>> {};
}

#endif
