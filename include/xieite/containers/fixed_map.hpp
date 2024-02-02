#ifndef XIEITE_HEADER_CONTAINERS_FIXED_MAP
#	define XIEITE_HEADER_CONTAINERS_FIXED_MAP

#	include <array>
#	include <concepts>
#	include <cstddef>
#	include <functional>
#	include <initializer_list>
#	include <memory>
#	include <ranges>
#	include <unordered_map>
#	include <utility>
#	include "../containers/make_array.hpp"
#	include "../exceptions/invalid_key.hpp"

namespace xieite::containers {
	template<typename Key, typename Value, std::size_t size, typename Hash = std::hash<Key>, typename KeyEqual = std::equal_to<Key>, typename Allocator = std::allocator<std::pair<const Key, Value*>>>
	class FixedMap {
	public:
		constexpr FixedMap() noexcept = default;

		template<std::ranges::range Range>
		constexpr FixedMap(Range&& entries) noexcept
		: array(xieite::containers::makeArray<std::pair<Key, Value>, size>(std::forward<Range>(entries))) {}

		constexpr FixedMap(const std::initializer_list<std::pair<Key, Value>> entries) noexcept
		: array(xieite::containers::makeArray<std::pair<Key, Value>, size>(entries)) {}

		template<std::convertible_to<Key> KeyReference>
		[[nodiscard]] constexpr const Value& operator[](KeyReference&& key) const {
			return this->getValue(std::forward<KeyReference>(key));
		}

		template<std::convertible_to<Key> KeyReference>
		[[nodiscard]] constexpr Value& operator[](KeyReference&& key) {
			return this->getValue(std::forward<KeyReference>(key));
		}

		[[nodiscard]] constexpr std::array<std::pair<Key, Value>, size>::const_iterator begin() const noexcept {
			return this->array.begin();
		}

		[[nodiscard]] constexpr std::array<std::pair<Key, Value>, size>::iterator begin() noexcept {
			return this->array.begin();
		}

		[[nodiscard]] constexpr std::array<std::pair<Key, Value>, size>::const_iterator end() const noexcept {
			return this->array.end();
		}

		[[nodiscard]] constexpr std::array<std::pair<Key, Value>, size>::iterator end() noexcept {
			return this->array.end();
		}

		template<std::convertible_to<Key> KeyReference>
		[[nodiscard]] constexpr const Value& at(KeyReference&& key) const {
			return this->getValue(std::forward<KeyReference>(key));
		}

		template<std::convertible_to<Key> KeyReference>
		[[nodiscard]] constexpr Value& at(KeyReference&& key) {
			return this->getValue(std::forward<KeyReference>(key));
		}

		template<std::convertible_to<Key> KeyReference>
		[[nodiscard]] constexpr bool contains(const KeyReference& key) const noexcept {
			if consteval {
				for (const std::pair<Key, Value>& entry : this->array) {
					if (std::invoke(KeyEqual(), entry.first, key)) {
						return true;
					}
				}
				return false;
			} else {
				return this->getMap().contains(key);
			}
		}

		[[nodiscard]] constexpr const std::array<std::pair<Key, Value>, size>& data() const noexcept {
			return this->array;
		}

	private:
		mutable std::array<std::pair<Key, Value>, size> array;

		[[nodiscard]] std::unordered_map<Key, Value*, Hash, KeyEqual, Allocator>& getMap() const noexcept {
			static auto map = ([this] -> std::unordered_map<Key, Value*, Hash, KeyEqual, Allocator> {
				std::unordered_map<Key, Value*, Hash, KeyEqual, Allocator> map;
				for (std::pair<Key, Value>& entry : this->array) {
					map.emplace(std::make_pair(entry.first, &entry.second));
				}
				return map;
			})();
			return map;
		}

		template<std::convertible_to<Key> KeyReference>
		[[nodiscard]] constexpr Value& getValue(const KeyReference& key) const {
			if consteval {
				for (std::pair<Key, Value>& entry : this->array) {
					if (std::invoke(KeyEqual(), entry.first, key)) {
						return entry.second;
					}
				}
				throw xieite::exceptions::InvalidKey("Cannot access key not in map");
			} else {
				return *this->getMap().at(key);
			}
		}
	};
}

#endif
