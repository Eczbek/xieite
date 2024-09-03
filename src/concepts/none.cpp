export module xieite:concepts.None;

export namespace xieite::concepts {
	template<typename Type, template<typename> typename... Traits>
	concept None = (... && !Traits<Type>::value);
}
