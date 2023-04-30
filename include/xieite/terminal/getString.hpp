#pragma once

#include <iostream>
#include <string>
#include <xieite/terminal/ModeLock.hpp>
#include <xieite/terminal/getCharacter.hpp>

namespace xieite::terminal {
	inline std::string getString() noexcept {
		xieite::terminal::ModeLock modeLock;
		modeLock.setBlocking(false);
		std::string buffer;
		while (true) {
			const char input = xieite::terminal::getCharacter(modeLock);
			if (input < 1) {
				break;
			}
			buffer += input;
		}
		return buffer;
	}
}
