#pragma once

#define XIEITE_CALL(...) __VA_ARGS__ DETAIL_XIEITE_CALL_##__VA_OPT__(1)

#define DETAIL_XIEITE_CALL_(...) __VA_ARGS__
#define DETAIL_XIEITE_CALL_1(...) (__VA_ARGS__)
