#ifndef DETAIL_XIEITE_HEADER_TRAIT_HAS_NOEX_BRACE_CTOR
#	define DETAIL_XIEITE_HEADER_TRAIT_HAS_NOEX_BRACE_CTOR

namespace xieite {
	template<typename T, typename... Args>
	concept has_noex_brace_ctor = requires(Args... args) {
		requires(noexcept(T { args... }));
	};
}

#endif
