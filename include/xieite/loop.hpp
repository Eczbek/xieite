#pragma once

#include <xieite/forward.hpp>

#define XIEITE_LOOP_FOR(...) \
	for (struct { \
		int flag = 2; \
		bool broke = false; \
		constexpr auto chainable(auto&&...) const noexcept { \
			struct Chainable { \
				constexpr void operator+() const noexcept {} \
				\
				/* discardable */ friend constexpr auto&& operator+(auto&& value, Chainable) noexcept { \
					return XIEITE_FORWARD(value); \
				} \
			}; \
			return Chainable(); \
		}
	} XIEITE_DETAIL_LOOP_STATE; XIEITE_DETAIL_LOOP_STATE.flag && !XIEITE_DETAIL_LOOP_STATE.broke; --XIEITE_DETAIL_LOOP_STATE.flag) \
		if ((XIEITE_DETAIL_LOOP_STATE.flag == 2) && !XIEITE_DETAIL_LOOP_STATE.broke) \
			for (__VA_ARGS__ + XIEITE_DETAIL_LOOP_STATE.chainable(XIEITE_DETAIL_LOOP_STATE.broke = true)) \
				if ((XIEITE_DETAIL_LOOP_STATE.broke = false)); \
				else

#define XIEITE_LOOP_WHILE(...) XIEITE_LOOP_FOR(; static_cast<bool>(__VA_ARGS__);)

// Blatantly stolen from m1lkweed (https://gist.github.com/m1lkweed/3be672402c43ac5697f1e29bcb79e004)
