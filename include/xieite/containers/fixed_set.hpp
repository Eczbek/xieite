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
#	include <utility>
#	include "../containers/make_array.hpp"

namespace xieite::containers {
	template<typename Key, std::size_t size, typename Hash = std::hash<Key>, typename KeyEqual = std::equal_to<Key>, typename Allocator = std::allocator<Key>>
	class FixedSet {
	public:
		constexpr FixedSet() noexcept = default;

		template<std::ranges::range Range>
		constexpr FixedSet(Range&& keys) noexcept
		: array(xieite::containers::makeArray<Key, size>(std::forward<Range>(keys))) {}

		constexpr FixedSet(const std::initializer_list<Key> keys) noexcept
		: array(xieite::containers::makeArray<Key, size>(keys)) {}

		template<std::convertible_to<Key> KeyReference>
		[[nodiscard]] constexpr bool operator[](KeyReference&& key) const noexcept {
			return this->contains(std::forward<KeyReference>(key));
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

		template<std::convertible_to<Key> KeyReference>
		[[nodiscard]] constexpr bool contains(KeyReference&& key) const noexcept {
			if consteval {
				return std::ranges::find(this->array, std::forward<KeyReference>(key)) != this->array.end();
			} else {
				static auto set = std::unordered_set<Key, Hash, KeyEqual, Allocator>(this->array.begin(), this->array.end());
				return set.contains(std::forward<KeyReference>(key));
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
