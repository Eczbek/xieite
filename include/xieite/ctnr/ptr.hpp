#ifndef DETAIL_XIEITE_HEADER_CTNR_PTR
#	define DETAIL_XIEITE_HEADER_CTNR_PTR
#
#	include <cstddef>
#	include <stdexcept>
#	include <type_traits>
#	include <utility>
#	include "../pp/arrow.hpp"
#	include "../pp/debug.hpp"
#	include "../pp/fwd.hpp"

namespace xieite {
	template<typename T>
	struct ptr {
		T* data;

		[[nodiscard]] explicit(false) constexpr ptr(T* data = nullptr) noexcept
		: data(data) {}

		ptr(const xieite::ptr<T>&) = delete;

		[[nodiscard]] explicit(false) constexpr ptr(xieite::ptr<T>&& other) noexcept
		: data(other.release()) {}

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
			XIEITE_ARROW_RET(*this ? void(*this->data = XIEITE_FWD(x)) : void(), *this)

		[[nodiscard]] constexpr operator bool() const noexcept {
			return this->data;
		}

		// https://cplusplus.github.io/LWG/issue673
		[[nodiscard]] constexpr std::add_lvalue_reference_t<T> operator*() const noexcept(!XIEITE_DEBUG) {
			if constexpr (XIEITE_DEBUG) {
				if (!*this) {
					throw std::logic_error("nullptr dereference");
				}
			}
			return *this->data;
		}

		[[nodiscard]] constexpr T* operator->() const noexcept(!XIEITE_DEBUG) {
			if constexpr (XIEITE_DEBUG) {
				if (!*this) {
					throw std::logic_error("nullptr dereference");
				}
			}
			return this->data;
		}

		[[nodiscard]] constexpr T* get() const noexcept {
			return this->data;
		}

		constexpr void reset(T* data = nullptr) noexcept {
			delete this->data;
			this->data = data;
		}

		[[nodiscard]] constexpr T* release() noexcept {
			return std::exchange(this->data, nullptr);
		}
	};

	template<typename T>
	struct ptr<T[]> {
		T* data;
		
		[[nodiscard]] explicit(false) constexpr ptr(T* data = nullptr) noexcept
		: data(data) {}

		ptr(const xieite::ptr<T[]>&) = delete;

		[[nodiscard]] explicit(false) constexpr ptr(xieite::ptr<T[]>&& other) noexcept
		: data(other.release()) {}

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
			return this->data;
		}

		[[nodiscard]] constexpr T& operator[](std::size_t idx) const noexcept(!XIEITE_DEBUG) {
			if constexpr (XIEITE_DEBUG) {
				if (!*this) {
					throw std::logic_error("nullptr dereference");
				}
			}
			return this->data[idx];
		}

		[[nodiscard]] constexpr T* get() const noexcept {
			return this->data;
		}

		constexpr void reset(T* data = nullptr) noexcept {
			delete[] this->data;
			this->data = data;
		}

		[[nodiscard]] constexpr T* release() noexcept {
			return std::exchange(this->data, nullptr);
		}
	};
}

#endif
