#include <fcntl.h> // F_SETFL, O_NONBLOCK, fcntl
#include <unistd.h> // STDIN_FILENO
#include <xieite/console/NonBlockLock.hpp> // xieite::console::NonBlockLock

xieite::console::NonBlockLock::NonBlockLock() noexcept {
	fcntl(STDIN_FILENO, F_SETFL, blockingMode | O_NONBLOCK);
}

xieite::console::NonBlockLock::~NonBlockLock() {
	fcntl(STDIN_FILENO, F_SETFL, blockingMode);
}
