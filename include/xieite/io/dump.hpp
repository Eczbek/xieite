#ifndef DETAIL_XIEITE_HEADER_IO_DUMP
#	define DETAIL_XIEITE_HEADER_IO_DUMP
#
#	include <cstddef>
#	include <format>
#	include <print>
#	include <string_view>
#	include "../data/fixed_array.hpp"
#	include "../data/fixed_str.hpp"
#	include "../fn/unroll.hpp"
#	include "../pp/fwd.hpp"

namespace xieite {
	template<xieite::fixed_str delim = " ", bool newline = true>
	void dump(auto&&... args) noexcept {
		static constexpr auto segment = xieite::fixed_str("{}") + delim;
		static constexpr std::size_t size = sizeof...(args) * segment.size() - (!!sizeof...(args) * delim.size());
		static constexpr auto fmt = xieite::unroll<size>([]<std::size_t... i> static {
			return xieite::fixed_array { segment[i % segment.size()]... };
		});
		if constexpr (newline) {
			std::println(std::format_string<decltype(args)...>(std::string_view(fmt.data(), size)), XIEITE_FWD(args)...);
		} else {
			std::print(std::format_string<decltype(args)...>(std::string_view(fmt.data(), size)), XIEITE_FWD(args)...);
		}
	}
}

#endif
