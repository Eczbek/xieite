#pragma once

#include "../concepts/all.hpp"

namespace xieite::concepts {
	template<typename Type, template<typename> typename... Traits>
	concept NotAll = !xieite::concepts::All<Type, Traits...>;
}
