#pragma once

#include "../pp/fwd.hpp"

namespace x4 {
	template<typename T>
	concept isnoexbtest = requires(T&& x) {
		{ static_cast<bool>(X4FWD(x)) } noexcept;
		{ static_cast<bool>(!X4FWD(x)) } noexcept;
		{ static_cast<void(*)(bool) noexcept>(nullptr)(X4FWD(x)) } noexcept;
		{ static_cast<void(*)(bool) noexcept>(nullptr)(!X4FWD(x)) } noexcept;
	};
}
