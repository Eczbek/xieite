#include <xte/data/array.hpp>
#include <xte/trait/is_same.hpp>
#include <iterator>

static_assert(xte::is_same<xte::array<int>::value_type, int>);
static_assert(xte::is_same<xte::array<int>::reference, int&>);
static_assert(xte::is_same<xte::array<int>::const_reference, const int&>);
static_assert(xte::is_same<xte::array<int>::pointer, int*>);
static_assert(xte::is_same<xte::array<int>::const_pointer, const int*>);
static_assert(xte::is_same<xte::array<int>::iterator, int*>);
static_assert(xte::is_same<xte::array<int>::const_iterator, const int*>);
static_assert(xte::is_same<xte::array<int>::reverse_iterator, std::reverse_iterator<int*>>);
static_assert(xte::is_same<xte::array<int>::const_reverse_iterator, std::reverse_iterator<const int*>>);
