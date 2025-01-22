export module xieite:type_id;

import std;
import :state;

namespace detail::type_id {
	using state = xieite::state<>;
}

export namespace xieite {
	template<typename>
	constexpr std::size_t type_id = detail::type_id::state::advance();
}
