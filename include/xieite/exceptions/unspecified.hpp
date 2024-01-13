#ifndef XIEITE_HEADER_EXCEPTIONS_UNSPECIFIED
#	define XIEITE_HEADER_EXCEPTIONS_UNSPECIFIED

#	include <exception>
#	include <string>
#	include <string_view>

namespace xieite::exceptions {
	class Unspecified
	: std::exception {
	public:
		constexpr Unspecified(const std::string_view message = "") noexcept
		: message(message) {}

		[[nodiscard]] const char* what() const noexcept {
			return this->message.c_str();
		}

	protected:
		std::string message;
	};
}

#endif
