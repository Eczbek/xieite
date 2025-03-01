#pragma once

namespace x4 {
	template<bool>
	struct setcpctor {};

	template<>
	struct setcpctor<false> {
		setcpctor() = default;
		setcpctor(const x4::setcpctor<false>&) = delete;
		setcpctor(x4::setcpctor<false>&&) = default;
		x4::setcpctor<false>& operator=(const x4::setcpctor<false>&) = default;
		x4::setcpctor<false>& operator=(x4::setcpctor<false>&&) = default;
	};
}
