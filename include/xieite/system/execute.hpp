#ifndef XIEITE_HEADER_SYSTEM_EXECUTE
#	define XIEITE_HEADER_SYSTEM_EXECUTE

#	include <cstdio>
#	include <string>
#	include "../concepts/same_as_any.hpp"
#	include "../memory/get_page_size.hpp"
#	include "../streams/pipe.hpp"

namespace xieite::system {
	template<xieite::concepts::SameAsAny<std::string, std::wstring> String = std::string>
	inline String execute(const String& command) noexcept {
		const xieite::streams::Pipe pipe = xieite::streams::Pipe(command, String(1, 'r'));
		const std::size_t pageSize = xieite::memory::getPageSize();
		String result;
		while (true) {
			String buffer = String(pageSize, '\0');
			if (!std::fread(buffer.data(), 1, buffer.size(), pipe.file)) {
				break;
			}
			result += buffer;
		}
		return result;
	}
}

#endif
