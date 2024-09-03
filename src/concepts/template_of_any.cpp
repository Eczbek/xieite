export module xieite:concepts.TemplateOfAny;

import :concepts.TemplateOf;

export namespace xieite::concepts {
	template<template<typename...> typename Template, typename... Types>
	concept TemplateOfAny = (... || xieite::concepts::TemplateOf<Template, Types>);
}
