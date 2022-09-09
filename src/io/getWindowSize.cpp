
#include <gcufl/io/cursor/Position.hpp>
#include <gcufl/io/getWindowSize.hpp>
#include <sys/ioctl.h>
#include <unistd.h>


gcufl::io::cursor::Position gcufl::io::getWindowSize() noexcept {
	winsize size;
	ioctl(STDIN_FILENO, TIOCGWINSZ, &size);
	return gcufl::io::cursor::Position(size.ws_row, size.ws_col);
}
