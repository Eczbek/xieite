#ifndef XIEITE_HEADER_CONCEPTS_TEMPORALDURATION
#	define XIEITE_HEADER_CONCEPTS_TEMPORALDURATION

#	include <type_traits>
#	include "../traits/isTemporalDuration.hpp"

namespace xieite::concepts {
	template<typename Any>
	concept TemporalDuration = xieite::traits::isTemporalDuration<std::remove_cv_t<Any>>;
}

#endif
