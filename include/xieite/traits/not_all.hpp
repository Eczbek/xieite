#pragma once

#include <type_traits>
#include "../concepts/none.hpp"

namespace xieite::traits {
	template<typename Type, template<typename> typename... Traits>
	struct NotAll
	: std::bool_constant<xieite::concepts::NotAll<Type, Traits...>> {};
}
