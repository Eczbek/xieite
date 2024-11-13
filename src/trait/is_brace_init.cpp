export module xieite:is_brace_init;

export namespace xieite {
	template<typename T, typename... Args>
	concept is_brace_init = requires(Args... args) { T { args... }; };
}
