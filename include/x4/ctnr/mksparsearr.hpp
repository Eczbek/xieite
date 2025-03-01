#pragma once

#include <array>
#include <concepts>
#include <cstddef>
#include <functional>
#include <initializer_list>
#include <ranges>
#include <utility>
#include "../fn/cast.hpp"
#include "../math/bits.hpp"
#include "../math/sgncast.hpp"
#include "../meta/arity.hpp"
#include "../trait/isinvoc.hpp"
#include "../trait/isnoexinvoc.hpp"

namespace x4 {
	template<std::integral K, typename V, std::ranges::input_range R = std::initializer_list<std::pair<K, V>>, x4::isinvoc<V(std::ranges::range_common_reference_t<R>)> F = decltype(x4::cast<V>)>
	[[nodiscard]] constexpr std::array<V, (1uz << x4::bits<K>)> mksparsearr(R&& entries, F&& fn = {})
	noexcept(x4::isnoexinvoc<F, V(std::ranges::range_common_reference_t<R>)>) {
		static_assert(x4::bits<K> <= 16, "key type must be reasonably small");
		static_assert(x4::arity<std::ranges::range_value_t<R>> == 2, "range entries must each have one key and one value");
		auto result = std::array<V, (1uz << x4::bits<K>)>();
		for (const auto& [key, value] : entries) {
			result[x4::sgncast<std::size_t>(static_cast<K>(std::forward_like<R>(key)))] = std::invoke(fn, std::forward_like<R>(value));
		}
		return result;
	}
}
