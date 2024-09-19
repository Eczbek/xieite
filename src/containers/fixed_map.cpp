module;

#include <xieite/forward.hpp>

export module xieite:containers.FixedMap;

import std;
import :containers.makeArray;

export namespace xieite::containers {
	template<typename Key, typename Value, std::size_t size, typename Hash = std::hash<Key>, typename KeyComparator = std::ranges::equal_to, typename Allocator = std::allocator<std::pair<const Key, Value*>>>
	struct FixedMap {
	public:
		FixedMap() = default;

		template<std::ranges::input_range Range>
		requires(std::convertible_to<std::ranges::range_value_t<Range>, std::pair<Key, Value>>)
		explicit constexpr FixedMap(Range&& entries) noexcept
		: array(xieite::containers::makeArray<std::pair<Key, Value>, size>(XIEITE_FORWARD(entries))) {}

		explicit(false) constexpr FixedMap(const std::initializer_list<std::pair<Key, Value>> entries) noexcept
		: array(xieite::containers::makeArray<std::pair<Key, Value>, size>(entries)) {}

		template<typename Self, std::convertible_to<Key> KeyReference>
		[[nodiscard]] constexpr auto&& operator[](this Self&& self, KeyReference&& key) {
			if consteval {
				KeyComparator keyComparator;
				for (auto&& entry : self.array) {
					if (std::invoke(keyComparator, entry.first, key)) {
						return std::forward_like<Self>(entry.second);
					}
				}
				throw std::out_of_range("must not access nonexistent key");
			} else {
				return std::forward_like<Self>(*self.getMap().at(XIEITE_FORWARD(key)));
			}
		}

		template<typename Self, std::convertible_to<Key> KeyReference>
		[[nodiscard]] constexpr auto&& at(this Self&& self, KeyReference&& key) {
			return std::forward_like<Self>(self[XIEITE_FORWARD(key)]);
		}

		template<std::convertible_to<Key> KeyReference>
		[[nodiscard]] constexpr bool contains(KeyReference&& key) const noexcept {
			if consteval {
				KeyComparator keyComparator;
				for (const std::pair<Key, Value>& entry : this->array) {
					if (std::invoke(keyComparator, entry.first, key)) {
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
		std::array<std::pair<Key, Value>, size> array;

		[[nodiscard]] std::unordered_map<Key, Value*, Hash, KeyComparator, Allocator>& getMap() const noexcept {
			using Map = std::unordered_map<Key, Value*, Hash, KeyComparator, Allocator>;
			static Map map = ([this] {
				Map map;
				map.reserve(this->array.size());
				for (const std::pair<Key, Value>& entry : this->array) {
					// Disregard constness here; It is properly handled in `operator[]`
					map.emplace(std::make_pair(entry.first, const_cast<Value*>(std::addressof(entry.second))));
				}
				return map;
			})();
			return map;
		}
	};
}
