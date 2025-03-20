#pragma once

#include <cstddef>
#include <stdexcept>
#include <type_traits>
#include <utility>
#include "../pp/arrow.hpp"
#include "../pp/debug.hpp"
#include "../pp/fwd.hpp"

namespace xieite {
	template<typename T>
	struct ptr {
		T* _data;

		[[nodiscard]] explicit(false) constexpr ptr(T* data = nullptr) noexcept
		: _data(data) {}

		ptr(const xieite::ptr<T>&) = delete;

		[[nodiscard]] explicit(false) constexpr ptr(xieite::ptr<T>&& other) noexcept
		: _data(other.release()) {}

		constexpr ~ptr() {
			this->reset();
		}

		void operator=(const xieite::ptr<T>&) = delete;

		constexpr xieite::ptr<T>& operator=(xieite::ptr<T>&& other) noexcept {
			this->reset(other.release());
			return *this;
		}

		constexpr xieite::ptr<T>& operator=(T* data) noexcept {
			this->reset(data);
			return *this;
		}

		constexpr xieite::ptr<T>& operator=(auto&& x)
			XIEITE_ARROW_RET(*this ? void(*this->_data = XIEITE_FWD(x)) : void(), *this)

		[[nodiscard]] constexpr operator bool() const noexcept {
			return this->_data;
		}

		// https://cplusplus.github.io/LWG/issue673
		[[nodiscard]] constexpr std::add_lvalue_reference_t<T> operator*() const noexcept(!XIEITE_DEBUG) {
			if constexpr (XIEITE_DEBUG) {
				if (!*this) {
					throw std::logic_error("nullptr dereference");
				}
			}
			return *this->_data;
		}

		[[nodiscard]] constexpr T* operator->() const noexcept(!XIEITE_DEBUG) {
			if constexpr (XIEITE_DEBUG) {
				if (!*this) {
					throw std::logic_error("nullptr dereference");
				}
			}
			return this->_data;
		}

		[[nodiscard]] constexpr T* get() const noexcept {
			return this->_data;
		}

		constexpr void reset(T* data = nullptr) noexcept {
			delete this->_data;
			this->_data = data;
		}

		[[nodiscard]] constexpr T* release() noexcept {
			return std::exchange(this->_data, nullptr);
		}
	};

	template<typename T>
	struct ptr<T[]> {
		T* _data;
		
		[[nodiscard]] explicit(false) constexpr ptr(T* data = nullptr) noexcept
		: _data(data) {}

		ptr(const xieite::ptr<T[]>&) = delete;

		[[nodiscard]] explicit(false) constexpr ptr(xieite::ptr<T[]>&& other) noexcept
		: _data(other.release()) {}

		constexpr ~ptr() {
			this->reset();
		}

		void operator=(const xieite::ptr<T[]>&) = delete;

		constexpr xieite::ptr<T[]>& operator=(xieite::ptr<T[]>&& other) noexcept {
			this->reset(other.release());
			return *this;
		}

		constexpr xieite::ptr<T[]>& operator=(T* data) noexcept {
			this->reset(data);
			return *this;
		}

		[[nodiscard]] constexpr operator bool() const noexcept {
			return this->_data;
		}

		[[nodiscard]] constexpr T& operator[](std::size_t idx) const noexcept(!XIEITE_DEBUG) {
			if constexpr (XIEITE_DEBUG) {
				if (!*this) {
					throw std::logic_error("nullptr dereference");
				}
			}
			return this->_data[idx];
		}

		[[nodiscard]] constexpr T* get() const noexcept {
			return this->_data;
		}

		constexpr void reset(T* data = nullptr) noexcept {
			delete[] this->_data;
			this->_data = data;
		}

		[[nodiscard]] constexpr T* release() noexcept {
			return std::exchange(this->_data, nullptr);
		}
	};
}
