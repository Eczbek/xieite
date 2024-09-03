export module xieite:functors.templatify;

import std;

export namespace xieite::functors {
	template<template<std::uint8_t> typename Functor>
	requires(([]<std::size_t... i>(std::index_sequence<i...>) -> bool {
		return (... && std::invocable<Functor<static_cast<std::uint8_t>(i)>>);
	})(std::make_index_sequence<static_cast<std::size_t>(std::numeric_limits<std::uint8_t>::max()) + 1>()))
	constexpr void templatify(const std::uint8_t value)
	noexcept(([]<std::size_t... i>(std::index_sequence<i...>) -> bool {
		return (... && std::is_nothrow_invocable_v<Functor<static_cast<std::uint8_t>(i)>>);
	})(std::make_index_sequence<static_cast<std::size_t>(std::numeric_limits<std::uint8_t>::max()) + 1>())) {
		([value]<std::size_t... i>(std::index_sequence<i...>) -> void {
			(..., ([value] -> void {
				static constexpr std::uint8_t index = static_cast<std::uint8_t>(i);
				if (value == index) {
					std::invoke(Functor<index>());
				}
			})());
		})(std::make_index_sequence<static_cast<std::size_t>(std::numeric_limits<std::uint8_t>::max()) + 1>());
	}
}
