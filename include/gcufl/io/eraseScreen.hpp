#pragma once

#include <gcufl/io/escapeCodes/Prefix.hpp>
#include <gcufl/io/escapeCodes/ScreenErasor.hpp>


namespace gcufl::io {
	template <gcufl::io::escapeCodes::ScreenErasor M, gcufl::io::escapeCodes::Prefix P = gcufl::io::escapeCodes::Prefix::Hexadecimal>
	void eraseScreen() noexcept {
		std::cout << static_cast<char>(P) << '[' << static_cast<int>(M) << 'J';
	}
}
