#ifndef XIEITE_HEADER_MACROS_LOOP
#	define XIEITE_HEADER_MACROS_LOOP

#	include "../macros/unused.hpp"

namespace xieite::detail {
	struct LoopState {
		int flag = 2;
		bool broke = false;

		friend constexpr xieite::detail::LoopState operator,(auto&&, xieite::detail::LoopState state) noexcept {
			return state;
		}
	};
}

#	define XIEITE_LOOP_FOR(...) \
		for (xieite::detail::LoopState XIEITE_DETAIL_LOOP_STATE; XIEITE_DETAIL_LOOP_STATE.flag && !XIEITE_DETAIL_LOOP_STATE.broke; --XIEITE_DETAIL_LOOP_STATE.flag) \
			if ((XIEITE_DETAIL_LOOP_STATE.flag == 2) && !XIEITE_DETAIL_LOOP_STATE.broke) \
				for (__VA_ARGS__, ((XIEITE_DETAIL_LOOP_STATE.broke = true), XIEITE_DETAIL_LOOP_STATE)) \
					if ((XIEITE_DETAIL_LOOP_STATE.broke = false)); \
					else

#	define XIEITE_LOOP_WHILE(...) XIEITE_LOOP_FOR(; __VA_ARGS__; XIEITE_UNUSED())

#endif

// Blatantly stolen from m1lkweed (https://gist.github.com/m1lkweed/3be672402c43ac5697f1e29bcb79e004)
