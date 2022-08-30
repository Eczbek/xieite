#pragma once


namespace gcufl {
	enum class os {
		Windows,
		Mac,
		Unix
	};

	template <gcufl::os>
	constexpr bool isOS = false;

#if defined(_WIN32) || defined(__WINDOWS__)
	template <>
	constexpr bool isOS<gcufl::os::Windows> = true;
#endif

#if defined(__APPLE__) || defined(__MACH__)
	template <>
	constexpr bool isOS<gcufl::os::Mac> = true;
#endif

#if defined(__unix__) || defined(__unix)
	template <>
	constexpr bool isOS<gcufl::os::Unix> = true;
#endif
}
