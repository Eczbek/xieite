export module xieite:seq_for;

import :make_seq;

export namespace xieite {
	template<typename... Ts>
	constexpr auto seq_for = xieite::make_seq<sizeof...(Ts)>;
}
