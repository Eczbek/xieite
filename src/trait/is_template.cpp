export module xieite:is_template;

import :is_spec;

export namespace xieite {
	template<template<typename...> typename M, typename T>
	concept is_template = xieite::is_spec<T, M>;
}
