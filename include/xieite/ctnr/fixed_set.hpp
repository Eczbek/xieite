#ifndef DETAIL_XIEITE_HEADER_CTNR_FIXED_SET
#	define DETAIL_XIEITE_HEADER_CTNR_FIXED_SET
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
#	include "../ctnr/make_array.hpp"
#	include "../pp/fwd.hpp"
#	include "../trait/is_ref_to.hpp"

namespace xieite {
	template<typename K, std::size_t size, typename Hash = std::hash<K>, typename Cmp = std::ranges::equal_to, typename Alloc = std::allocator<K>>
	struct fixed_set {
	public:
		[[nodiscard]] fixed_set() = default;

		template<std::ranges::input_range R>
		requires(std::convertible_to<std::ranges::range_value_t<R>, K>)
		[[nodiscard]] explicit constexpr fixed_set(R&& keys) noexcept
		: array(xieite::make_array<K, size>(XIEITE_FWD(keys))) {}

		[[nodiscard]] explicit(false) constexpr fixed_set(std::initializer_list<K> keys) noexcept
		: array(xieite::make_array<K, size>(keys)) {}

		[[nodiscard]] constexpr bool operator[](xieite::is_ref_to<K> auto&& key) const noexcept {
			return this->has(XIEITE_FWD(key));
		}

		[[nodiscard]] constexpr bool has(xieite::is_ref_to<K> auto&& key) const noexcept {
			if consteval {
				return std::ranges::contains(this->array, XIEITE_FWD(key));
			} else {
				static const auto set = std::unordered_set<K, Hash, Cmp, Alloc>(std::from_range, this->array);
				return set.has(XIEITE_FWD(key));
			}
		}

		[[nodiscard]] constexpr const std::array<K, size>& data() const noexcept {
			return this->array;
		}

	private:
		std::array<K, size> array;
	};
}

#endif
