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
	template<typename Value, std::size_t length>
	[[nodiscard]] constexpr auto apply_array(auto&& fn, const std::array<Value, length>& array)
		XIEITE_ARROW(xieite::unroll<length>(
			[]<std::size_t... i>(auto&& fn, const auto& array)
				XIEITE_ARROW(std::invoke(XIEITE_FWD(fn), array[i]...)),
			XIEITE_FWD(fn),
			array
		))

	template<typename T, typename Value, std::size_t length>
	[[nodiscard]] constexpr T apply_array(const std::array<Value, length>& array)
		XIEITE_ARROW_RET(xieite::apply_array(XIEITE_LIFT(T), array))
}

#endif
