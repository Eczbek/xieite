#pragma once

#include <gcufl/traits/isStreamable.hpp>
#include <iterator>
#include <sstream>
#include <string_view>


namespace gcufl::algorithms {
	template<std::forward_iterator I> requires(gcufl::traits::isStreamable<typename std::iterator_traits<I>::value_type>)
	std::stringstream streamify(I begin, const I end, const std::string_view delimiter = " ") noexcept {
		std::stringstream result;
		if (begin != end)
			result << *begin;
		while (++begin != end)
			result << delimiter << *begin;
		return result;
	}
}
