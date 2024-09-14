export module xieite:functors.Visitor;

export namespace xieite::functors {
	template<typename... Bases>
	struct Visitor
	: Bases... {
		using Bases::operator()...;
	};

	template<typename... Bases>
	Visitor(Bases...) -> xieite::functors::Visitor<Bases...>;
}
