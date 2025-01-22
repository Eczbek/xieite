export module xieite:is_same;

import std;

export namespace xieite {
	template<typename... Ts>
	concept is_same = (... && std::same_as<Ts...[0], Ts>);
}
