#pragma once

#include <cstddef>
#include <type_traits>
#include "../pp/arrow.hpp"
#include "../pp/comma.hpp"
#include "../pp/diag.hpp"
#include "../pp/each.hpp"
#include "../pp/fwd.hpp"
#include "../pp/if.hpp"
#include "../pp/seq.hpp"
#include "../pp/unwrap.hpp"

#define XIEITE_FN(...) ([]DETAIL_XIEITE_FN(0, __VA_ARGS__))
#define XIEITE_FN_THIS(...) ([]DETAIL_XIEITE_FN(1, __VA_ARGS__))
#define XIEITE_FN_LOCAL(...) ([&]DETAIL_XIEITE_FN(1, __VA_ARGS__))
#define XIEITE_FN_MUT(captures_, ...) (DETAIL_XIEITE::FN::indirect { [XIEITE_UNWRAP(captures_)] mutable { return [&]DETAIL_XIEITE_FN(1, __VA_ARGS__); } })

XIEITE_DIAG_OFF_CLANG("-Wdollar-in-identifier-extension")

#define DETAIL_XIEITE_FN(this_, ...) \
	< \
		typename... $$, \
		XIEITE_IF(this_)(typename $$this XIEITE_COMMA()) \
		XIEITE_EACH(DETAIL_XIEITE_FN_TEMPLATE_PARAM, XIEITE_SEQ(256)) \
	>[[nodiscard]]( \
		XIEITE_IF(this_)([[maybe_unused]] this $$this&& $this XIEITE_COMMA()) \
		auto&&... $ \
	) XIEITE_IF(this_)(, static) noexcept(requires ( \
		XIEITE_IF(this_)($$this&& $this XIEITE_COMMA()) \
		XIEITE_EACH(DETAIL_XIEITE_FN_PARAM, XIEITE_SEQ(256)) \
	) { requires(noexcept(__VA_ARGS__)); }) \
	-> decltype(auto) \
	requires(requires ( \
		XIEITE_IF(this_)($$this&& $this XIEITE_COMMA()) \
		XIEITE_EACH(DETAIL_XIEITE_FN_PARAM, XIEITE_SEQ(256)) \
	) { __VA_ARGS__; }) { \
		XIEITE_EACH_DELIM(DETAIL_XIEITE_FN_REF,, XIEITE_SEQ(256)) \
		return __VA_ARGS__; \
	}
#define DETAIL_XIEITE_FN_TEMPLATE_PARAM(i_) typename $$##i_ = DETAIL_XIEITE::FN::t<i_, $$...>
#define DETAIL_XIEITE_FN_PARAM(i_) decltype(DETAIL_XIEITE::FN::v<i_>(XIEITE_FWD($)...)) $##i_
#define DETAIL_XIEITE_FN_REF(i_) [[maybe_unused]] auto&& $##i_ = DETAIL_XIEITE::FN::v<i_>(XIEITE_FWD($)...);

namespace DETAIL_XIEITE::FN {
	// Template parameter must be named here due to GCC bug
	// https://gcc.gnu.org/bugzilla/show_bug.cgi?id=117422
	template<std::size_t idx>
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
	using t = decltype(([]<typename... Us> static {
		if constexpr (idx < sizeof...(Us)) {
			return std::type_identity<Us...[idx]>();
		} else {
			return std::type_identity<DETAIL_XIEITE::FN::unusable>();
		}
	}).template operator()<Ts...>())::type;

	// A wrapper is required as a workaround due to GCC bug
	// https://gcc.gnu.org/bugzilla/show_bug.cgi?id=117061
	template<typename F>
	struct indirect : F {
		template<typename... Ts>
		constexpr auto operator()(this auto&& self, auto&&... args)
			XIEITE_ARROW(static_cast<F&>(self)().template operator()<Ts...>(XIEITE_FWD(args)...))
	};
}
