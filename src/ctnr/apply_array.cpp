module;

#include <xieite/arrow.hpp>
#include <xieite/fwd.hpp>

export module xieite:apply_array;

import std;
import :is_rm_cvref_same_as;
import :unroll;

export namespace xieite {
	template<typename F, typename V, std::size_t size, xieite::is_rm_cvref_same_as<std::array<V, size>> Array>
	constexpr auto apply_array(F&& fn, Array&& array)
	XIEITE_ARROW(xieite::unroll<size>([&fn, &array]<std::size_t... i> {
		return std::invoke(XIEITE_FWD(fn), std::forward_like<Array>(array[i])...);
	}))

	template<typename T, typename V, std::size_t size, xieite::is_rm_cvref_same_as<std::array<V, size>> Array>
	[[nodiscard]] constexpr auto apply_array(Array&& array)
	XIEITE_ARROW(xieite::unroll<size>([&array]<std::size_t... i> {
		return T(std::forward_like<Array>(array[i])...);
	}))
}
