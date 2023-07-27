#ifndef XIEITE_HEADER_RANDOM_GETUUID
#	define XIEITE_HEADER_RANDOM_GETUUID

#	include "../macros/SYSTEM_TYPE.hpp"

#	if XIEITE_SYSTEM_TYPE_UNIX
#		include <string>
#		include <uuid/uuid.h>

namespace xieite::random {
	inline std::string getUUID() noexcept {
		::uuid_t uuid;
		::uuid_generate(uuid);
		std::string result = std::string(37, '\0');
		::uuid_unparse(uuid, result.data());
		return result;
	}
}

#	else
#		error "System not supported"
#	endif

#endif
