#pragma once

#define XIEITE_CAT(x, ...) XIEITE_PCAT(x, __VA_ARGS__)
#define XIEITE_CATR(x, ...) XIEITE_PCATR(x, __VA_ARGS__)
#define XIEITE_PCAT(x, ...) x##__VA_ARGS__
#define XIEITE_PCATR(x, ...) __VA_ARGS__##x
#define XIEITE_CAT_A(x) XIEITE_PCAT(x,
#define XIEITE_CAT_B(x) XIEITE_PCATR(x,
