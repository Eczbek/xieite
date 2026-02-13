#include <xte/meta/value_at.hpp>

static_assert('a' == xte::value_at<0, 'a', 'b', 'c', 'd', 'e', 'f'>);
static_assert('b' == xte::value_at<1, 'a', 'b', 'c', 'd', 'e', 'f'>);
static_assert('c' == xte::value_at<2, 'a', 'b', 'c', 'd', 'e', 'f'>);
static_assert('d' == xte::value_at<3, 'a', 'b', 'c', 'd', 'e', 'f'>);
static_assert('e' == xte::value_at<4, 'a', 'b', 'c', 'd', 'e', 'f'>);
static_assert('f' == xte::value_at<5, 'a', 'b', 'c', 'd', 'e', 'f'>);
