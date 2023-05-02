#pragma once

#include <xieite/macros/CONCATENATE.hpp>

#define XIEITE_THIEF_EXPOSE(item, id) \
	constexpr auto XIEITE_CONCATENATE(XIEITE_INTERNAL_STEAL, id)(); \
	template<auto pointer> struct XIEITE_CONCATENATE(XIEITE_INTERNAL_THIEF, id) { \
		friend constexpr auto XIEITE_CONCATENATE(XIEITE_INTERNAL_STEAL, id)() { \
			return pointer; \
		} \
	}; \
	template struct XIEITE_CONCATENATE(XIEITE_INTERNAL_THIEF, id)<item>;

#define XIEITE_THIEF_STEAL(victim, id) \
	((victim).*XIEITE_CONCATENATE(XIEITE_INTERNAL_STEAL, id)())

// Thanks to Halalaluyafail for idea and help
