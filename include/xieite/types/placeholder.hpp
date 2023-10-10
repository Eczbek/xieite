#pragma once

namespace xieite::types {
	struct Placeholder {
		template<typename Type>
		constexpr operator Type&() const noexcept;

		template<typename Type>
		constexpr operator Type&&() const noexcept;
	};
}
