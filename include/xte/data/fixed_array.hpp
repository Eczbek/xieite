#ifndef DETAIL_XTE_HEADER_DATA_FIXED_ARRAY
#	define DETAIL_XTE_HEADER_DATA_FIXED_ARRAY
#
#	include "../core/types.hpp"
#	include "../meta/type.hpp"
#	include "../meta/wrap_value.hpp"
#	include "../preproc/fwd.hpp"

namespace xte {
	template<typename T, xte::uz n>
	struct fixed_array {
		using type = T;

		static constexpr auto size = xte::wrap_value<n>();

		[[nodiscard]] constexpr auto&& operator[](this auto&& self, xte::uz index) noexcept {
			return XTE_FWD(self).DETAIL_XTE_data[index];
		}

		[[nodiscard]] constexpr auto* data(this auto&& self) noexcept {
			return self.DETAIL_XTE_data;
		}

		[[nodiscard]] constexpr auto* begin(this auto&& self) noexcept {
			return self.data();
		}

		[[nodiscard]] constexpr auto* end(this auto&& self) noexcept {
			return self.data() + n;
		}

		xte::type<T[n]> DETAIL_XTE_data;
	};

	template<typename T>
	struct fixed_array<T, 0> {
		using type = T;

		static constexpr auto size = xte::wrap_value<0uz>();

		[[nodiscard]] constexpr const T* data() noexcept {
			return nullptr;
		}

		[[nodiscard]] constexpr const T* begin() noexcept {
			return nullptr;
		}

		[[nodiscard]] constexpr const T* end() noexcept {
			return nullptr;
		}
	};
}

#endif
