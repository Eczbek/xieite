module;

#include <xieite/sequence.hpp>

export module xieite:functors.templatify;

import std;

export namespace xieite::functors {
	template<template<std::uint8_t> typename Functor>
	requires(XIEITE_SEQUENCE(i, (1uz << std::numeric_limits<std::uint8_t>::digits), (... && std::invocable<Functor<static_cast<std::uint8_t>(i)>>)))
	constexpr void templatify(const std::uint8_t value)
	noexcept(XIEITE_SEQUENCE(i, (1uz << std::numeric_limits<std::uint8_t>::digits), (... && std::is_nothrow_invocable_v<Functor<static_cast<std::uint8_t>(i)>>))) {
		XIEITE_SEQUENCE(i, (1uz << std::numeric_limits<std::uint8_t>::digits), (..., ([value] {
			static constexpr std::uint8_t index = static_cast<std::uint8_t>(i);
			if (value == index) {
				std::invoke(Functor<index>());
			}
		})()));
	}
}
