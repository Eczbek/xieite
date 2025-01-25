#pragma once

namespace xieite {
	template<typename T, typename... Args>
	concept has_noex_brace_init = requires (Args... args) {
		requires(noexcept(T { args... }));
	};
}
