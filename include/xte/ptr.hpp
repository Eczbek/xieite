#ifndef DETAIL_XTE_HEADER_PTR
#	define DETAIL_XTE_HEADER_PTR
#
#	include "./aliases.hpp"
#	include "./class_traits.hpp"
#	include "./exchange.hpp"
#	include "./macros.hpp"
#	include "./qual_traits.hpp"
#	include <iterator>
#	include <new>
#	include <type_traits>

namespace xte {
	template<typename item_type>
	struct ptr : xte::non_copyable {
	private:
		item_type* _data;

	public:
		using value_type = item_type;

		[[nodiscard]] constexpr explicit(false) ptr(item_type* data = nullptr) noexcept
		: _data(data) {}

		[[nodiscard]] constexpr explicit(false) ptr(xte::ptr<item_type>&& other) noexcept
		: _data(other.release()) {}

		constexpr ~ptr() {
			this->reset();
		}

		constexpr xte::ptr<item_type>& operator=(xte::ptr<item_type>&& other) noexcept {
			this->reset(other.release());
			return *this;
		}

		constexpr xte::ptr<item_type>& operator=(item_type* data) noexcept {
			this->reset(data);
			return *this;
		}

		constexpr auto operator=(auto&& x) XTE_RETURNS(
			(this->_data ? void(*this->_data = XTE_FWD(x)) : void()),
			*this
		)

		[[nodiscard]] constexpr explicit operator bool() const noexcept {
			return this->_data;
		}

		[[nodiscard]] constexpr explicit operator item_type*() const noexcept {
			return this->_data;
		}

		[[nodiscard]] constexpr item_type& operator*() const noexcept {
			return *this->_data;
		}

		[[nodiscard]] constexpr auto* operator->(this auto&& self) noexcept {
			return self._data;
		}

		[[nodiscard]] constexpr decltype(auto) operator->*(this auto&& self, xte::is_member_ptr_of<item_type> auto&& member) noexcept {
			if constexpr (std::is_member_function_pointer_v<xte::drop_ref<decltype(member)>>) {
				return XTE_LIFT_LOCAL((XTE_FWD(self)._data->*member));
			} else {
				return xte::like<decltype(self)>(self._data->*member);
			}
		}

		[[nodiscard]] friend constexpr bool operator==(xte::ptr<item_type> const& lhs, item_type const* rhs) noexcept {
			return lhs._data == rhs;
		}

		[[nodiscard]] constexpr auto* data(this auto&& self) noexcept {
			return self._data;
		}

		constexpr void reset(item_type* data = nullptr) noexcept {
			::delete this->_data;
			this->_data = data;
		}

		[[nodiscard]] constexpr item_type* release() noexcept {
			return xte::exchange(this->_data, nullptr);
		}

		[[nodiscard]] constexpr auto* begin(this auto&& self) noexcept {
			return self._data;
		}

		[[nodiscard]] constexpr item_type const* cbegin() const noexcept {
			return this->begin();
		}

		[[nodiscard]] constexpr auto* end(this auto&& self) noexcept {
			return self._data + !!self._data;
		}

		[[nodiscard]] constexpr item_type const* cend() const noexcept {
			return this->end();
		}

		[[nodiscard]] constexpr auto rbegin(this auto&& self) noexcept {
			return std::reverse_iterator(self.end());
		}

		[[nodiscard]] constexpr auto crbegin() const noexcept {
			return this->rbegin();
		}

		[[nodiscard]] constexpr auto rend(this auto&& self) noexcept {
			return std::reverse_iterator(self.begin());
		}

		[[nodiscard]] constexpr auto crend() const noexcept {
			return this->rend();
		}

		[[nodiscard]] static constexpr xte::ptr<item_type> make(auto&&... args) noexcept(false) {
			return ::new item_type(XTE_FWD(args)...);
		}

		[[nodiscard]] static constexpr auto make_noex(auto&&... args) XTE_RETURNS(
			xte::ptr<item_type>(::new(std::nothrow) item_type(XTE_FWD(args)...))
		)

		[[nodiscard]] static constexpr xte::ptr<item_type> make_default() noexcept(false) {
			return ::new item_type;
		}

		[[nodiscard]] static constexpr xte::ptr<item_type> make_default_noex() noexcept {
			return ::new(std::nothrow) item_type;
		}
	};

	template<typename item_type>
	struct ptr<item_type[]> : xte::non_copyable {
	private:
		item_type* _data;

	public:
		[[nodiscard]] constexpr explicit(false) ptr(item_type* data = nullptr) noexcept
		: _data(data) {}

		[[nodiscard]] constexpr explicit(false) ptr(xte::ptr<item_type[]>&& other) noexcept
		: _data(other.release()) {}

		constexpr ~ptr() {
			this->reset();
		}

		constexpr xte::ptr<item_type[]>& operator=(xte::ptr<item_type[]>&& other) noexcept {
			this->reset(other.release());
			return *this;
		}

		constexpr xte::ptr<item_type[]>& operator=(item_type* data) noexcept {
			this->reset(data);
			return *this;
		}

		[[nodiscard]] constexpr explicit operator bool() const noexcept {
			return this->_data;
		}

		[[nodiscard]] constexpr explicit operator item_type*() const noexcept {
			return this->_data;
		}

		[[nodiscard]] constexpr auto&& operator[](this auto&& self, xte::uz index) noexcept {
			return XTE_FWD(self)._data[index];
		}

		[[nodiscard]] friend constexpr bool operator==(xte::ptr<item_type[]> const& lhs, item_type const* rhs) noexcept {
			return lhs._data == rhs;
		}

		[[nodiscard]] constexpr auto* data(this auto&& self) noexcept {
			return self._data;
		}

		constexpr void reset(item_type* data = nullptr) noexcept {
			::delete[] this->_data;
			this->_data = data;
		}

		[[nodiscard]] constexpr item_type* release() noexcept {
			return xte::exchange(this->_data, nullptr);
		}

		[[nodiscard]] constexpr auto* begin(this auto&& self) noexcept {
			return self._data;
		}

		[[nodiscard]] constexpr item_type const* end() const noexcept {
			return this->_data + !!this->_data;
		}

		[[nodiscard]] static constexpr xte::ptr<item_type[]> make(xte::uz size, auto&&... args) noexcept(false) {
			return ::new item_type[size] { XTE_FWD(args)... };
		}

		[[nodiscard]] static constexpr auto make_noex(xte::uz size, auto&&... args) XTE_RETURNS(
			xte::ptr<item_type[]>(::new(std::nothrow) item_type[size] { XTE_FWD(args)... })
		)

		[[nodiscard]] static constexpr xte::ptr<item_type[]> make_default(xte::uz size) noexcept(false) {
			return ::new item_type[size];
		}

		[[nodiscard]] static constexpr xte::ptr<item_type[]> make_default_noex(xte::uz size) noexcept {
			return ::new(std::nothrow) item_type[size];
		}
	};
}

#endif
