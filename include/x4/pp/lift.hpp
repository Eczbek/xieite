#pragma once

#include "../pp/ar.hpp"
#include "../pp/fwd.hpp"

#define X4LIFT(...) []DETAIL_X4LIFT(static, __VA_ARGS__)
#define X4LIFTLOC(...) [&]DETAIL_X4LIFT(, __VA_ARGS__)
#define X4LIFTM(...) DETAIL_X4LIFTM(.,  __VA_ARGS__)
#define X4LIFTMPTR(...) DETAIL_X4LIFTM(->, __VA_ARGS__)

#define DETAIL_X4LIFT(specs_, ...) \
	[[nodiscard]](auto&&... DETAIL_X4args) specs_ \
		X4ARPARAM( \
			(decltype(DETAIL_X4args)&&... DETAIL_X4args), \
			__VA_ARGS__(X4FWD(DETAIL_X4args)...) \
		)
#define DETAIL_X4LIFTM(access_, ...) \
	[][[nodiscard]](auto&& DETAIL_X4obj, auto&&... DETAIL_X4args) static \
		X4ARPARAM( \
			(decltype(DETAIL_X4obj)&& DETAIL_X4obj, decltype(DETAIL_X4args)&&... DETAIL_X4args), \
			(X4FWD(DETAIL_X4obj) access_ __VA_ARGS__(X4FWD(DETAIL_X4args)...)) \
		)
