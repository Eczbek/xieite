#ifndef XIEITE_HEADER_CONTAINERS_FIXED_SET
#	define XIEITE_HEADER_CONTAINERS_FIXED_SET

#	include <algorithm>
#	include <array>
#	include <concepts>
#	include <cstddef>
#	include <functional>
#	include <initializer_list>
#	include <memory>
#	include <ranges>
#	include <unordered_set>
#	include "../containers/make_array.hpp"
#	include "../macros/forward.hpp"

namespace xieite::containers {
	template<typename Key, std::size_t size, typename Hash = std::hash<Key>, typename KeyEqual = std::equal_to<Key>, typename Allocator = std::allocator<Key>>
	class FixedSet {
	public:
		constexpr FixedSet() noexcept = default;

		template<std::ranges::range Range>
		constexpr FixedSet(Range&& keys) noexcept
		: array(xieite::containers::makeArray<Key, size>(XIEITE_FORWARD(keys))) {}

		constexpr FixedSet(const std::initializer_list<Key> keys) noexcept
		: array(xieite::containers::makeArray<Key, size>(keys)) {}

		template<std::convertible_to<Key> KeyReference>
		[[nodiscard]] constexpr bool operator[](KeyReference&& key) const noexcept {
			return this->contains(XIEITE_FORWARD(key));
		}

		template<std::convertible_to<Key> KeyReference>
		[[nodiscard]] constexpr bool contains(const KeyReference& key) const noexcept {
			if consteval {
				return std::ranges::find(this->array, key) != this->array.end();
			} else {
				static const auto set = std::unordered_set<Key, Hash, KeyEqual, Allocator>(this->array.begin(), this->array.end());
				return set.contains(key);
			}
		}

		[[nodiscard]] constexpr const std::array<Key, size>& data() const noexcept {
			return this->array;
		}

	private:
		mutable std::array<Key, size> array;
	};
}

#endif
