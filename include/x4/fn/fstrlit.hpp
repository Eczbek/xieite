#pragma once

#include "../ctnr/fstr.hpp"

namespace x4::fstrlit {
	template<x4::fstr fstr>
	[[nodiscard]] consteval auto operator""_fstr() noexcept {
		return fstr;
	}
}
