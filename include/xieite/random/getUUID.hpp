#include <string>
#include <uuid/uuid.h>

namespace xieite::random {
    std::string getUUID() noexcept {
        uuid_t uuid;
        uuid_generate(uuid);
        std::string result(37, '\0');
        uuid_unparse(uuid, result.data());
        return result;
    }
}
