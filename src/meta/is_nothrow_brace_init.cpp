export module xieite:is_nothrow_brace_init;

export namespace xieite {
	template<typename T, typename... Args>
	concept is_nothrow_brace_init = requires {
		requires(noexcept(T { args... }));
	};
}
