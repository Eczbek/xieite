#pragma once

namespace DETAIL_XIEITE::maybe_base {
	template<typename>
	struct dummy {};
}

namespace xieite {
	template<bool x, typename T>
	using maybe_base = std::conditional_t<x, T, DETAIL_XIEITE::maybe_base::dummy<T>>;
}
