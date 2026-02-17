#ifndef DETAIL_XTE_HEADER_PREPROC_LAMBDA
#	define DETAIL_XTE_HEADER_PREPROC_LAMBDA
#
#	include "../preproc/any.hpp"
#	include "../preproc/diagnostic.hpp"
#	include "../preproc/fwd.hpp"
#	include "../preproc/if.hpp"
#
#	define XTE_LAMBDA(...) ([]DETAIL_XTE_LAMBDA_DECL(0, 0, __VA_ARGS__))
#	define XTE_LAMBDA_THIS(...) ([]DETAIL_XTE_LAMBDA_DECL(0, 1, __VA_ARGS__))
#	define XTE_LAMBDA_LOCAL(...) ([&]DETAIL_XTE_LAMBDA_DECL(1, 1, __VA_ARGS__))

XTE_DIAGNOSTIC_OFF_CLANG("-Wdollar-in-identifier-extension")

#	define DETAIL_XTE_LAMBDA_DECL(_captures, _this, ...) <decltype(auto)... __VA_OPT__($$ XTE_IIF(_this)(, typename $$this)())>__VA_OPT__([[nodiscard]])(__VA_OPT__(XTE_IIF(_this)([[maybe_unused]] this $$this&& $this,)() [[maybe_unused]]) auto&&... __VA_OPT__($)) XTE_IIF(_captures)()(XTE_IF(XTE_ANY(__VA_ARGS__))(XTE_IIF(_this)()(static))(static)) noexcept __VA_OPT__(DETAIL_XTE_LAMBDA_CHECK(_this, noexcept(__VA_ARGS__)) -> decltype(auto) requires DETAIL_XTE_LAMBDA_CHECK(_this, requires { __VA_ARGS__; })) DETAIL_XTE_LAMBDA_BODY(__VA_ARGS__)
#	define DETAIL_XTE_LAMBDA_CHECK(_this, ...) (requires (XTE_IIF(_this)($$this&& $this,)() decltype($)&&... $) { requires ([](XTE_IIF(_this)([[maybe_unused]] auto&& $this,)() auto&&... $) DETAIL_XTE_LAMBDA_BODY(__VA_ARGS__))(XTE_IIF(_this)(XTE_FWD($this),)() XTE_FWD($)...); })
#	define DETAIL_XTE_LAMBDA_BODY(...) { __VA_OPT__(XTE_DIAGNOSTIC_PUSH_GCC(OFF, "-Wunused-parameter") return ([&]<decltype(auto) $$0, decltype(auto) $$1, decltype(auto) $$2, decltype(auto) $$3, decltype(auto) $$4, decltype(auto) $$5, decltype(auto) $$6, decltype(auto) $$7, decltype(auto) $$8, decltype(auto) $$9, decltype(auto) $$A, decltype(auto) $$B, decltype(auto) $$C, decltype(auto) $$D, decltype(auto) $$E, decltype(auto) $$F, decltype(auto)...>(auto&& $0, auto&& $1, auto&& $2, auto&& $3, auto&& $4, auto&& $5, auto&& $6, auto&& $7, auto&& $8, auto&& $9, auto&& $A, auto&& $B, auto&& $C, auto&& $D, auto&& $E, auto&& $F, auto&&...) mutable -> decltype(auto) { return __VA_ARGS__; }).template operator()<$$..., 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0>(XTE_FWD($)..., 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0); XTE_DIAGNOSTIC_POP_GCC()) }

#endif
