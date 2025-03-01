#pragma once

namespace x4 {
	template<typename T, typename... Args>
	concept hasbraceinit = requires (Args... args) { T { args... }; };
}
