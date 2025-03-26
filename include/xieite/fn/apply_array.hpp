#ifndef DETAIL_XIEITE_HEADER_FN_APPLY_ARRAY
#	define DETAIL_XIEITE_HEADER_FN_APPLY_ARRAY
#
#	include <array>
#	include <cstddef>
#	include <functional>
#	include "../fn/unroll.hpp"
#	include "../pp/arrow.hpp"
#	include "../pp/lift.hpp"

namespace xieite {
	template<typename F, typename V, std::size_t size>
	[[nodiscard]] constexpr auto apply_array(F&& fn, const std::array<V, size>& array)
		XIEITE_ARROW(xieite::unroll<size>(
			[]<std::size_t... i>(F&& fn, const auto& array) static
				XIEITE_ARROW(std::invoke(XIEITE_FWD(fn), array[i]...)),
			XIEITE_FWD(fn),
			array
		))

	template<typename T, typename V, std::size_t size>
	[[nodiscard]] constexpr T apply_array(const std::array<V, size>& array)
		XIEITE_ARROW_RET(xieite::apply_array(XIEITE_LIFT(T), array))
}

#endif
