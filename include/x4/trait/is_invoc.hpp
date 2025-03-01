#pragma once

#include <type_traits>

namespace x4 {
	template<typename T, typename Sig = void()>
	concept isinvoc = ([]<typename Ret, typename... Args>(std::type_identity<Ret(Args...)>) static /* -> bool */ {
		return std::is_invocable_r_v<Ret, T, Args...>;
	})(std::type_identity<Sig>());
}

