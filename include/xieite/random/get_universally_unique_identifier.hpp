#ifndef XIEITE_HEADER_RANDOM_GET_UNIVERSALLY_UNIQUE_IDENTIFIER
#	define XIEITE_HEADER_RANDOM_GET_UNIVERSALLY_UNIQUE_IDENTIFIER

#	include "../macros/platform.hpp"

#	if !XIEITE_PLATFORM_TYPE_UNIX
#		error "Platform not supported"
#	endif

#	include <string>
#	include <uuid/uuid.h>

namespace xieite::random {
	[[nodiscard]] inline std::string getUniversallyUniqueIdentifier() noexcept {
		uuid_t uuid;
		uuid_generate(uuid);
		std::string result = std::string(37, '\0');
		uuid_unparse(uuid, result.data());
		return result;
	}
}

#endif
