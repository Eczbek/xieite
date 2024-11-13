export module xieite:is_hasher;

import :is_invoc;

export namespace xieite {
	template<typename T, typename Arg>
	concept is_hasher = xieite::is_invoc<T, std::size_t(Arg)>;
}
