#pragma once

namespace xieite {
	template<bool>
	struct set_mv_assign {};

	template<>
	struct set_mv_assign<false> {
		set_mv_assign() = default;
		set_mv_assign(const xieite::set_mv_assign<false>&) = default;
		set_mv_assign(xieite::set_mv_assign<false>&&) = default;
		xieite::set_mv_assign<false>& operator=(const xieite::set_mv_assign<false>&) = default;
		auto operator=(xieite::set_mv_assign<false>&&) = delete;
	};
}
