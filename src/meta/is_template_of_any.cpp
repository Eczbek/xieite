export module xieite:is_template_of_any;

import :is_template_of;

export namespace xieite {
	template<template<typename...> typename M, typename... Ts>
	concept is_template_of_any = (... || xieite::is_template_of<M, Ts>);
}
