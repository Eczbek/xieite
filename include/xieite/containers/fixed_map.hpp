#ifndef XIEITE_HEADER_CONTAINERS_FIXED_MAP
#	define XIEITE_HEADER_CONTAINERS_FIXED_MAP

#	include <array>
#	include <concepts>
#	include <cstddef>
#	include <functional>
#	include <initializer_list>
#	include <memory>
#	include <unordered_map>
#	include <utility>
#	include "../concepts/range_of.hpp"
#	include "../containers/make_array.hpp"
#	include "../exceptions/invalid_key.hpp"
#	include "../macros/forward.hpp"

namespace xieite::containers {
	template<typename Key, typename Value, std::size_t size, typename Hash = std::hash<Key>, typename KeyComparator = std::equal_to<Key>, typename Allocator = std::allocator<std::pair<const Key, Value*>>>
	struct FixedMap {
	public:
		constexpr FixedMap() noexcept = default;

		template<xieite::concepts::RangeOf<std::pair<Key, Value>> Range>
		constexpr FixedMap(Range&& entries) noexcept
		: array(xieite::containers::makeArray<std::pair<Key, Value>, size>(XIEITE_FORWARD(entries))) {}

		constexpr FixedMap(const std::initializer_list<std::pair<Key, Value>> entries) noexcept
		: array(xieite::containers::makeArray<std::pair<Key, Value>, size>(entries)) {}

		template<typename Self, std::convertible_to<Key> KeyReference>
		[[nodiscard]] constexpr auto&& operator[](this Self&& self, KeyReference&& key) {
			return XIEITE_FORWARD(self).getValue(XIEITE_FORWARD(key));
		}

		template<typename Self, std::convertible_to<Key> KeyReference>
		[[nodiscard]] constexpr auto&& at(this Self&& self, KeyReference&& key) {
			return XIEITE_FORWARD(self).getValue(XIEITE_FORWARD(key));
		}

		template<std::convertible_to<Key> KeyReference>
		[[nodiscard]] constexpr bool contains(KeyReference&& key) const noexcept {
			if consteval {
				for (const std::pair<Key, Value>& entry : this->array) {
					if (std::invoke(KeyComparator(), entry.first, XIEITE_FORWARD(key))) {
						return true;
					}
				}
				return false;
			} else {
				return this->getMap().contains(XIEITE_FORWARD(key));
			}
		}

		[[nodiscard]] constexpr const std::array<std::pair<Key, Value>, size>& data() const noexcept {
			return this->array;
		}

	private:
		mutable std::array<std::pair<Key, Value>, size> array;

		[[nodiscard]] std::unordered_map<Key, Value*, Hash, KeyComparator, Allocator>& getMap() const noexcept {
			static auto map = ([this] -> std::unordered_map<Key, Value*, Hash, KeyComparator, Allocator> {
				std::unordered_map<Key, Value*, Hash, KeyComparator, Allocator> map;
				for (std::pair<Key, Value>& entry : this->array) {
					map.emplace(std::make_pair(entry.first, &entry.second));
				}
				return map;
			})();
			return map;
		}

		template<std::convertible_to<Key> KeyReference>
		[[nodiscard]] constexpr Value& getValue(KeyReference&& key) const {
			if consteval {
				for (std::pair<Key, Value>& entry : this->array) {
					if (std::invoke(KeyComparator(), entry.first, key)) {
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
