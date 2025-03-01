#pragma once

#include <type_traits>
#include "../trait/addlref.hpp"
#include "../trait/islref.hpp"
#include "../trait/cprref.hpp"
#include "../trait/rmref.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpref = std::conditional_t<x4::islref<T>, x4::add_lref<U>, x4::cprref<T, x4::rmref<U>>>;
}
