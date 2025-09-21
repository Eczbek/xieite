#ifndef DETAIL_XIEITE_HEADER_DATA_PTR
#	define DETAIL_XIEITE_HEADER_DATA_PTR
#
#	include <cstddef>
#	include <stdexcept>
#	include <type_traits>
#	include <utility>
#	include "../pp/arrow.hpp"
#	include "../pp/debug.hpp"
#	include "../pp/fwd.hpp"

namespace xieite {
	template<typename Value>
	struct ptr {
		Value* value;

		[[nodiscard]] explicit(false) constexpr ptr(Value* value = nullptr) noexcept
		: value(value) {}

		ptr(const xieite::ptr<Value>&) = delete;

		[[nodiscard]] explicit(false) constexpr ptr(xieite::ptr<Value>&& other) noexcept
		: value(other.release()) {}

		constexpr ~ptr() {
			this->reset();
		}

		void operator=(const xieite::ptr<Value>&) = delete;

		constexpr xieite::ptr<Value>& operator=(xieite::ptr<Value>&& other) noexcept {
			this->reset(other.release());
			return *this;
		}

		constexpr xieite::ptr<Value>& operator=(Value* value) noexcept {
			this->reset(value);
			return *this;
		}

		constexpr xieite::ptr<Value>& operator=(auto&& x) XIEITE_ARROW_RET(
			*this ? void(*this->value = XIEITE_FWD(x)) : void(),
			*this
		)

		[[nodiscard]] constexpr operator bool() const noexcept {
			return this->value;
		}

		// https://cplusplus.github.io/LWG/issue673
		[[nodiscard]] constexpr std::add_lvalue_reference_t<Value> operator*() const noexcept(!XIEITE_DEBUG) {
			if constexpr (XIEITE_DEBUG) {
				if (!*this) {
					throw std::logic_error("nullptr dereference");
				}
			}
			return *this->value;
		}

		[[nodiscard]] constexpr Value* operator->() const noexcept(!XIEITE_DEBUG) {
			if constexpr (XIEITE_DEBUG) {
				if (!*this) {
					throw std::logic_error("nullptr dereference");
				}
			}
			return this->value;
		}

		[[nodiscard]] constexpr Value* get() const noexcept {
			return this->value;
		}

		constexpr void reset(Value* value = nullptr) noexcept {
			delete this->value;
			this->value = value;
		}

		[[nodiscard]] constexpr Value* release() noexcept {
			return std::exchange(this->value, nullptr);
		}
	};

	template<typename Value>
	struct ptr<Value[]> {
		Value* array;
		
		[[nodiscard]] explicit(false) constexpr ptr(Value* array = nullptr) noexcept
		: array(array) {}

		ptr(const xieite::ptr<Value[]>&) = delete;

		[[nodiscard]] explicit(false) constexpr ptr(xieite::ptr<Value[]>&& other) noexcept
		: array(other.release()) {}

		constexpr ~ptr() {
			this->reset();
		}

		void operator=(const xieite::ptr<Value[]>&) = delete;

		constexpr xieite::ptr<Value[]>& operator=(xieite::ptr<Value[]>&& other) noexcept {
			this->reset(other.release());
			return *this;
		}

		constexpr xieite::ptr<Value[]>& operator=(Value* array) noexcept {
			this->reset(array);
			return *this;
		}

		[[nodiscard]] constexpr operator bool() const noexcept {
			return this->array;
		}

		[[nodiscard]] constexpr Value& operator[](std::size_t idx) const noexcept(!XIEITE_DEBUG) {
			if constexpr (XIEITE_DEBUG) {
				if (!*this) {
					throw std::logic_error("nullptr dereference");
				}
			}
			return this->array[idx];
		}

		[[nodiscard]] constexpr Value* get() const noexcept {
			return this->array;
		}

		constexpr void reset(Value* array = nullptr) noexcept {
			delete[] this->array;
			this->array = array;
		}

		[[nodiscard]] constexpr Value* release() noexcept {
			return std::exchange(this->array, nullptr);
		}
	};
}

#endif
