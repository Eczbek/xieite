#ifndef DETAIL_XTE_HEADER_UTIL_ERROR
#	define DETAIL_XTE_HEADER_UTIL_ERROR
#
#	include "../data/string_view.hpp"
#	include <exception>
#	include <meta>

namespace xte {
	struct [[nodiscard]] error : std::exception, xte::string_view {
		consteval error(xte::string_view message) noexcept
		: xte::string_view(std::define_static_string(message)) {}

		virtual constexpr const char* what() const noexcept override {
			return this->data();
		}
	};
}

#endif
