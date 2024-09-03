export module xieite:concepts.TemplateOfAll;

import :concepts.TemplateOf;

export namespace xieite::concepts {
	template<template<typename...> typename Template, typename... Types>
	concept TemplateOfAll = (... && xieite::concepts::TemplateOf<Template, Types>);
}
