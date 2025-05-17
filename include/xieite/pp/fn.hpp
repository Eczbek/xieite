#ifndef DETAIL_XIEITE_HEADER_PP_FN
#	define DETAIL_XIEITE_HEADER_PP_FN
#
#	include <cstddef>
#	include <type_traits>
#	include "../pp/any.hpp"
#	include "../pp/arrow.hpp"
#	include "../pp/comma.hpp"
#	include "../pp/diagnostic.hpp"
#	include "../pp/each.hpp"
#	include "../pp/fwd.hpp"
#	include "../pp/if.hpp"
#	include "../pp/opt.hpp"
#	include "../pp/seq.hpp"
#	include "../pp/unwrap.hpp"
#
#	define XIEITE_FN(...) ([]DETAIL_XIEITE_FN(0, 0, __VA_ARGS__))
#	define XIEITE_FN_THIS(...) ([]DETAIL_XIEITE_FN(0, 1, __VA_ARGS__))
#	define XIEITE_FN_LOCAL(captures_, ...) ([XIEITE_UNWRAP(captures_)]DETAIL_XIEITE_FN(XIEITE_ANY(captures_), 1, __VA_ARGS__))
#	define XIEITE_FN_MUT(captures_, ...) (DETAIL_XIEITE::FN::indirect { [XIEITE_UNWRAP(captures_)] mutable { return [&]DETAIL_XIEITE_FN(1, 1, __VA_ARGS__); } })

XIEITE_DIAGNOSTIC_OFF_CLANG("-Wdollar-in-identifier-extension")

#	define DETAIL_XIEITE_FN(has_captures_, this_, ...) \
	< \
		typename... __VA_OPT__($$ XIEITE_IF(this_)(XIEITE_COMMA() \
		typename $$this)(), \
		XIEITE_SEQ(16, DETAIL_XIEITE_FN_TEMPLATE_PARAM)) \
	>__VA_OPT__([[nodiscard]])(__VA_OPT__( \
		XIEITE_IF(this_)([[maybe_unused]] this $$this&&F $this XIEITE_COMMA())() \
		[[maybe_unused]]) auto&&... __VA_OPT__($) \
	) XIEITE_IF(has_captures_)()(XIEITE_OPT(__VA_ARGS__)(XIEITE_IF(this_)()(static))(static)()) \
	noexcept __VA_OPT__((requires(XIEITE_IF(this_)($$this&& $this XIEITE_COMMA())() XIEITE_SEQ(16, DETAIL_XIEITE_FN_PARAM)) { requires(noexcept(__VA_ARGS__)); }) \
	-> decltype(auto) \
	requires(requires(XIEITE_IF(this_)($$this&& $this XIEITE_COMMA())() XIEITE_SEQ(16, DETAIL_XIEITE_FN_PARAM)) { __VA_ARGS__; })) { \
		__VA_OPT__(XIEITE_EACH_DELIM(DETAIL_XIEITE_FN_REF,, XIEITE_SEQ(16)) \
		return __VA_ARGS__;) \
	}
#	define DETAIL_XIEITE_FN_TEMPLATE_PARAM(i_) typename $$##i_ = DETAIL_XIEITE::FN::t<i_, $$...>::type
#	define DETAIL_XIEITE_FN_PARAM(i_) decltype(DETAIL_XIEITE::FN::v<i_>(XIEITE_FWD($)...)) $##i_
#	define DETAIL_XIEITE_FN_REF(i_) [[maybe_unused]] auto&& $##i_ = DETAIL_XIEITE::FN::v<i_>(XIEITE_FWD($)...);

namespace DETAIL_XIEITE::FN {
	template<std::size_t idx> // Template parameter must be named here due to GCC bug (https://gcc.gnu.org/bugzilla/show_bug.cgi?id=117422)
	constexpr auto&& v(auto&&...) noexcept;

	struct unusable {
	public:
		template<std::size_t idx>
		[[nodiscard]] friend constexpr auto&& v(auto&&... args) noexcept {
			if constexpr (idx < sizeof...(args)) {
				return XIEITE_FWD(args...[idx]);
			} else {
				static constexpr DETAIL_XIEITE::FN::unusable unusable;
				return unusable;
			}
		}

	private:
		unusable() = default;
	};

	template<std::size_t idx, typename... Ts>
	struct t : decltype(([]<typename... Us> static {
		if constexpr (idx < sizeof...(Us)) {
			return std::type_identity<Us...[idx]>();
		} else {
			return std::type_identity<DETAIL_XIEITE::FN::unusable>();
		}
	}).template operator()<Ts...>()) {};

	// Workaround for GCC bug (https://gcc.gnu.org/bugzilla/show_bug.cgi?id=117061)
	template<typename Fn>
	struct indirect : Fn {
		template<typename... Ts>
		[[nodiscard]] constexpr auto operator()(this Fn& self, auto&&... args)
			XIEITE_ARROW(self.template operator()<Ts...>(XIEITE_FWD(args)...))
	};
}

#endif
