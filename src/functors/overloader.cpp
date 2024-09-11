export module xieite:functors.Overloader;

export namespace xieite::functors {
	template<typename... Functors>
	struct Overloader
	: Functors... {
		using Functors::operator()...;
	};

	template<typename... Functors>
	Overloader(Functors...) -> xieite::functors::Overloader<Functors...>;
}
