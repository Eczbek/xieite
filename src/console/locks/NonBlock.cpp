
#include <gcufl/console/locks/NonBlock.hpp>
#include <fcntl.h>


gcufl::console::locks::NonBlock::NonBlock() noexcept {
	if (!instancesCount++)
		fcntl(STDIN_FILENO, F_SETFL, blockingMode | O_NONBLOCK);
}

gcufl::console::locks::NonBlock::~NonBlock() {
	if (!--instancesCount)
		fcntl(STDIN_FILENO, F_SETFL, blockingMode);
}
