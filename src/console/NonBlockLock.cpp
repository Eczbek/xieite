#include <fcntl.h>
#include <xieite/console/NonBlockLock.hpp>

xieite::console::NonBlockLock::NonBlockLock() noexcept {
	fcntl(STDIN_FILENO, F_SETFL, blockingMode | O_NONBLOCK);
}

xieite::console::NonBlockLock::~NonBlockLock() {
	fcntl(STDIN_FILENO, F_SETFL, blockingMode);
}
