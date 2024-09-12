export module xieite:concepts.BraceInitializable;

export namespace xieite::concepts {
	template<typename Type, typename... Arguments>
	concept BraceInitializable = requires(Arguments... arguments) { Type { arguments... }; };
}
