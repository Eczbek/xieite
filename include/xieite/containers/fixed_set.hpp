#ifndef XIEITE_HEADER_CONTAINERS_FIXED_SET
#	define XIEITE_HEADER_CONTAINERS_FIXED_SET

#	include <algorithm>
#	include <array>
#	include <concepts>
#	include <cstddef>
#	include <functional>
#	include <initializer_list>
#	include <memory>
#	include <unordered_set>
#	include "../concepts/range_of.hpp"
#	include "../containers/make_array.hpp"
#	include "../macros/forward.hpp"

namespace xieite::containers {
	template<typename Key_, std::size_t size_, typename Hash_ = std::hash<Key_>, typename KeyComparator_ = std::equal_to<Key_>, typename Allocator_ = std::allocator<Key_>>
	struct FixedSet {
	public:
		constexpr FixedSet() noexcept = default;

		template<xieite::concepts::RangeOf<Key_> Range_>
		constexpr FixedSet(Range_&& keys) noexcept
		: array(xieite::containers::makeArray<Key_, size_>(XIEITE_FORWARD(keys))) {}

		constexpr FixedSet(const std::initializer_list<Key_> keys) noexcept
		: array(xieite::containers::makeArray<Key_, size_>(keys)) {}

		template<std::convertible_to<Key_> KeyReference_>
		[[nodiscard]] constexpr bool operator[](KeyReference_&& key) const noexcept {
			return this->contains(XIEITE_FORWARD(key));
		}

		template<std::convertible_to<Key_> KeyReference_>
		[[nodiscard]] constexpr bool contains(KeyReference_&& key) const noexcept {
			if consteval {
				return std::ranges::find(this->array, XIEITE_FORWARD(key)) != this->array.end();
			} else {
				static const auto set = std::unordered_set<Key_, Hash_, KeyComparator_, Allocator_>(this->array.begin(), this->array.end());
				return set.contains(XIEITE_FORWARD(key));
			}
		}

		[[nodiscard]] constexpr const std::array<Key_, size_>& data() const noexcept {
			return this->array;
		}

	private:
		mutable std::array<Key_, size_> array;
	};
}

#endif
