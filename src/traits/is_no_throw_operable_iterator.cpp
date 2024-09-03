export module xieite:traits.IsNoThrowOperableIterator;

import std;
import :concepts.NoThrowOperableIterator;

export namespace xieite::traits {
	template<typename Iterator>
	struct IsNoThrowOperableIterator
	: std::bool_constant<xieite::concepts::NoThrowOperableIterator<Iterator>> {};
}
