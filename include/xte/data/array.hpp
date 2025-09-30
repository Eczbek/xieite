#ifndef DETAIL_XTE_HEADER_DATA_ARRAY
#	define DETAIL_XTE_HEADER_DATA_ARRAY
#
#	include "../core/types.hpp"
#	include "../data/ptr.hpp"

namespace xte {
	template<typename T>
	struct array {
	private:
		xte::uz _size = 0;
		xte::uz _capacity = 0;
		xte::ptr<T[]> _data;

	public:
		[[nodiscard]] explicit(false) constexpr array() = default;

		[[nodiscard]] constexpr xte::uz size() const noexcept {
			return this->_size;
		}

		[[nodiscard]] constexpr xte::uz capacity() const noexcept {
			return this->_capacity;
		}

		[[nodiscard]] constexpr auto* data(this auto&& self) noexcept {
			return self._data.data();
		}
	};
}

#endif
