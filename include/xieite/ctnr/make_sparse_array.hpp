#ifndef DETAIL_XIEITE_HEADER_CTNR_MAKE_SPARSE_ARRAY
#	define DETAIL_XIEITE_HEADER_CTNR_MAKE_SPARSE_ARRAY
#
#	include <array>
#	include <concepts>
#	include <cstddef>
#	include <functional>
#	include <initializer_list>
#	include <ranges>
#	include <type_traits>
#	include <utility>
#	include "../math/bit_size.hpp"
#	include "../math/sign_cast.hpp"
#	include "../meta/arity.hpp"
#	include "../pp/fwd.hpp"
#	include "../trait/is_invoc.hpp"
#	include "../trait/is_noex_invoc.hpp"

namespace xieite {
	template<typename K, typename V, std::ranges::input_range R = std::initializer_list<std::pair<K, V>>, xieite::is_invoc<std::pair<K, V>(std::ranges::range_common_reference_t<R>)> F = std::identity>
	requires(std::integral<K> || std::is_enum_v<K>)
	[[nodiscard]] constexpr std::array<V, (1uz << xieite::bit_size<K>)> make_sparse_array(R&& entries, F&& fn = {})
	noexcept(xieite::is_noex_invoc<F, std::pair<K, V>(std::ranges::range_common_reference_t<R>)>) {
		static_assert(xieite::bit_size<K> <= 16, "key type must be reasonably small");
		static_assert(xieite::arity<std::ranges::range_value_t<R>> == 2, "range entries must each have one key and one value");
		auto result = std::array<V, (1uz << xieite::bit_size<K>)>();
		for (auto&& entry : XIEITE_FWD(entries)) {
			auto&& [key, value] = std::invoke(fn, XIEITE_FWD(entry));
			result[xieite::sign_cast<std::size_t>(std::to_underlying(key))] = XIEITE_FWD(value);
		}
		return result;
	}
}

#endif
