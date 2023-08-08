#ifndef XIEITE_HEADER__FUNCTORS__ARGUMENT
#	define XIEITE_HEADER__FUNCTORS__ARGUMENT

#	include <cstddef>
#	include <tuple>
#	include "../functors/Arguments.hpp"

namespace xieite::functors {
	template<typename Functor, std::size_t index>
	using Argument = std::tuple_element_t<index, xieite::functors::Arguments<Functor>>;
}

#endif
