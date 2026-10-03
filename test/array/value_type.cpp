#include <xte/array.hpp>
#include <xte/qual_traits.hpp>
#include <iterator>

static_assert(xte::is_same<xte::array<int>::value_type, int>);
static_assert(xte::is_same<xte::array<int>::reference, int&>);
static_assert(xte::is_same<xte::array<int>::const_reference, int const&>);
static_assert(xte::is_same<xte::array<int>::pointer, int*>);
static_assert(xte::is_same<xte::array<int>::const_pointer, int const*>);
static_assert(xte::is_same<xte::array<int>::iterator, int*>);
static_assert(xte::is_same<xte::array<int>::const_iterator, int const*>);
static_assert(xte::is_same<xte::array<int>::reverse_iterator, std::reverse_iterator<int*>>);
static_assert(xte::is_same<xte::array<int>::const_reverse_iterator, std::reverse_iterator<int const*>>);
