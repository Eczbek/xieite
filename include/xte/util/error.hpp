#ifndef DETAIL_XTE_HEADER_UTIL_ERROR
#	define DETAIL_XTE_HEADER_UTIL_ERROR
#
#	include "../data/fixed_string.hpp"
#	include "../meta/type.hpp"
#	include "../util/types.hpp"
#	include <exception>

namespace xte {
	template<xte::uz n>
	struct error : std::exception, xte::fixed_string<n> {
		using xte::fixed_string<n>::fixed_string;

		virtual constexpr const char* what() const noexcept override {
			return this->data();
		}
	};

	template<xte::uz n>
	error(const xte::type<char[n]>&) -> error<~-n>;
}

#endif
