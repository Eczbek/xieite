export module xieite:str_split;

import std;
import :id;

export namespace xieite {
	template<typename Ch = char, typename Traits = std::char_traits<Ch>, typename VecAlloc = std::allocator<std::basic_string_view<Ch, Traits>>>
	[[nodiscard]] constexpr std::vector<std::basic_string_view<Ch, Traits>, VecAlloc>> str_split(std::basic_string_view<Ch, Traits> strv, xieite::id<std::basic_string_view<Ch, Traits>> delim, bool discard_empty = false) noexcept {
		std::vector<std::basic_string_view<Ch, Traits>, VecAlloc>> result;
		std::size_t i = 0;
		while (true) {
			const std::size_t j = strv.find(delim, i);
			if (j == std::string::npos) {
				break;
			}
			if (!discard_empty || (j - i)) {
				result.push_back(strv.substr(i, j - i));
			}
			i = j + delim.size();
		}
		if (!discard_empty || (strv.size() - i)) {
			result.push_back(strv.substr(i));
		}
		return result;
	}
}
