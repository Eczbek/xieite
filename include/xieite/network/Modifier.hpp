#ifndef XIEITE_HEADER_NETWORK_MODIFIER
#	define XIEITE_HEADER_NETWORK_MODIFIER

#	include <xieite/macros/SYSTEM_TYPE.hpp>

#	ifdef XIEITE_SYSTEM_TYPE_LINUX
#		include <sys/socket.h>

namespace xieite::network {
	enum struct Modifier
	: int {
		NonBlock = SOCK_NONBLOCK,
		CloseOnExecution = SOCK_CLOEXEC
	};
}

#	else
#		error "System not supported"
#	endif

#endif
