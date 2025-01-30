#pragma once

#include "../meta/t.hpp"

namespace xieite {
	template<typename T, template<typename...> typename... Ms>
	concept is_spec = (... && requires { ([]<typename... Args>(xieite::t<Ms<Args...>>) {})(xieite::t<T>()); });
}

// TODO: Remove after `std::specialization_of` is implemented
