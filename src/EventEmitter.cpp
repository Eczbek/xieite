#include <gcufl/EventEmitter.hpp>


void gcufl::EventEmitter::off(const std::string& event) noexcept {
	events.erase(event);
}
