#ifndef XIEITE_HEADER_CONCEPTS_NARROWCHARACTER
#	define XIEITE_HEADER_CONCEPTS_NARROWCHARACTER

#	include <concepts>
#	include <type_traits>
#	include <xieite/concepts/OrdinaryCharacter.hpp>

namespace xieite::concepts {
	template<typename Any>
	concept NarrowCharacter = xieite::concepts::OrdinaryCharacter<Any> || std::same_as<std::remove_cv_t<Any>, char8_t>;
}

#endif
