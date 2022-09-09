
#include <gcufl/io/locks/NonBlock.hpp>
#include <fcntl.h>


gcufl::io::locks::NonBlock::NonBlock() noexcept {
	if (!instancesCount++)
		fcntl(STDIN_FILENO, F_SETFL, blockingMode | O_NONBLOCK);
}

gcufl::io::locks::NonBlock::~NonBlock() {
	if (!--instancesCount)
		fcntl(STDIN_FILENO, F_SETFL, blockingMode);
}
