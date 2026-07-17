#ifndef DETAIL_XTE_HEADER_UTIL_ERROR
#	define DETAIL_XTE_HEADER_UTIL_ERROR
#
#	include "../data/string_view.hpp"
#	include <exception>

namespace xte {
	struct error : std::exception, xte::string_view {
		using xte::string_view::string_view;

		[[nodiscard]] virtual constexpr const char* what() const noexcept override {
			return this->data();
		}
	};
}

#endif
