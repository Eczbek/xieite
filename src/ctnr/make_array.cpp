module;

#include <xieite/fwd.hpp>
#include <xieite/lift.hpp>

export module xieite:make_array;

import std;
import :is_invoc;
import :is_nothrow_invoc;
import :unroll;

export namespace xieite {
	template<typename V, std::size_t size, std::ranges::input_range R = std::initializer_list<V>, xieite::is_invoc<V(std::ranges::range_common_reference_t<R>)> F = decltype(XIEITE_LIFT_ONE(static_cast<V>))>
	[[nodiscard]] constexpr std::array<V, size> make_array(R&& range, F&& conv = {})
	noexcept(xieite::is_nothrow_invoc<F, V(std::ranges::range_common_reference_t<R>)>) {
		return xieite::unroll<size>([&range, &conv]<std::size_t... i> -> std::array<V, size> {
			auto it = std::ranges::begin(XIEITE_FWD(range));
			return std::array<V, size> {
				([&conv, &it] -> decltype(auto) {
					if constexpr (i > 0) {
						++it;
					}
					return std::invoke(conv, std::forward_like<R>(*it));
				})()...
			};
		});
	}
}
