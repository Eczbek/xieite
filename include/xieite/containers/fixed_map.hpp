#ifndef XIEITE_HEADER_CONTAINERS_FIXED_MAP
#	define XIEITE_HEADER_CONTAINERS_FIXED_MAP

#	include <array>
#	include <cstddef>
#	include <functional>
#	include <initializer_list>
#	include <memory>
#	include <ranges>
#	include <unordered_map>
#	include <utility>
#	include "../exceptions/invalid_key.hpp"
#	include "../ranges/make_array.hpp"

namespace xieite::containers {
	template<typename Key, typename Value, std::size_t size, typename Hash = std::hash<Key>, typename KeyEqual = std::equal_to<Key>, typename Allocator = std::allocator<std::pair<const Key, Value&>>>
	class FixedMap {
	public:
		constexpr FixedMap() noexcept = default;

		template<std::ranges::range Range>
		constexpr FixedMap(const Range& entries) noexcept
		: array(xieite::ranges::makeArray<std::pair<Key, Value>, size>(entries)) {}

		constexpr FixedMap(const std::initializer_list<std::pair<Key, Value>> entries) noexcept
		: array(xieite::ranges::makeArray<std::pair<Key, Value>, size>(entries)) {}

		[[nodiscard]] constexpr const Value& operator[](const Key& key) const {
			return this->getValue(key);
		}

		[[nodiscard]] constexpr Value& operator[](const Key& key) {
			return this->getValue(key);
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

		[[nodiscard]] constexpr const Value& at(const Key& key) const {
			return this->getValue(key);
		}

		[[nodiscard]] constexpr Value& at(const Key& key) {
			return this->getValue(key);
		}

		[[nodiscard]] constexpr bool contains(const Key& key) const noexcept {
			if consteval {
				for (const std::pair<Key, Value>& entry : this->array) {
					if (entry.first == key) {
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

		[[nodiscard]] std::unordered_map<Key, Value&, Hash, KeyEqual, Allocator>& getMap() const noexcept {
			static std::unordered_map<Key, Value&, Hash, KeyEqual, Allocator> map = ([this] {
				std::unordered_map<Key, Value&, Hash, KeyEqual, Allocator> map;
				for (std::pair<Key, Value>& entry : this->array) {
					map.emplace(entry);
				}
				return map;
			})();
			return map;
		}

		[[nodiscard]] constexpr Value& getValue(const Key& key) const {
			if consteval {
				for (std::pair<Key, Value>& entry : this->array) {
					if (entry.first == key) {
						return entry.second;
					}
				}
				throw xieite::exceptions::InvalidKey("Cannot access key not in map");
			} else {
				return this->getMap().at(key);
			}
		}
	};
}

#endif
