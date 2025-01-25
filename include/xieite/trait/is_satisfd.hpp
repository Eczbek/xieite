#pragma once

namespace xieite {
	template<auto fn, typename... Ts>
	concept is_satisfd = requires { fn.template operator()<Ts...>(); };
}
