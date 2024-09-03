export module xieite:traits.IsTemplateOfAll;

import std;
import :concepts.TemplateOfAll;

export namespace xieite::traits {
	template<template<typename...> typename Template, typename... Types>
	struct IsTemplateOfAll
	: std::bool_constant<xieite::concepts::TemplateOfAll<Template, Types...>> {};
}
