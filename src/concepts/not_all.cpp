export module xieite:concepts.NotAll;

export namespace xieite::concepts {
	template<typename Type, template<typename> typename... Traits>
	concept NotAll = (... || !Traits<Type>::value);
}
