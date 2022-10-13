
#include <cstdio>
#include <gcufl/stream/read.hpp>
#include <gcufl/system/execute.hpp>
#include <string>
#include <string_view>

std::string gcufl::system::execute(const std::string_view command) noexcept {
	return gcufl::stream::read(popen(command.data(), "r"));
}
