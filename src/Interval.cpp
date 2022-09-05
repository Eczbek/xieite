#include <gcufl/Interval.hpp>


gcufl::Interval::~Interval() {
	running = false;
	loop.join();
}
