
#include <cstdio>
#include <gcufl/system/execute.hpp>
#include <memory>
#include <string>
#include <string_view>


std::string gcufl::system::execute(const std::string_view command) noexcept {
	std::shared_ptr<FILE> pipe(popen(command.data(), "r"), pclose);
	std::string result;
	if (pipe) {
		char buffer[1024];
		while (!feof(pipe.get()))
			if (fgets(buffer, 1024, pipe.get()) != NULL)
				result += buffer;
	}
	return result;
}
