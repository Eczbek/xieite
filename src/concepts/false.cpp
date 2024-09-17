export module xieite:concepts.False;

export namespace xieite::concepts {
	template<typename Trait>
	concept False = !static_cast<bool>(Trait::value);
}
