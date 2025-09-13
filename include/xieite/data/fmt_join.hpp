#ifndef DETAIL_XIEITE_HEADER_DATA_FMT_JOIN
#	define DETAIL_XIEITE_HEADER_DATA_FMT_JOIN
#
#	include <cstddef>
#	include <format>
#	include <string_view>
#	include "../data/fixed_array.hpp"
#	include "../data/fixed_str.hpp"
#	include "../fn/unroll.hpp"

using namespace std::literals;

namespace xieite {
	template<xieite::fixed_str delim, typename... Args>
	constexpr std::format_string<Args...> fmt_join = ([] {
		static constexpr auto data = xieite::unroll<([] -> std::size_t {
			std::size_t offset = 0;
			for (char c : delim.view()) {
				offset += "{}"sv.contains(c);
			}
			return sizeof...(Args) * 2 + (sizeof...(Args) - !!sizeof...(Args)) * (delim.size + offset);
		})()>([]<std::size_t... i> {
			std::size_t j = -1uz;
			bool ok = true;
			return xieite::fixed_array { (void(i), (((j += ok) %= (2 + delim.size)) < 2) ? "{}"[j] : (void(ok = !ok || !"{}"sv.contains(delim[j - 2])), delim[j - 2]))... };
		});
		return std::format_string<Args...>(std::string_view(data.array, data.size));
	})();
}

#endif
