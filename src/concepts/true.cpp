export module xieite:concepts.True;

export namespace xieite::concepts {
	template<typename Trait>
	concept True = static_cast<bool>(Trait::value);
}
