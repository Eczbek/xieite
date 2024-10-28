#pragma once

#define XIEITE_ARROW(...) noexcept(noexcept(__VA_ARGS__)) -> decltype(__VA_ARGS__) { return __VA_ARGS__; }
#define XIEITE_ARROW_CTOR(...) noexcept(noexcept(__VA_ARGS__)) : __VA_ARGS__ {}
