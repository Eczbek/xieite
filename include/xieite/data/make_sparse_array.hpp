#ifndef DETAIL_XIEITE_HEADER_DATA_MAKE_SPARSE_ARRAY
#	define DETAIL_XIEITE_HEADER_DATA_MAKE_SPARSE_ARRAY
#
#	include <array>
#	include <concepts>
#	include <cstddef>
#	include <functional>
#	include <initializer_list>
#	include <ranges>
#	include "../math/bit_size.hpp"
#	include "../math/sign_cast.hpp"
#	include "../math/to_underlying.hpp"
#	include "../meta/arity.hpp"
#	include "../pp/fwd.hpp"
#	include "../trait/is_enum.hpp"
#	include "../trait/is_invoc.hpp"
#	include "../trait/is_noex_invoc.hpp"

namespace xieite {
	template<typename Key, typename Value, std::ranges::input_range Range = std::initializer_list<std::pair<Key, Value>>, xieite::is_invoc<std::pair<Key, Value>(std::ranges::range_common_reference_t<Range>)> Conv = std::identity>
	requires(std::integral<Key> || xieite::is_enum<Key>)
	[[nodiscard]] constexpr std::array<Value, (1uz << xieite::bit_size<Key>)> make_sparse_array(Range&& entries, Conv&& conv = {})
	noexcept(xieite::is_noex_invoc<Conv, std::pair<Key, Value>(std::ranges::range_common_reference_t<Range>)>) {
		static_assert(xieite::bit_size<Key> <= 16, "key type must be reasonably small");
		static_assert(xieite::arity<std::ranges::range_value_t<Range>> == 2, "range entries must each have one key and one value");
		auto result = std::array<Value, (1uz << xieite::bit_size<Key>)>();
		for (auto&& entry : XIEITE_FWD(entries)) {
			auto&& [key, value] = std::invoke(conv, XIEITE_FWD(entry));
			result[xieite::sign_cast<std::size_t>(xieite::to_underlying(key))] = XIEITE_FWD(value);
		}
		return result;
	}
}

#endif
