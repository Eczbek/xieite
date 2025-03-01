#pragma once

namespace x4 {
	template<bool>
	struct setmvctor {};

	template<>
	struct setmvctor<false> {
		setmvctor() = default;
		setmvctor(const x4::setmvctor<false>&) = default;
		setmvctor(x4::setmvctor<false>&&) = delete;
		x4::setmvctor<false>& operator=(const x4::setmvctor<false>&) = default;
		x4::setmvctor<false>& operator=(x4::setmvctor<false>&&) = default;
	};
}
