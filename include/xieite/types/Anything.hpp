#pragma once

namespace xieite::types {
	struct Anything final {
		template<typename Any>
		constexpr operator Any&();

		template<typename Any>
		constexpr operator Any&&();
	};
}
