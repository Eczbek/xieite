#ifndef DETAIL_XIEITE_HEADER_IO_DUMP
#	define DETAIL_XIEITE_HEADER_IO_DUMP
#
#	include <cstddef>
#	include <format>
#	include <print>
#	include <string_view>
#	include "../ctnr/fixed_array.hpp"
#	include "../ctnr/fixed_str.hpp"
#	include "../fn/unroll.hpp"
#	include "../pp/fwd.hpp"

namespace xieite {
	template<xieite::fixed_str delim = " ", typename... Args>
	void dump(Args&&... args) noexcept {
		static constexpr auto fmt = xieite::fixed_str("{}") + delim;
		static constexpr std::size_t size = sizeof...(Args) * fmt.size() - (!!sizeof...(Args) * delim.size());
		static constexpr auto data = xieite::unroll<size>([]<std::size_t... i> static {
			return xieite::fixed_array { fmt[i % fmt.size()]... };
		});
		std::println(std::format_string<Args...>(std::string_view(data.data(), size)), XIEITE_FWD(args)...);
	}
}

#endif
