#ifndef XIEITE_HEADER_CONTAINERS_STATIC_STRING
#	define XIEITE_HEADER_CONTAINERS_STATIC_STRING

#	include <cstddef>
#	include <string_view>

namespace xieite::containers {
	template<std::size_t characters>
	struct StaticString {
		char data[characters + 1];

		template<std::size_t otherCharacters>
		constexpr StaticString(const char (&data)[otherCharacters]) noexcept {
			for (std::size_t i = 0; i < otherCharacters; ++i) {
				this->data[i] = data[i];
			}
		}

		[[nodiscard]] static constexpr std::size_t size() noexcept {
			return characters;
		}

		[[nodiscard]] constexpr std::string_view view() const noexcept {
			return std::string_view(this->data, this->data + characters);
		}
	};

	template<std::size_t characters>
	StaticString(char const (&)[characters]) -> StaticString<characters - 1>;
}

#endif
