#ifndef DETAIL_XIEITE_HEADER_PP_FN
#	define DETAIL_XIEITE_HEADER_PP_FN
#
#	include "../pp/arrow.hpp"
#	include "../pp/comma.hpp"
#	include "../pp/diagnostic.hpp"
#	include "../pp/fwd.hpp"
#	include "../pp/if.hpp"
#	include "../pp/opt.hpp"
#	include "../pp/repeat.hpp"
#	include "../pp/unwrap.hpp"
#
#	define XIEITE_FN(...) DETAIL_XIEITE_FN(, 0, __VA_ARGS__)
#	define XIEITE_FN_THIS(...) DETAIL_XIEITE_FN(, 1, __VA_ARGS__)
#	define XIEITE_FN_LOCAL(_captures, ...) DETAIL_XIEITE_FN(_captures, 1, __VA_ARGS__)
#	define XIEITE_FN_MUT(_captures, ...) (DETAIL_XIEITE::FN::indirect { [XIEITE_UNWRAP(_captures)] mutable { return DETAIL_XIEITE_FN(&, 1, __VA_ARGS__); } })

XIEITE_DIAGNOSTIC_OFF_CLANG("-Wdollar-in-identifier-extension")

#	define DETAIL_XIEITE_FN(_captures, _this, ...) ([XIEITE_UNWRAP(_captures)]<class... __VA_OPT__($$ XIEITE_IF(_this)(XIEITE_COMMA() class $$this)())>__VA_OPT__([[nodiscard]])(__VA_OPT__(XIEITE_IF(_this)([[maybe_unused]] this $$this&& $this XIEITE_COMMA())()[[maybe_unused]]) auto&&... __VA_OPT__($)) XIEITE_OPT(_captures)()(XIEITE_OPT(__VA_ARGS__)(XIEITE_IF(_this)()(static))(static)) noexcept __VA_OPT__(DETAIL_XIEITE_FN_CHECK(_this, noexcept(__VA_ARGS__)) -> decltype(auto) requires DETAIL_XIEITE_FN_CHECK(_this, requires { __VA_ARGS__; })) DETAIL_XIEITE_FN_BODY(__VA_ARGS__))
#	define DETAIL_XIEITE_FN_CHECK(_this, ...) (requires(XIEITE_IF(_this)($$this&& $this XIEITE_COMMA())() decltype($)&&... $) { requires([](XIEITE_IF(_this)([[maybe_unused]] auto&& $this XIEITE_COMMA())() auto&&... $) static DETAIL_XIEITE_FN_BODY(__VA_ARGS__))(XIEITE_IF(_this)(XIEITE_FWD($this) XIEITE_COMMA())() XIEITE_FWD($)...); })
#	define DETAIL_XIEITE_FN_BODY(...) { __VA_OPT__(XIEITE_DIAGNOSTIC_PUSH_GCC() XIEITE_DIAGNOSTIC_PUSH_CLANG() XIEITE_DIAGNOSTIC_OFF_GCC("-Wunused-parameter") XIEITE_DIAGNOSTIC_OFF_CLANG("-Wunused-parameter") return ([&]<class $$0, class $$1, class $$2, class $$3, class $$4, class $$5, class $$6, class $$7, class $$8, class $$9, class $$A, class $$B, class $$C, class $$D, class $$E, class $$F>(auto&& $0, auto&& $1, auto&& $2, auto&& $3, auto&& $4, auto&& $5, auto&& $6, auto&& $7, auto&& $8, auto&& $9, auto&& $A, auto&& $B, auto&& $C, auto&& $D, auto&& $E, auto&& $F, auto...) mutable -> decltype(auto) { return __VA_ARGS__; }).template operator()<XIEITE_REPEAT(16, int)>(XIEITE_FWD($)..., XIEITE_REPEAT(16, 0)); XIEITE_DIAGNOSTIC_POP_GCC() XIEITE_DIAGNOSTIC_POP_CLANG()) }
#	define DETAIL_XIEITE_FN_TEMPLATE_PARAMS(_n) class $$##_n
#	define DETAIL_XIEITE_FN_PARAMS(_n) auto&& $##_n

namespace DETAIL_XIEITE::FN {
	template<typename Fn>
	struct indirect : Fn {
		template<typename... Ts>
		[[nodiscard]] constexpr auto operator()(this Fn& self, auto&&... args) XIEITE_ARROW(
			self.template operator()<Ts...>(XIEITE_FWD(args)...)
		)
	};
}

#endif
