#include <xte/data/fixed_array.hpp>
#include <xte/trait/is_same.hpp>

static_assert(xte::is_same<int, xte::fixed_array<int, 3>::value_type>);

static_assert(xte::fixed_array<int, 3>::size == 3);
static_assert(xte::fixed_array<int, 3>::size() == 3);
static_assert(xte::fixed_array<int, 3>().size == 3);
static_assert(xte::fixed_array<int, 3>().size() == 3);

static_assert((xte::fixed_array<int, 3> { 0, 1, 2 })[0] == 0);
static_assert((xte::fixed_array<int, 3> { 0, 1, 2 })[1] == 1);
static_assert((xte::fixed_array<int, 3> { 0, 1, 2 })[2] == 2);

static_assert((xte::fixed_array<int, 3> { 0, 1, 2 }).data()[0] == 0);
static_assert((xte::fixed_array<int, 3> { 0, 1, 2 }).data()[1] == 1);
static_assert((xte::fixed_array<int, 3> { 0, 1, 2 }).data()[2] == 2);

static_assert(([] {
	auto [_0, _1, _2] = xte::fixed_array { 0., 1, 2 };
	return (_0 == 0)
		&& (_1 == 1)
		&& (_2 == 2);
})());

static_assert(xte::fixed_array { 0, 1, 2 } < xte::fixed_array { 0, 1, 3 });

static_assert(([] {
	xte::fixed_array a = { 1 };
	a = xte::fixed_array { 2 };
	return a[0] == 2;
})());

static_assert((xte::fixed_array { 1, 2 } + xte::fixed_array { 3, 4 }) == xte::fixed_array { 1, 2, 3, 4 });

static_assert(xte::is_derived_from_instance_of<xte::remove_cvref<xte::fixed_array<int, 2>&&>, ^^xte::fixed_array>);
static_assert(xte::is_same<xte::fixed_array<int, 2>::value_type, xte::fixed_array<int, 2>::value_type>);
