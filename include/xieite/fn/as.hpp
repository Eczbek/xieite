#ifndef DETAIL_XIEITE_HEADER_FN_AS
#	define DETAIL_XIEITE_HEADER_FN_AS
#
#	include <type_traits>

namespace xieite {
	template<typename T>
	constexpr auto as = [][[nodiscard]](std::type_identity_t<T> x) static noexcept {
		return x;
	};
}

#endif
