#pragma once

#include <xieite/macros/CONCATENATE.hpp>

#define XIEITE_THIEF_EXPOSE(item, id) \
	constexpr auto XIEITE_CONCATENATE(XIEITE_INTERNAL_THIEF_STEAL_, id)(); \
	\
	template<auto pointer> \
	struct XIEITE_CONCATENATE(XIEITE_INTERNAL_THIEF_EXPOSE_, id) final { \
		friend constexpr auto XIEITE_CONCATENATE(XIEITE_INTERNAL_THIEF_STEAL_, id)() { \
			return pointer; \
		} \
	}; \
	\
	template struct XIEITE_CONCATENATE(XIEITE_INTERNAL_THIEF_EXPOSE_, id)<&item>;

#define XIEITE_THIEF_STEAL(victim, id) \
	((victim).*XIEITE_CONCATENATE(XIEITE_INTERNAL_THIEF_STEAL_, id)())

// Thanks to Halalaluyafail for original code and help
