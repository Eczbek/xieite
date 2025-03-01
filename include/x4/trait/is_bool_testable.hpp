#pragma once

#include "../pp/fwd.hpp"

namespace x4 {
	template<typename T>
	concept isbtest = requires(T&& x) {
		static_cast<bool>(X4FWD(x));
		static_cast<bool>(!X4FWD(x));
		static_cast<void(*)(bool)>(nullptr)(X4FWD(x));
		static_cast<void(*)(bool)>(nullptr)(!X4FWD(x));
	};
}
