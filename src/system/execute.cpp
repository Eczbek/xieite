
#include <cstdio>
#include <gcufl/system/execute.hpp>
#include <memory>
#include <string>
#include <string_view>


std::string gcufl::system::execute(std::string_view command) noexcept {
	std::shared_ptr<FILE> pipe(popen(command.data(), "r"), pclose);
	std::string result;
	if (pipe) {
		char buffer[128];
		while (!feof(pipe.get()))
			if (fgets(buffer, 128, pipe.get()) != NULL)
				result += buffer;
	}
	return result;
}
