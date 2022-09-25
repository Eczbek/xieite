
#include <gcufl/stream/putBack.hpp>
#include <istream>
#include <string_view>


std::istream& gcufl::stream::putBack(std::istream& inputStream, const std::string_view data) noexcept {
	for (std::size_t i = data.size(); i--;)
		inputStream.putback(data[i]);
	return inputStream;
}
