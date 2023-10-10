#pragma once

#include "../concepts/any.hpp"

namespace xieite::concepts {
	template<typename Type, template<typename> typename... Traits>
	concept None = !xieite::concepts::Any<Type, Traits...>;
}
