#pragma once

#include <type_traits>

namespace x4 {
	template<typename T, typename Sig = void()>
	concept isnoexinvoc = ([]<typename Ret, typename... Args>(std::type_identity<Ret(Args...)>) static /* -> bool */ {
		return std::is_nothrow_invocable_r_v<Ret, T, Args...>;
	})(std::type_identity<Sig>());
}
