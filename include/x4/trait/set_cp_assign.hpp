#pragma once

namespace x4 {
	template<bool>
	struct setcpass {};

	template<>
	struct setcpass<false> {
		setcpass() = default;
		setcpass(const x4::setcpass<false>&) = default;
		setcpass(x4::setcpass<false>&&) = default;
		auto operator=(const x4::setcpass<false>&) = delete;
		x4::setcpass<false>& operator=(x4::setcpass<false>&&) = default;
	};
}
