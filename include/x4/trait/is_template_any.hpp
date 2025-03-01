#pragma once

#include "../trait/istemplate.hpp"

namespace x4 {
	template<template<typename...> typename M, typename... Ts>
	concept istpltany = (... || x4::istemplate<M, Ts>);
}
