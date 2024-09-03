export module xieite:traits.IsNoThrowOperableRange;

import std;
import :concepts.NoThrowOperableRange;

export namespace xieite::traits {
	template<typename Range>
	struct IsNoThrowOperableRange
	: std::bool_constant<xieite::concepts::NoThrowOperableRange<Range>> {};
}
