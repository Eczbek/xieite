export module xieite:concepts.Satisfies;

export namespace xieite::concepts {
	template<auto validator, typename... Types>
	concept Satisfies = requires { validator.template operator()<Types...>(); };
}
