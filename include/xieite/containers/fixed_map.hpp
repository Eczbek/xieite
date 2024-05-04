#ifndef XIEITE_HEADER_CONTAINERS_FIXED_MAP
#	define XIEITE_HEADER_CONTAINERS_FIXED_MAP

#	include <array>
#	include <concepts>
#	include <cstddef>
#	include <functional>
#	include <initializer_list>
#	include <memory>
#	include <optional>
#	include <type_traits>
#	include <unordered_map>
#	include <utility>
#	include "../concepts/no_throw_invocable.hpp"
#	include "../concepts/range_of.hpp"
#	include "../containers/make_array.hpp"
#	include "../macros/forward.hpp"
#	include "../types/maybe_constant.hpp"

namespace xieite::containers {
	template<typename Key_, typename Value_, std::size_t size_, typename Hash_ = std::hash<Key_>, typename KeyComparator_ = std::equal_to<Key_>, typename Allocator_ = std::allocator<std::pair<const Key_, Value_*>>>
	struct FixedMap {
	public:
		constexpr FixedMap() noexcept = default;

		template<xieite::concepts::RangeOf<std::pair<Key_, Value_>> Range_>
		constexpr FixedMap(Range_&& entries) noexcept
		: array(xieite::containers::makeArray<std::pair<Key_, Value_>, size_>(XIEITE_FORWARD(entries))) {}

		constexpr FixedMap(const std::initializer_list<std::pair<Key_, Value_>> entries) noexcept
		: array(xieite::containers::makeArray<std::pair<Key_, Value_>, size_>(entries)) {}

		template<typename Self_, std::convertible_to<Key_> KeyReference_>
		[[nodiscard]] constexpr std::optional<std::reference_wrapper<xieite::types::MaybeConstant<Value_, std::is_const_v<Self_>>>> operator[](this Self_&& self, KeyReference_&& key) noexcept {
			return XIEITE_FORWARD(self).getValue(XIEITE_FORWARD(key));
		}

		template<typename Self_, std::convertible_to<Key_> KeyReference_>
		[[nodiscard]] constexpr std::optional<std::reference_wrapper<xieite::types::MaybeConstant<Value_, std::is_const_v<Self_>>>> at(this Self_&& self, KeyReference_&& key) noexcept {
			return XIEITE_FORWARD(self).getValue(XIEITE_FORWARD(key));
		}

		template<std::convertible_to<Key_> KeyReference_>
		[[nodiscard]] constexpr bool contains(KeyReference_&& key) const noexcept {
			if consteval {
				for (const std::pair<Key_, Value_>& entry : this->array) {
					if (std::invoke(KeyComparator_(), entry.first, XIEITE_FORWARD(key))) {
						return true;
					}
				}
				return false;
			} else {
				return this->getMap().contains(XIEITE_FORWARD(key));
			}
		}

		[[nodiscard]] constexpr const std::array<std::pair<Key_, Value_>, size_>& data() const noexcept {
			return this->array;
		}

	private:
		mutable std::array<std::pair<Key_, Value_>, size_> array;

		[[nodiscard]] std::unordered_map<Key_, Value_*, Hash_, KeyComparator_, Allocator_>& getMap() const noexcept {
			using Map = std::unordered_map<Key_, Value_*, Hash_, KeyComparator_, Allocator_>;
			static Map map = ([this] {
				Map map;
				map.reserve(this->array.size_());
				for (std::pair<Key_, Value_>& entry : this->array) {
					map.emplace(std::make_pair(entry.first, &entry.second));
				}
				return map;
			})();
			return map;
		}

		template<std::convertible_to<Key_> KeyReference_>
		[[nodiscard]] constexpr std::optional<std::reference_wrapper<Value_>> getValue(KeyReference_&& key) const noexcept {
			if consteval {
				for (std::pair<Key_, Value_>& entry : this->array) {
					if (std::invoke(KeyComparator_(), entry.first, key)) {
						return entry.second;
					}
				}
				return std::nullopt;
			} else {
				return *this->getMap().at(key);
			}
		}
	};
}

#endif
