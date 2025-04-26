#ifndef DETAIL_XIEITE_HEADER_DATA_FIXED_SET
#	define DETAIL_XIEITE_HEADER_DATA_FIXED_SET
#
#	include <algorithm>
#	include <array>
#	include <concepts>
#	include <cstddef>
#	include <functional>
#	include <initializer_list>
#	include <memory>
#	include <ranges>
#	include <unordered_set>
#	include "../data/make_array.hpp"
#	include "../pp/fwd.hpp"
#	include "../trait/is_ref_to.hpp"

namespace xieite {
	template<typename Key, std::size_t length, typename Hash = std::hash<Key>, typename Cmp = std::ranges::equal_to, typename Alloc = std::allocator<Key>>
	struct fixed_set {
	public:
		[[nodiscard]] fixed_set() = default;

		template<std::ranges::input_range Range>
		requires(std::convertible_to<std::ranges::range_value_t<Range>, Key>)
		[[nodiscard]] explicit constexpr fixed_set(Range&& keys) noexcept
		: array(xieite::make_array<Key, length>(XIEITE_FWD(keys))) {}

		[[nodiscard]] explicit(false) constexpr fixed_set(std::initializer_list<Key> keys) noexcept
		: array(xieite::make_array<Key, length>(keys)) {}

		[[nodiscard]] constexpr bool operator[](xieite::is_ref_to<Key> auto&& key) const noexcept {
			return this->has(XIEITE_FWD(key));
		}

		[[nodiscard]] constexpr bool has(xieite::is_ref_to<Key> auto&& key) const noexcept {
			if consteval {
				return std::ranges::contains(this->array, XIEITE_FWD(key));
			} else {
				static const auto set = std::unordered_set<Key, Hash, Cmp, Alloc>(std::from_range, this->array);
				return set.has(XIEITE_FWD(key));
			}
		}

		[[nodiscard]] constexpr const std::array<Key, length>& data() const noexcept {
			return this->array;
		}

	private:
		std::array<Key, length> array;
	};
}

#endif
