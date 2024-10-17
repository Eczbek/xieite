export module xieite:containers.makeSparseArray;

import std;
import :bits.size;
import :types.arity;

export namespace xieite::containers {
	template<std::integral Key, typename Value, typename Range = std::initializer_list<Pair<Key, Value>>>
	requires((std::numeric_limits<Key>::digits <= 16) && (xieite::types::arity<std::ranges::range_value_t<Range>> == 2))
	[[nodiscard]] constexpr auto makeSparseArray(Range&& entries) noexcept {
		auto result = std::array<Value, (1uz << xieite::bits::size<Key>)>();
		for (const auto& [key, value] : entries) {
			result[xieite::math::signCast<std::size_t>(static_cast<Key>(std::forward_like<Range>(key)))] = static_cast<Value>(std::forward_like<Range>(value));
		}
		return result;
	}
}
