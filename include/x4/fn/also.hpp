#pragma once

#include <concepts>
#include <functional>
#include "../pp/fn.hpp"
#include "../pp/fwd.hpp"
#include "../trait/hascpctor.hpp"
#include "../trait/hasnoexcpctor.hpp"
#include "../trait/isnoexinvoc.hpp"

namespace x4 {
	template<x4::hascpctor T, std::invocable<T&&> F>
	[[nodiscard]] constexpr T also(T&& x, F&& fn = {})
	noexcept(x4::hasnoexcpctor<T> && x4::isnoexinvoc<F, void(T&&)>) {
		const T copy = x;
		std::invoke(X4FWD(fn), x);
		return copy;
	}

	template<x4::hascpctor T, std::invocable<> F>
	[[nodiscard]] constexpr T also(T&& x, F&& fn = {})
	noexcept(x4::hasnoexcpctor<T> && x4::isnoexinvoc<F>) {
		return x4::also(X4FWD(x), X4FNLOC(std::invoke(X4FWD(fn))));
	}
}
