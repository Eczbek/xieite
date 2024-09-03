export module xieite:concepts.All;

export namespace xieite::concepts {
	template<typename Type, template<typename> typename... Traits>
	concept All = (... && Traits<Type>::value);
}
