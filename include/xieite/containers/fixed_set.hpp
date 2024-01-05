#ifndef XIEITE_HEADER_CONTAINERS_FIXED_SET
#	define XIEITE_HEADER_CONTAINERS_FIXED_SET

#	include <algorithm>
#	include <array>
#	include <cstddef>
#	include <functional>
#	include <initializer_list>
#	include <memory>
#	include <ranges>
#	include <unordered_set>
#	include <utility>
#	include "../ranges/make_array.hpp"

namespace xieite::containers {
	template<typename Key, std::size_t size, typename Hash = std::hash<Key>, typename KeyEqual = std::equal_to<Key>, typename Allocator = std::allocator<Key>>
	class FixedSet {
	public:
		constexpr FixedSet() noexcept = default;

		template<std::ranges::range Range>
		constexpr FixedSet(const Range& keys) noexcept
		: array(xieite::ranges::makeArray<Key, size>(keys)) {}

		constexpr FixedSet(const std::initializer_list<Key> keys) noexcept
		: array(xieite::ranges::makeArray<Key, size>(keys)) {}

		[[nodiscard]] constexpr bool operator[](const Key& key) const noexcept {
			return this->contains(key);
		}

		[[nodiscard]] constexpr std::array<Key, size>::const_iterator begin() const noexcept {
			return this->array.begin();
		}

		[[nodiscard]] constexpr std::array<Key, size>::iterator begin() noexcept {
			return this->array.begin();
		}

		[[nodiscard]] constexpr std::array<Key, size>::const_iterator end() const noexcept {
			return this->array.end();
		}

		[[nodiscard]] constexpr std::array<Key, size>::iterator end() noexcept {
			return this->array.end();
		}

		[[nodiscard]] constexpr bool contains(const Key& key) const noexcept {
			if consteval {
				return std::ranges::find(this->array, key) != this->array.end();
			} else {
				static std::unordered_set<Key, Hash, KeyEqual, Allocator> set = ([this] {
					std::unordered_set<Key, Hash, KeyEqual, Allocator> set;
					for (const Key& entry : this->array) {
						set.emplace(entry);
					}
					return set;
				})();
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