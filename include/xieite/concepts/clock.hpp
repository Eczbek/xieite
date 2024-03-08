#ifndef XIEITE_HEADER_CONCEPTS_CLOCK
#	define XIEITE_HEADER_CONCEPTS_CLOCK

#	include <chrono>

namespace xieite::concepts {
	template<typename Type>
	concept Clock = std::chrono::is_clock_v<Type>;
}

#endif
