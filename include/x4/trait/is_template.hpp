#pragma once

#include "../trait/isspec.hpp"

namespace x4 {
	template<template<typename...> typename M, typename... Ts>
	concept istplt = (... && x4::isspec<Ts, M>);
}
