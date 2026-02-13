#include <xte/util/at.hpp>

static_assert(xte::at<0>(1, 2, 3, 4, 5) == 1);
static_assert(xte::at<1>(1, 2, 3, 4, 5) == 2);
static_assert(xte::at<2>(1, 2, 3, 4, 5) == 3);
static_assert(xte::at<3>(1, 2, 3, 4, 5) == 4);
static_assert(xte::at<4>(1, 2, 3, 4, 5) == 5);
