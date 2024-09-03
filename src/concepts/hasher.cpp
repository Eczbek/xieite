export module xieite:concepts.Hasher;

import :concepts.Invocable;

export namespace xieite::concepts {
	template<typename Type, typename Argument>
	concept Hasher = xieite::concepts::Invocable<Type, std::size_t(Argument)>;
}
