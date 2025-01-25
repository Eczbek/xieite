#pragma once

#include <cstddef>
#include "../meta/t.hpp"
#include "../meta/v.hpp"

namespace xieite {
	template<template<typename, std::size_t> typename Ctnr, typename V, std::size_t... sizes>
	using fixed_md_ctnr = decltype(([]<std::size_t... curr>(this auto self, xieite::v<curr>...) {
		if constexpr (sizeof...(curr)) {
			return ([self]<std::size_t first, std::size_t... rest> {
				return xieite::t<Ctnr<typename decltype(self(xieite::v<rest>()...))::type, first>>();
			})(xieite::v<curr>()...);
		} else {
			return xieite::t<V>();
		}
	})(xieite::v<sizes>()...))::type;
}
