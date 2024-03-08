#ifndef XIEITE_HEADER_RANDOM_GET_UNIVERSALLY_UNIQUE_IDENTIFIER
#	define XIEITE_HEADER_RANDOM_GET_UNIVERSALLY_UNIQUE_IDENTIFIER

#	include "../macros/platform.hpp"

#	if !XIEITE_PLATFORM_TYPE_UNIX
#		error "Platform not supported"
#	endif

#	include <string>
#	include <uuid/uuid.h>
#	include "../concepts/string.hpp"

namespace xieite::random {
	template<xieite::concepts::String String = std::string>
	[[nodiscard]] inline String getUniversallyUniqueIdentifier() noexcept {
		::uuid_t uuid;
		::uuid_generate(uuid);
		String result = String(37, '\0');
		::uuid_unparse(uuid, result.data());
		return result;
	}
}

#endif
