#pragma once

#include "../meta/mkseq.hpp"

namespace x4 {
	template<typename... Ts>
	constexpr auto seqfor = x4::mkseq<sizeof...(Ts)>;
}
