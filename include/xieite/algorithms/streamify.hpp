#pragma once
#include <iterator>
#include <sstream>
#include <string_view>
#include <xieite/concepts/StreamableOut.hpp>

namespace xieite::algorithms {
	template<std::forward_iterator I>
	requires(xieite::concepts::StreamableOut<typename std::iterator_traits<I>::value_type>)
	[[nodiscard]]
	constexpr std::stringstream streamify(I begin, const I end, const std::string_view delimiter = " ") noexcept {
		std::stringstream result;
		if (begin != end)
			result << *begin;
		while (++begin != end)
			result << delimiter << *begin;
		return result;
	}
}
