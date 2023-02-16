#pragma once
#include <array> // std::array
#include <concepts> // std::convertible_to
#include <limits> // std::numeric_limits

namespace xieite::containers {
	template<std::convertible_to<std::size_t> K, typename V>
	class OrderedMap {
	private:
		static const K minLimit = std::numeric_limits<K>::min();
		std::array<V, std::numeric_limits<K>::max() - minLimit + 1> values;

	public:
		constexpr OrderedMap() noexcept = default;

		[[nodiscard]]
		constexpr V& operator[](const K key) noexcept {
			return values[key - minLimit];
		}

		[[nodiscard]]
		constexpr const V& operator[](const K key) const noexcept {
			return values[key - minLimit];
		}
	};
}
