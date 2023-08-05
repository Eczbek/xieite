#ifndef XIEITE_HEADER__RANDOM__GET_UUID
#	define XIEITE_HEADER__RANDOM__GET_UUID

#	include "../macros/SYSTEM_TYPE.hpp"

#	if !XIEITE__SYSTEM_TYPE__UNIX
#		error "System not supported"
#	endif

#	include <string>
#	include <uuid/uuid.h>

namespace xieite::random {
	[[nodiscard]]
	inline std::string getUUID() noexcept {
		::uuid_t uuid;
		::uuid_generate(uuid);
		std::string result = std::string(37, '\0');
		::uuid_unparse(uuid, result.data());
		return result;
	}
}

#endif
