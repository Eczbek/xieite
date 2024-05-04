#ifndef XIEITE_HEADER_CONCEPTS_TEMPLATE_OF
#	define XIEITE_HEADER_CONCEPTS_TEMPLATE_OF

#	include "../concepts/specialization_of.hpp"

namespace xieite::concepts {
	template<template<typename...> typename Template_, typename Type_>
	concept TemplateOf = xieite::concepts::SpecializationOf<Type_, Template_>;
}

#endif
