#ifndef DETAIL_XIEITE_HEADER_FN_AS
#	define DETAIL_XIEITE_HEADER_FN_AS
#
#	include <type_traits>
#	include "../trait/add_c.hpp"
#	include "../trait/add_cv.hpp"
#	include "../trait/add_v.hpp"
#	include "../trait/is_arith.hpp"
#	include "../trait/rm_c.hpp"
#	include "../trait/rm_cv.hpp"
#	include "../trait/rm_v.hpp"
#	include "../trait/try_sign.hpp"
#	include "../trait/try_unsign.hpp"

namespace xieite {
	template<typename T>
	constexpr auto as = [][[nodiscard]](std::type_identity_t<T> x) static noexcept {
		return x;
	};

	inline constexpr auto as_c = []<typename T>[[nodiscard]](T&& x) static noexcept {
		return const_cast<xieite::add_c<T&&>>(x);
	};

	inline constexpr auto as_v = []<typename T>[[nodiscard]](T&& x) static noexcept {
		return const_cast<xieite::add_v<T&&>>(x);
	};

	inline constexpr auto as_cv = []<typename T>[[nodiscard]](T&& x) static noexcept {
		return const_cast<xieite::add_cv<T&&>>(x);
	};

	inline constexpr auto as_not_c = []<typename T>[[nodiscard]](T&& x) static noexcept {
		return const_cast<xieite::rm_c<T&&>>(x);
	};

	inline constexpr auto as_not_v = []<typename T>[[nodiscard]](T&& x) static noexcept {
		return const_cast<xieite::rm_v<T&&>>(x);
	};

	inline constexpr auto as_not_cv = []<typename T>[[nodiscard]](T&& x) static noexcept {
		return const_cast<xieite::rm_cv<T&&>>(x);
	};

	inline constexpr auto as_unsign = []<xieite::is_arith T>(T x) static noexcept {
		return static_cast<xieite::try_unsign<T>>(x);
	};

	inline constexpr auto as_sign = []<xieite::is_arith T>(T x) static noexcept {
		return static_cast<xieite::try_sign<T>>(x);
	};
}

#endif
