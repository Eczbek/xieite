#ifndef DETAIL_XTE_HEADER_DATA_PTR
#	define DETAIL_XTE_HEADER_DATA_PTR
#
#	include "../preproc/arrow.hpp"
#	include "../preproc/fwd.hpp"
#	include "../trait/non_copyable.hpp"
#	include "../util/exchange.hpp"
#	include "../util/types.hpp"
#	include <new>

namespace xte {
	template<typename T>
	struct ptr : xte::non_copyable {
	private:
		T* _data;

	public:
		[[nodiscard]] explicit(false) constexpr ptr(T* data = nullptr) noexcept
		: _data(data) {}

		[[nodiscard]] explicit(false) constexpr ptr(xte::ptr<T>&& other) noexcept
		: _data(other.release()) {}

		constexpr ~ptr() {
			this->reset();
		}

		constexpr xte::ptr<T>& operator=(xte::ptr<T>&& other) noexcept {
			this->reset(other.release());
			return *this;
		}

		constexpr xte::ptr<T>& operator=(T* data) noexcept {
			this->reset(data);
			return *this;
		}

		constexpr auto operator=(auto&& x) XTE_ARROW(
			(this->_data ? void(*this->_data = XTE_FWD(x)) : void()),
			*this
		)

		[[nodiscard]] explicit constexpr operator bool() const noexcept {
			return this->_data;
		}

		[[nodiscard]] constexpr T& operator*() const noexcept {
			return *this->_data;
		}

		[[nodiscard]] constexpr auto* operator->(this auto&& self) noexcept {
			return self._data;
		}

		[[nodiscard]] friend constexpr bool operator==(const xte::ptr<T>& lhs, const T* rhs) noexcept {
			return lhs._data == rhs;
		}

		[[nodiscard]] constexpr auto* data(this auto&& self) noexcept {
			return self._data;
		}

		constexpr void reset(T* data = nullptr) noexcept {
			delete this->_data;
			this->_data = data;
		}

		[[nodiscard]] constexpr T* release() noexcept {
			return xte::exchange(this->_data, nullptr);
		}

		[[nodiscard]] constexpr auto* begin(this auto&& self) noexcept {
			return self._data;
		}

		[[nodiscard]] constexpr const T* end() const noexcept {
			return this->_data + !!this->_data;
		}

		[[nodiscard]] static constexpr xte::ptr<T> make(auto&&... args) noexcept(false) {
			return new T(XTE_FWD(args)...);
		}

		[[nodiscard]] static constexpr auto make_noex(auto&&... args) XTE_ARROW(
			xte::ptr<T>(new(std::nothrow) T(XTE_FWD(args)...))
		)

		[[nodiscard]] static constexpr xte::ptr<T> make_default() noexcept(false) {
			return new T;
		}

		[[nodiscard]] static constexpr xte::ptr<T> make_default_noex() noexcept {
			return new(std::nothrow) T;
		}
	};

	template<typename T>
	struct ptr<T[]> : xte::non_copyable {
	private:
		T* _data;

	public:
		[[nodiscard]] explicit(false) constexpr ptr(T* data = nullptr) noexcept
		: _data(data) {}

		[[nodiscard]] explicit(false) constexpr ptr(xte::ptr<T[]>&& other) noexcept
		: _data(other.release()) {}

		constexpr ~ptr() {
			this->reset();
		}

		constexpr xte::ptr<T[]>& operator=(xte::ptr<T[]>&& other) noexcept {
			this->reset(other.release());
			return *this;
		}

		constexpr xte::ptr<T[]>& operator=(T* data) noexcept {
			this->reset(data);
			return *this;
		}

		[[nodiscard]] explicit(false) constexpr operator bool() const noexcept {
			return this->_data;
		}

		[[nodiscard]] constexpr auto&& operator[](this auto&& self, xte::uz index) noexcept {
			return XTE_FWD(self)._data[index];
		}

		[[nodiscard]] friend constexpr bool operator==(const xte::ptr<T[]>& lhs, const T* rhs) noexcept {
			return lhs._data == rhs;
		}

		[[nodiscard]] constexpr auto* data(this auto&& self) noexcept {
			return self._data;
		}

		constexpr void reset(T* data = nullptr) noexcept {
			::delete[] this->_data;
			this->_data = data;
		}

		[[nodiscard]] constexpr T* release() noexcept {
			return xte::exchange(this->_data, nullptr);
		}

		[[nodiscard]] constexpr auto* begin(this auto&& self) noexcept {
			return self._data;
		}

		[[nodiscard]] constexpr const T* end() const noexcept {
			return this->_data + !!this->_data;
		}

		[[nodiscard]] static constexpr xte::ptr<T[]> make(xte::uz size, auto&&... args) noexcept(false) {
			return ::new T[size] { XTE_FWD(args)... };
		}

		[[nodiscard]] static constexpr auto make_noex(xte::uz size, auto&&... args) XTE_ARROW(
			xte::ptr<T[]>(::new(std::nothrow) T[size] { XTE_FWD(args)... })
		)

		[[nodiscard]] static constexpr xte::ptr<T[]> make_default(xte::uz size) noexcept(false) {
			return ::new T[size];
		}

		[[nodiscard]] static constexpr xte::ptr<T[]> make_default_noex(xte::uz size) noexcept {
			return ::new(std::nothrow) T[size];
		}
	};
}

#endif
