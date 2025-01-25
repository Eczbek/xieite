#pragma once

#include "../trait/is_spec.hpp"

namespace xieite {
	template<template<typename...> typename M, typename... Ts>
	concept is_template = (... && xieite::is_spec<Ts, M>);
}
