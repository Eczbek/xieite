#pragma once
#include <concepts>

namespace xieite::numbers {
	template<std::integral auto N, template T = decltype(N)>
	constexpr T factorial = N * xieite::numbers::factorial<N - 1, T>;

	template<template T>
	constexpr T factorial<static_cast<T>(0), T> = static_cast<T>(1);
}
