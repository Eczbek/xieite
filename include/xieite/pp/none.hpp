#pragma once

#define XIEITE_NONE(...) DETAIL_XIEITE_NONE_##__VA_OPT__(1)

#define DETAIL_XIEITE_NONE_ 1
#define DETAIL_XIEITE_NONE_1 0
