export module xieite:is_conv_to;

import std;

export namespace xieite {
	template<typename T, typename... Us>
	concept is_conv_to = (... && std::convertible_to<T, Us>);
}
