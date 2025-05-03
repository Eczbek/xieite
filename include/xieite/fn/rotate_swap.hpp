#ifndef DETAIL_XIEITE_HEADER_FN_ROTATE_SWAP
#	define DETAIL_XIEITE_HEADER_FN_ROTATE_SWAP
#
#	include <cstddef>
#	include <tuple>
#	include <utility>
#	include "../fn/repeat.hpp"
#	include "../trait/has_noex_mv_assign.hpp"
#	include "../trait/has_noex_mv_ctor.hpp"

namespace xieite {
	template<std::size_t distance = 1, typename... Args>
	constexpr std::tuple<Args&...> rotate_swap(Args&... args)
	noexcept((... && (xieite::has_noex_mv_ctor<Args> && xieite::has_noex_mv_assign<Args>))) {
		static constexpr std::size_t size = sizeof...(Args);
		if constexpr (size && (distance % size)) {
			static constexpr std::size_t wrapped = distance % size;
			if constexpr ((wrapped == 1) || (size % wrapped)) {
				auto temp = std::move(args...[0]);
				xieite::repeat<(size - 1)>([&args...]<std::size_t i> -> void {
					args...[i * wrapped % size] = std::move(args...[(i * wrapped % size + wrapped) % size]);
				});
				args...[size - wrapped] = std::move(temp);
			} else {
				xieite::repeat<wrapped>([&args...]<std::size_t i> -> void {
					auto temp = std::move(args...[i]);
					xieite::repeat<(size / wrapped)>([&args...]<std::size_t j> -> void {
						args...[i + j * wrapped] = std::move(args...[(i + j * wrapped + wrapped) % size]);
					});
					args...[size - wrapped + i] = std::move(temp);
				});
			}
		}
		return std::tie(args...);
	}
}

#endif
