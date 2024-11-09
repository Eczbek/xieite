export module xieite:is_satisfd;

export namespace xieite {
	template<auto fn, typename... Ts>
	concept is_satisfd = requires { fn.template operator()<Ts...>(); };
}
