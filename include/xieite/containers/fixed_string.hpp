#ifndef XIEITE_HEADER_CONTAINERS_STATIC_STRING
#	define XIEITE_HEADER_CONTAINERS_STATIC_STRING

#	include <array>
#	include <cstddef>
#	include <string_view>
#	include "../concepts/string_view.hpp"

namespace xieite::containers {
	template<std::size_t characters, typename Character = char>
	struct FixedString {
		std::array<Character, characters + 1> data;

		template<std::size_t otherCharacters>
		constexpr FixedString(const Character(&data)[otherCharacters]) noexcept {
			for (std::size_t i = 0; i < otherCharacters; ++i) {
				this->data[i] = data[i];
			}
		}

		[[nodiscard]] static constexpr std::size_t size() noexcept {
			return characters;
		}

		template<xieite::concepts::StringView StringView = std::string_view>
		[[nodiscard]] constexpr StringView view() const noexcept {
			return StringView(this->data, this->data + characters);
		}
	};

	template<std::size_t characters, typename Character>
	FixedString(const Character(&)[characters]) -> xieite::containers::FixedString<characters - 1, Character>;
}

#endif
