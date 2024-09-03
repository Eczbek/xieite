export module xieite:concepts.TemplateOf;

import :concepts.SpecializationOf;

export namespace xieite::concepts {
	template<template<typename...> typename Template, typename Type>
	concept TemplateOf = xieite::concepts::SpecializationOf<Type, Template>;
}
