#ifndef XIEITE_HEADER_CONCEPTS_TEMPLATE_OF_ANY
#	define XIEITE_HEADER_CONCEPTS_TEMPLATE_OF_ANY

#	include "../concepts/template_of.hpp"

namespace xieite::concepts {
	template<template<typename...> typename Template, typename... Types>
	concept TemplateOfAny = (... || xieite::concepts::TemplateOf<Template, Types>)
}

#endif
