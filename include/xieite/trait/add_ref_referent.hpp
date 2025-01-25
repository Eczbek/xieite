#pragma once

#include <type_traits>
#include "../trait/add_lref_referent.hpp"
#include "../trait/add_rref_referent.hpp"
#include "../trait/is_lref_referent.hpp"
#include "../trait/is_rref_referent.hpp"

namespace xieite {
	template<typename T, typename U>
	using add_ref_referent = std::conditional_t<xieite::is_lref_referent<T>, xieite::add_lref_referent<U>, std::conditional_t<xieite::is_rref_referent<T>, xieite::add_rref_referent<U>, U>>;
}
