#pragma once

#define X4CAT(x, ...) X4PCAT(x, __VA_ARGS__)
#define X4CATR(x, ...) X4PCATR(x, __VA_ARGS__)
#define X4PCAT(x, ...) x##__VA_ARGS__
#define X4PCATR(x, ...) __VA_ARGS__##x
#define X4CAT_A(x) X4PCAT(x,
#define X4CAT_B(x) X4PCATR(x,
