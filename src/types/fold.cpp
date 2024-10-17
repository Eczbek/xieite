export module xieite:types.Fold;

import std;

template<auto transformer, typename Result>
struct FoldHelper
: Result {
	template<typename Next>
	FoldHelper<transformer, decltype(transformer.template operator()<Next::type, Result::type>())> operator->*(Next) const;
};

export namespace xieite::types {
	template<auto transformer, typename First, typename... Rest>
	using Fold = decltype((FoldHelper<transformer, std::type_identity<First>>()->*...->*std::type_identity<Rest>()))::type;
}
