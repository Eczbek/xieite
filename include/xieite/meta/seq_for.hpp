#pragma once

#include "../meta/make_seq.hpp"

namespace xieite {
	template<typename... Ts>
	inline constexpr auto seq_for = xieite::make_seq<sizeof...(Ts)>;
}
