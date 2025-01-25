#pragma once

namespace xieite {
	template<bool>
	struct set_mv_ctor {};

	template<>
	struct set_mv_ctor<false> {
		set_mv_ctor() = default;
		set_mv_ctor(const xieite::set_mv_ctor<false>&) = default;
		set_mv_ctor(xieite::set_mv_ctor<false>&&) = delete;
		xieite::set_mv_ctor<false>& operator=(const xieite::set_mv_ctor<false>&) = default;
		xieite::set_mv_ctor<false>& operator=(xieite::set_mv_ctor<false>&&) = default;
	};
}
