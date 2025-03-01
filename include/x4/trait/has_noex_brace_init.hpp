#pragma once

namespace x4 {
	template<typename T, typename... Args>
	concept hasnoexbraceinit = requires (Args... args) {
		requires(noexcept(T { args... }));
	};
}
