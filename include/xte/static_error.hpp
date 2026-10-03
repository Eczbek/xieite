#ifndef DETAIL_XTE_HEADER_STATIC_ERROR
#	define DETAIL_XTE_HEADER_STATIC_ERROR
#
#	include "./static_string_view.hpp"
#	include <exception>
#	include <meta>

namespace xte {
	template<xte::static_string_view message>
	struct [[nodiscard]] static_error : std::exception {
	private:
		static constexpr char const* _data = std::define_static_string(message);

	public:
		virtual constexpr char const* what() const noexcept override {
			return xte::static_error<message>::_data;
		}
	};
}

#endif
