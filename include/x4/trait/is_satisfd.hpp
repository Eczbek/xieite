#pragma once

namespace x4 {
	template<auto fn, typename... Ts>
	concept issatisfd = requires { fn.template operator()<Ts...>(); };
}
