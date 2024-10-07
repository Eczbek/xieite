#pragma once

#include <concepts>
#include <type_traits>

#define XIEITE_FORWARD(...) static_cast<std::conditional_t<std::same_as<decltype(__VA_ARGS__), decltype((__VA_ARGS__))>, decltype(__VA_ARGS__), std::add_rvalue_reference_t<decltype(__VA_ARGS__)>>(__VA_ARGS__)
