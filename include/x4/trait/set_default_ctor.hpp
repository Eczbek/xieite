#pragma once

namespace x4 {
	template<bool>
	struct setdfltctor {};

	template<>
	struct setdfltctor<false> {
		setdfltctor() = delete;
		setdfltctor(const x4::setdfltctor<false>&) = default;
		setdfltctor(x4::setdfltctor<false>&&) = default;
		x4::setdfltctor<false>& operator=(const x4::setdfltctor<false>&) = default;
		x4::setdfltctor<false>& operator=(x4::setdfltctor<false>&&) = default;
	};
}
