#pragma once

#include <type_traits>
#include "../meta/t.hpp"

namespace xieite {
	template<typename T, typename Sig = void()>
	concept is_invoc = ([]<typename Ret, typename... Args>(xieite::t<Ret(Args...)>) /* -> bool */ {
		return std::is_invocable_r_v<Ret, T, Args...>;
	})(xieite::t<Sig>());
}

