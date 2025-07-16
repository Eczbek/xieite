#ifndef DETAIL_XIEITE_HEADER_DATA_FIXED_MAP
#	define DETAIL_XIEITE_HEADER_DATA_FIXED_MAP
#
#	include <array>
#	include <concepts>
#	include <functional>
#	include <initializer_list>
#	include <memory>
#	include <stdexcept>
#	include <ranges>
#	include <unordered_map>
#	include <utility>
#	include "../data/make_array.hpp"
#	include "../pp/fwd.hpp"
#	include "../trait/is_ref_to.hpp"

namespace xieite {
	template<typename Key, typename Value, std::size_t length, typename Hash = std::hash<Key>, typename Cmp = std::equal_to<>, typename Alloc = std::allocator<std::pair<const Key, Value*>>>
	struct fixed_map {
	public:
		[[nodiscard]] fixed_map() = default;

		template<std::ranges::input_range Range>
		requires(std::convertible_to<std::ranges::range_value_t<Range>, std::pair<Key, Value>>)
		[[nodiscard]] explicit constexpr fixed_map(Range&& entries) noexcept
		: array(xieite::make_array<std::pair<Key, Value>, length>(XIEITE_FWD(entries))) {}

		[[nodiscard]] explicit(false) constexpr fixed_map(std::initializer_list<std::pair<Key, Value>> entries) noexcept
		: array(xieite::make_array<std::pair<Key, Value>, length>(entries)) {}

		[[nodiscard]] constexpr auto&& operator[](this auto&& self, xieite::is_ref_to<Key> auto&& key) noexcept(false) {
			auto* value = XIEITE_FWD(self).get_val(XIEITE_FWD(key));
			if (!value) {
				throw std::out_of_range("must not access nonexistent key");
			}
			return std::forward_like<decltype(self)>(*value);
		}

		[[nodiscard]] constexpr auto&& at(this auto&& self, xieite::is_ref_to<Key> auto&& key) noexcept(false) {
			return std::forward_like<decltype(self)>(self[XIEITE_FWD(key)]);
		}

		[[nodiscard]] constexpr bool has(xieite::is_ref_to<Key> auto&& key) const noexcept {
			return this->get_val(XIEITE_FWD(key));
		}

		[[nodiscard]] constexpr const std::array<std::pair<Key, Value>, length>& data() const noexcept {
			return this->array;
		}

	private:
		std::array<std::pair<Key, Value>, length> array;

		template<typename Map = std::unordered_map<Key, Value*, Hash, Cmp, Alloc>>
		[[nodiscard]] Map& get_map() const noexcept {
			static Map map = ([this] -> Map {
				Map map;
				map.reserve(this->array.size());
				for (const std::pair<Key, Value>& entry : this->array) {
					// Disregard constness here; it is properly handled in `operator[]()`
					map.emplace(std::make_pair(entry.first, const_cast<Value*>(std::addressof(entry.second))));
				}
				return map;
			})();
			return map;
		}

		[[nodiscard]] constexpr auto* get_val(this auto&& self, xieite::is_ref_to<Key> auto&& key) noexcept {
			if consteval {
				Cmp cmp;
				for (auto&& entry : self.array) {
					if (std::invoke(cmp, entry.first, key)) {
						return &entry.second;
					}
				}
				return nullptr;
			} else {
				return self.get_map().at(XIEITE_FWD(key));
			}
		}
	};
}

#endif
