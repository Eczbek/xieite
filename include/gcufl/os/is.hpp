#pragma once

#include <gcufl/os/Type.hpp>


namespace gcufl::os {
	template<gcufl::os::Type>
	constexpr bool is = false;

#if defined(_WIN32) || defined(__WINDOWS__)
	template<>
	constexpr bool is<gcufl::os::Type::Windows> = true;
#endif

#if defined(__APPLE__) || defined(__MACH__)
	template<>
	constexpr bool is<gcufl::os::Type::Mac> = true;
#endif

#if defined(__unix__) || defined(__unix)
	template<>
	constexpr bool is<gcufl::os::Type::Unix> = true;
#endif
}
