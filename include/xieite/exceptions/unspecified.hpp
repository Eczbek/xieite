#ifndef XIEITE_HEADER_EXCEPTIONS_UNSPECIFIED
#	define XIEITE_HEADER_EXCEPTIONS_UNSPECIFIED

#	include <string>
#	include <string_view>

namespace xieite::exceptions {
	class Unspecified {
	public:
		constexpr Unspecified(const std::string_view message = "") noexcept
		: message(message) {}

		constexpr const char* what() const noexcept {
			return this->message.c_str();
		}

	private:
		std::string message;
	};
}

#endif
