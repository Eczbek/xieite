export module xieite:str_split;

import std;
import :chv;

export namespace xieite {
	template<typename Ch = char, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<std::basic_string_view<Ch, Traits>>, xieite::end...,
		typename StrV = std::basic_string_view<Ch, Traits>,
		typename Vec = std::vector<StrV, Alloc>>
	[[nodiscard]] constexpr Vec str_split(StrV str, xieite::chv<Ch, Traits> delim, bool discard_empty = false) noexcept {
		Vec result;
		std::size_t i = 0;
		while (true) {
			const std::size_t j = str.find(delim, i);
			if (j == std::string::npos) {
				break;
			}
			if (!discard_empty || (j - i)) {
				result.push_back(str.substr(i, j - i));
			}
			i = j + delim.size();
		}
		if (!discard_empty || (str.size() - i)) {
			result.push_back(str.substr(i));
		}
		return result;
	}
}
