#ifndef DETAIL_XIEITE_HEADER_TRAIT_HAS_BRACE_INIT
#	define DETAIL_XIEITE_HEADER_TRAIT_HAS_BRACE_INIT

namespace xieite {
	template<typename T, typename... Args>
	concept has_brace_init = requires(Args... args) { T { args... }; };
}

#endif
