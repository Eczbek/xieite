module;

#include "../macros/forward.hpp"

export module xieite:containers.FixedSet;

import std;
import :containers.makeArray;

export namespace xieite::containers {
	template<typename Key, std::size_t size, typename Hash = std::hash<Key>, typename KeyComparator = std::equal_to<Key>, typename Allocator = std::allocator<Key>>
	struct FixedSet {
	public:
		constexpr FixedSet() noexcept = default;

		template<std::ranges::input_range Range>
		requires(std::convertible_to<std::ranges::range_value_t<Range>, Key>)
		explicit constexpr FixedSet(Range&& keys) noexcept
		: array(xieite::containers::makeArray<Key, size>(XIEITE_FORWARD(keys))) {}

		explicit(false) constexpr FixedSet(const std::initializer_list<Key> keys) noexcept
		: array(xieite::containers::makeArray<Key, size>(keys)) {}

		template<std::convertible_to<Key> KeyReference>
		[[nodiscard]] constexpr bool operator[](KeyReference&& key) const noexcept {
			return this->contains(XIEITE_FORWARD(key));
		}

		template<std::convertible_to<Key> KeyReference>
		[[nodiscard]] constexpr bool contains(KeyReference&& key) const noexcept {
			if consteval {
				return std::ranges::contains(this->array, XIEITE_FORWARD(key));
			} else {
				static const auto set = std::unordered_set<Key, Hash, KeyComparator, Allocator>(this->array.begin(), this->array.end());
				return set.contains(XIEITE_FORWARD(key));
			}
		}

		[[nodiscard]] constexpr const std::array<Key, size>& data() const noexcept {
			return this->array;
		}

	private:
		std::array<Key, size> array;
	};
}
