#include <sys/ioctl.h> // TIOCGWINSZ, ioctl, winsize
#include <unistd.h> // STDIN_FILENO
#include <xieite/console/CursorPosition.hpp>
#include <xieite/console/getWindowSize.hpp>

xieite::console::CursorPosition xieite::console::getWindowSize() noexcept {
	winsize size;
	ioctl(STDIN_FILENO, TIOCGWINSZ, &size);
	return xieite::console::CursorPosition(size.ws_row, size.ws_col);
}
