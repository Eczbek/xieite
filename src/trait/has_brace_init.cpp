export module xieite:has_brace_init;

export namespace xieite {
	template<typename T, typename... Args>
	concept has_brace_init = requires (Args... args) { T { args... }; };
}
