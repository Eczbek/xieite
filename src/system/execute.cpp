
#include <cstdio>
#include <xieite/stream/readFile.hpp>
#include <xieite/system/execute.hpp>
#include <string>
#include <string_view>

std::string xieite::system::execute(const std::string_view command) noexcept {
	return xieite::stream::readFile(popen(command.data(), "r"));
}
