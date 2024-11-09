export module xieite:is_template_any;

import :is_template;

export namespace xieite {
	template<template<typename...> typename M, typename... Ts>
	concept is_template_any = (... || xieite::is_template<M, Ts>);
}
