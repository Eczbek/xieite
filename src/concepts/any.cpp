export module xieite:concepts.Any;

export namespace xieite::concepts {
	template<typename Type, template<typename> typename... Traits>
	concept Any = (... || Traits<Type>::value);
}
