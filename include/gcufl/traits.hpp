#pragma once

#include <chrono>
#include <concepts>
#include <ostream>
#include <type_traits>


namespace gcufl::traits {
	template <typename T>
	concept Streamable = requires(std::ostream& stream, const T& value) {
		{ stream << value } -> std::convertible_to<std::ostream&>;
  	};

	template <typename T>
	concept Arithmetic = std::is_arithmetic_v<T>;

	template <typename>
	struct is_duration
	: std::false_type {};

	template <gcufl::traits::Arithmetic R, std::intmax_t N, std::intmax_t D>
	struct is_duration<std::chrono::duration<R, std::ratio<N, D>>>
	: std::true_type {};

	template <typename T>
	constexpr bool is_duration_v = gcufl::traits::is_duration<T>::value;

	template <typename T>
	concept Duration = gcufl::traits::is_duration_v<std::remove_cv_t<T>>;
}
