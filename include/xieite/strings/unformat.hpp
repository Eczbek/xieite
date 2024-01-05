#ifndef XIEITE_HEADER_STRINGS_UNFORMAT
#	define XIEITE_HEADER_STRINGS_UNFORMAT

#	include <array>
#	include <concepts>
#	include <cstddef>
#	include <stdexcept>
#	include <string_view>
#	include <tuple>
#	include <utility>
#	include "../concepts/arithmetic.hpp"
#	include "../strings/parse_number.hpp"
#	include "../strings/valid_number.hpp"

namespace xieite::strings {
	template<typename... Types>
	requires((... && (xieite::concepts::Arithmetic<Types> || std::constructible_from<Types, std::string_view>)))
	constexpr void unformat(const std::string_view input, const std::string_view format, Types&... results) {
		std::array<std::string_view, sizeof...(Types)> strings;
		bool indicesDecided = false;
		bool hasIndices;
		std::size_t nextIndex = 0;
		std::size_t i = 0;
		std::size_t j = 0;
		const std::size_t formatSize = format.size();
		const std::size_t inputSize = input.size();
		while ((i < formatSize) && (j < inputSize)) {
			if ((format[i] == '{') && ((formatSize - i) > 1) && (format[i + 1] == '{') || (format[i] == '}') && ((formatSize - i) > 1) && (format[i + 1] == '}')) {
				++i;
			} else if (format[i] == '{') {
				++i;
				const std::size_t indexEnd = format.find('}', i);
				if (indexEnd == std::string_view::npos) {
					throw std::invalid_argument("Last indexed placeholder not terminated");
				}
				const std::string_view indexString = format.substr(i, indexEnd - i);
				i = indexEnd;
				if (!indicesDecided) {
					indicesDecided = true;
					hasIndices = !!indexString.size();
				} else if (hasIndices != !!indexString.size()) {
					throw std::invalid_argument("Placeholders inconsistently indexed");
				}
				if (hasIndices && !validNumber<std::size_t>(indexString)) {
					throw std::invalid_argument("Placeholder contains invalid index");
				}
				const std::size_t index = hasIndices ? xieite::strings::parseNumber<std::size_t>(indexString) : nextIndex;
				++nextIndex;
				if (index >= sizeof...(Types)) {
					throw std::invalid_argument("Placeholder index out of range");
				}
				const std::size_t inputEnd = ((formatSize - i) > 1) ? input.find(format[i + 1], j) : std::string_view::npos;
				const std::size_t inputLength = (inputEnd != std::string_view::npos) ? (inputEnd - j) : std::string_view::npos;
				strings[index] = input.substr(j, inputLength);
				j = inputEnd - 1;
			} else if (format[i] != input[j]) {
				throw std::invalid_argument("Input does not match format");
			}
			++i;
			++j;
		}
		([&results..., &strings]<std::size_t... indices>(std::index_sequence<indices...>) {
			const std::tuple<Types&...> tuple = std::make_tuple(std::ref(results)...);
			(..., ([&strings, tuple] {
				if constexpr (xieite::concepts::Arithmetic<Types>) {
					if (!xieite::strings::validNumber<Types>(strings[indices])) {
						throw std::invalid_argument("Input cannot be parsed as number");
					}
					std::get<indices>(tuple) = xieite::strings::parseNumber<Types>(strings[indices]);
				} else {
					std::get<indices>(tuple) = Types(strings[indices]);
				}
			})());
		})(std::make_index_sequence<sizeof...(Types)>());
	}
}

#endif