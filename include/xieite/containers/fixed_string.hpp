#ifndef XIEITE_HEADER_CONTAINERS_STATIC_STRING
#	define XIEITE_HEADER_CONTAINERS_STATIC_STRING

#	include <array>
#	include <cstddef>
#	include <string_view>

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

		[[nodiscard]] constexpr std::string_view view() const noexcept {
			const std::string_view view = std::string_view(this->data, this->data + characters);
			return view.substr(0, view.find('\0'));
		}
	};

	template<std::size_t characters, typename Character>
	FixedString(const Character(&)[characters]) -> xieite::containers::FixedString<characters - 1, Character>;
}

#endif
