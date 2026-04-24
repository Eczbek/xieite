#ifndef DETAIL_XTE_HEADER_MATH_MOD_CHECKED
#	define DETAIL_XTE_HEADER_MATH_MOD_CHECKED
#
#	include "../data/null.hpp"
#	include "../data/opt.hpp"
#	include "../math/rem_checked.hpp"
#	include "../math/sign.hpp"
#	include "../trait/is_number.hpp"
#	include <type_traits>

namespace xte {
	[[nodiscard]] constexpr auto mod_checked(xte::is_number auto x, xte::is_number auto... ys) noexcept {
		using common_type = std::common_type_t<decltype(x), decltype(ys)...>;
		auto result = xte::opt(static_cast<common_type>(x));
		(void)(... && (result = ([](common_type lhs, common_type rhs) {
			return xte::rem_checked(lhs, rhs).and_then([](common_type rem) {
				return xte::rem_checked(rem + rhs * (xte::sign(lhs) != xte::sign(rhs)), rhs);
			});
		})(result, static_cast<common_type>(ys))));
		return result;
	};
}

#endif
