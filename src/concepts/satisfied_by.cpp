export module xieite:concepts.SatisfiedBy;

export namespace xieite::concepts {
	template<auto validator, typename... Types>
	concept SatisfiedBy = requires { validator.template operator()<Types...>(); };
}
