#pragma once
#include <type_traits> // std::is_trivial_v

namespace xieite::concepts {
	template<typename Any>
	concept Trivial = std::is_trivial_v<Any>;
}
