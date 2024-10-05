export module xieite:functors.Visitor;

export namespace xieite::functors {
	template<typename... Functors>
	struct Visitor
	: Functors... {
		using Functors::operator()...;
	};

	template<typename... Functors>
	Visitor(Functors...) -> Visitor<Functors...>;
}
