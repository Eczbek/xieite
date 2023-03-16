#pragma once
#include <array> // std::array
#include <concepts> // std::convertible_to
#include <limits> // std::numeric_limits

namespace xieite::containers {
	template<std::convertible_to<std::size_t> Key, typename Value>
	class OrderedMap {
	private:
		static const Key minLimit = std::numeric_limits<Key>::min();
		std::array<Value, std::numeric_limits<Key>::max() - minLimit + 1> values;

	public:
		constexpr OrderedMap() noexcept = default;

		[[nodiscard]]
		constexpr Value& operator[](const Key key) noexcept {
			return this->values[key - this->minLimit];
		}

		[[nodiscard]]
		constexpr const Value& operator[](const Key key) const noexcept {
			return this->values[key - this->minLimit];
		}
	};
}
