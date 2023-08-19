#ifndef XIEITE_HEADER__RANDOM__GET_UNIVERSALLY_UNIQUE_IDENTIFIER
#	define XIEITE_HEADER__RANDOM__GET_UNIVERSALLY_UNIQUE_IDENTIFIER

#	include "../macros/SYSTEM_TYPE.hpp"

#	if !XIEITE__SYSTEM_TYPE__UNIX
#		error "System not supported"
#	endif

#	include <string>
#	include <uuid/uuid.h>

namespace xieite::random {
	inline std::string getUniversallyUniqueIdentifier() noexcept {
		::uuid_t uuid;
		::uuid_generate(uuid);
		std::string result = std::string(37, '\0');
		::uuid_unparse(uuid, result.data());
		return result;
	}
}

#endif
