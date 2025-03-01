#pragma once

namespace x4 {
	template<bool>
	struct setmvass {};

	template<>
	struct setmvass<false> {
		setmvass() = default;
		setmvass(const x4::setmvass<false>&) = default;
		setmvass(x4::setmvass<false>&&) = default;
		x4::setmvass<false>& operator=(const x4::setmvass<false>&) = default;
		auto operator=(x4::setmvass<false>&&) = delete;
	};
}
