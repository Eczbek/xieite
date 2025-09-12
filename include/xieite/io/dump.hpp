#ifndef DETAIL_XIEITE_HEADER_IO_DUMP
#	define DETAIL_XIEITE_HEADER_IO_DUMP
#
#	include <cstddef>
#	include <cstdio>
#	include <format>
#	include <print>
#	include <string_view>
#	include "../data/fixed_array.hpp"
#	include "../data/fixed_str.hpp"
#	include "../fn/unroll.hpp"
#	include "../pp/fwd.hpp"

using namespace std::literals;

namespace xieite {
	template<xieite::fixed_str delim = " ", bool newline = true, typename... Args>
	void dump(std::FILE* file, Args&&... args) noexcept {
		static constexpr std::size_t fmt_size = ([] -> std::size_t {
			std::size_t offset = 0;
			for (char c : delim.view()) {
				offset += "{}"sv.contains(c);
			}
			return sizeof...(Args) * 2 + (sizeof...(Args) - !!sizeof...(Args)) * (delim.size() + offset);
		})();
		static constexpr auto fmt = xieite::unroll<fmt_size>([]<std::size_t... i> {
			std::size_t j = -1uz;
			bool flag = false;
			return xieite::fixed_array { (void(i), (((j += !flag) %= (2 + delim.size())) < 2) ? "{}"[j] : delim[j - 2 - (flag = !flag && (j > 2) && "{}"sv.contains(delim[j - 3]))])... };
		});
		if constexpr (newline) {
			std::println(file, std::format_string<Args...>(std::string_view(fmt.data(), fmt_size)), XIEITE_FWD(args)...);
		} else {
			std::print(file, std::format_string<Args...>(std::string_view(fmt.data(), fmt_size)), XIEITE_FWD(args)...);
		}
	}

	template<xieite::fixed_str delim = " ", bool newline = true>
	void dump(auto&&... args) noexcept {
		return xieite::dump<delim, newline>(stdout, XIEITE_FWD(args)...);
	}
}

#endif
