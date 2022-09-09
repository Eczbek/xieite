#pragma once

#include <gcufl/io/escapeCodes/LineErasor.hpp>
#include <gcufl/io/escapeCodes/Prefix.hpp>
#include <iostream>


namespace gcufl::io {
	template <gcufl::io::escapeCodes::LineErasor M, gcufl::io::escapeCodes::Prefix P = gcufl::io::escapeCodes::Prefix::Hexadecimal>
	void eraseLine() noexcept {
		std::cout << static_cast<char>(P) << '[' << static_cast<int>(M) << 'K';
	}
}
