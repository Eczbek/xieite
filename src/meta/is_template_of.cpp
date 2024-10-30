export module xieite:is_template_of;

import :is_spec_of;

export namespace xieite {
	template<template<typename...> typename M, typename T>
	concept is_template_of = xieite::is_spec_of<T, M>;
}
