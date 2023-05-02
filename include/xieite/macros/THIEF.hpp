#pragma once

#include <xieite/macros/CONCATENATE.hpp>

#define XIEITE_THIEF_EXPOSE(target, id) \
	constexpr auto XIEITE_CONCATENATE(XIEITE_INTERNAL_THIEF_STEAL_, id)(); \
	template<auto pointer> struct XIEITE_CONCATENATE(XIEITE_INTERNAL_THIEF_EXPOSE_, id) { \
		friend constexpr auto XIEITE_CONCATENATE(XIEITE_INTERNAL_THIEF_STEAL_, id)() { \
			return pointer; \
		} \
	}; \
	template struct XIEITE_CONCATENATE(XIEITE_INTERNAL_THIEF_EXPOSE_, id)<&target>;

#define XIEITE_THIEF_STEAL(victim, id) \
	((victim).*XIEITE_CONCATENATE(XIEITE_INTERNAL_THIEF_STEAL_, id)())

// Thanks to Halalaluyafail for idea and help
