#pragma once

#include <array>
#include <concepts>
#include <cstddef>
#include <limits>


namespace gcufl {
	template<std::convertible_to<std::size_t> K, typename V>
	struct OrderedMap {
		std::array<V, std::numeric_limits<K>::max() - std::numeric_limits<K>::min() + 1> values;

		V& operator[](const K key) noexcept {
			return values[key - std::numeric_limits<K>::min()];
		}

		const V& operator[](const K key) const noexcept {
			return values[key - std::numeric_limits<K>::min()];
		}
	};
}
