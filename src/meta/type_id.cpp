export module xieite:type_id;

import std;
import :state;

using type_id_state = xieite::state<>;

export namespace xieite {
	template<typename>
	constexpr std::size_t type_id = type_id_state::advance();
}
