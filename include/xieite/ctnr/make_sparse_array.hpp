#pragma once

#include <array>
#include <concepts>
#include <cstddef>
#include <functional>
#include <initializer_list>
#include <ranges>
#include <utility>
#include "../fn/cast.hpp"
#include "../math/bit_size.hpp"
#include "../math/sign_cast.hpp"
#include "../meta/arity.hpp"
#include "../trait/is_invoc.hpp"
#include "../trait/is_noex_invoc.hpp"

namespace xieite {
	template<std::integral K, typename V, std::ranges::input_range R = std::initializer_list<std::pair<K, V>>, xieite::is_invoc<V(std::ranges::range_common_reference_t<R>)> F = xieite::cast<V>>
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
