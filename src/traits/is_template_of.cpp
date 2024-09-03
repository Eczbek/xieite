export module xieite:traits.IsTemplateOf;

import std;
import :concepts.TemplateOf;

export namespace xieite::traits {
	template<template<typename...> typename Template, typename Type>
	struct IsTemplateOf
	: std::bool_constant<xieite::concepts::TemplateOf<Template, Type>> {};
}
