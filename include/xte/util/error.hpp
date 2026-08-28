#ifndef DETAIL_XTE_HEADER_UTIL_ERROR
#	define DETAIL_XTE_HEADER_UTIL_ERROR
#
#	include "../data/static_string_view.hpp"
#	include <exception>
#	include <meta>

namespace xte {
	template<xte::static_string_view message>
	struct [[nodiscard]] error : std::exception {
	private:
		static constexpr const char* _data = std::define_static_string(message);

	public:
		virtual constexpr const char* what() const noexcept override {
			return xte::error<message>::_data;
		}
	};
}

#endif
