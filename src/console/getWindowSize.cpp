
#include <gcufl/console/cursor/Position.hpp>
#include <gcufl/console/getWindowSize.hpp>
#include <sys/ioctl.h>
#include <unistd.h>

gcufl::console::cursor::Position gcufl::console::getWindowSize() noexcept {
	winsize size;
	ioctl(STDIN_FILENO, TIOCGWINSZ, &size);
	return gcufl::console::cursor::Position(size.ws_row, size.ws_col);
}
