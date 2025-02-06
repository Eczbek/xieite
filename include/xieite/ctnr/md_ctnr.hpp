#pragma once

#include <cstddef>
#include <type_traits>
#include "../meta/value.hpp"

namespace xieite {
	template<template<typename> typename Ctnr, typename V, std::size_t rank>
	using md_ctnr = decltype(([]<std::size_t rest>(this auto self, xieite::value<rest>) {
		if constexpr (rest) {
			return std::type_identity<Ctnr<typename decltype(self(xieite::value<(rest - 1)>()))::type>>();
		} else {
			return std::type_identity<V>();
		}
	})(xieite::value<rank>()))::type;
}
