
#include <xieite/stream/putBack.hpp>
#include <istream>
#include <string_view>

std::istream& xieite::stream::putBack(std::istream& inputStream, const std::string_view data) noexcept {
	for (std::size_t i = data.size(); i--;)
		inputStream.putback(data[i]);
	return inputStream;
}
