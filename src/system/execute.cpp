
#include <array>
#include <cstdio>
#include <gcufl/system/execute.hpp>
#include <memory>
#include <string>
#include <string_view>


std::string gcufl::system::execute(const std::string_view command) noexcept {
	std::shared_ptr<FILE> pipe(popen(command.data(), "r"), pclose);
	std::string result;
	if (pipe) {
		std::array<char, 1024> buffer;
		while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr)
			result += buffer.data();
	}
	return result;
}
