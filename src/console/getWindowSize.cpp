#include <xieite/console/cursor/Position.hpp>
#include <xieite/console/getWindowSize.hpp>
#include <sys/ioctl.h>
#include <unistd.h>

xieite::console::cursor::Position xieite::console::getWindowSize() noexcept {
	winsize size;
	ioctl(STDIN_FILENO, TIOCGWINSZ, &size);
	return xieite::console::cursor::Position(size.ws_row, size.ws_col);
}
