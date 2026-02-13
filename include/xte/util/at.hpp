#ifndef DETAIL_XTE_HEADER_FUNC_AT
#	define DETAIL_XTE_HEADER_FUNC_AT
#
#	include "../preproc/fwd.hpp"
#	include "../util/types.hpp"

namespace xte {
	template<xte::uz index>
	[[nodiscard]] constexpr auto&& at(auto&&... args) noexcept requires(index < sizeof...(args)) {
		return XTE_FWD(args...[index]);
	};
}

#endif
