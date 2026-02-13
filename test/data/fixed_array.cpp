#include <xte/data/fixed_array.hpp>
#include <xte/trait/is_same.hpp>

static_assert(xte::is_same<int, xte::fixed_array<int, 3>::type>);

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
