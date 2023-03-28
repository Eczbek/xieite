#pragma once

#include <type_traits>

namespace xieite::concepts {
	template<typename Any>
	concept CopyAssignable = std::is_copy_assignable<Any>;
}
