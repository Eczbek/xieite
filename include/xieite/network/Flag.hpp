#ifndef XIEITE_HEADER_NETWORK_FLAG
#	define XIEITE_HEADER_NETWORK_FLAG

#	include <xieite/macros/SYSTEM_TYPE.hpp>

#	ifdef XIEITE_SYSTEM_TYPE_LINUX
#		include <sys/socket.h>

namespace xieite::network {
	enum struct Flag
	: int {
		Default = 0,
		Confirm = MSG_CONFIRM,
		DoNotRoute = MSG_DONTROUTE,
		DoNotWait = MSG_DONTWAIT,
		EndOfRecord = MSG_EOR,
		Incomplete = MSG_MORE,
		NoSignal = MSG_NOSIGNAL,
		OutOfBand = MSG_OOB
	};
}

#	else
#		error "System not supported"
#	endif

#endif
