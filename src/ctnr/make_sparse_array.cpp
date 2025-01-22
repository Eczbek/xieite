module;

#include <xieite/lift.hpp>

export module xieite:make_sparse_array;

import std;
import :arity;
import :bit_size;
import :is_invoc;
import :is_noex_invoc;
import :sign_cast;

export namespace xieite {
	template<std::integral K, typename V, std::ranges::input_range R = std::initializer_list<std::pair<K, V>>, xieite::is_invoc<V(std::ranges::range_common_reference_t<R>)> F = decltype(XIEITE_LIFT_ONE(static_cast<V>))>
	[[nodiscard]] constexpr std::array<V, (1uz << xieite::bit_size<K>)> make_sparse_array(R&& entries, F&& fn = {})
	noexcept(xieite::is_noex_invoc<F, V(std::ranges::range_common_reference_t<R>)>) {
		static_assert(xieite::bit_size<K> <= 16, "key type must be reasonably small");
		static_assert(xieite::arity<std::ranges::range_value_t<R>> == 2, "range entries must each have one key and one value");
		auto result = std::array<V, (1uz << xieite::bit_size<K>)>();
		for (const auto& [key, value] : entries) {
			result[xieite::sign_cast<std::size_t>(static_cast<K>(std::forward_like<R>(key)))] = std::invoke(fn, std::forward_like<R>(value));
		}
		return result;
	}
}
