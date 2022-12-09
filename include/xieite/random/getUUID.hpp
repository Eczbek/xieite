#pragma once
#include <string> // std::string
#include <uuid/uuid.h> // uuid_generate, uuid_t, uuid_unparse

namespace xieite::random {
	std::string getUUID() noexcept {
		uuid_t uuid;
		uuid_generate(uuid);
		std::string result(37, '\0');
		uuid_unparse(uuid, result.data());
		return result;
	}
}
