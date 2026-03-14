#include <xte/data/array.hpp>
#include <xte/data/fixed_array.hpp>
#include <xte/trait/is_same.hpp>
#include <xte/util/as_c.hpp>
#include <xte/util/lvalue.hpp>
#include <xte/util/xvalue.hpp>
#include <ranges>

static_assert(([] {
	xte::array<int> a { 1, 2, 3 };
	xte::array<int> b = a;
	return a == b;
})());
static_assert(([] {
	xte::array<int> a;
	xte::array<int> b = xte::xvalue(a);
	return true;
})());
static_assert(xte::array<int>(std::from_range, xte::fixed_array<int, 1> { 5 })[0] == 5);

static_assert(xte::array<int>().size() == 0);
static_assert(xte::array<int>().capacity() == 0);

static_assert((xte::array<int> { 0 }).size() == 1);
static_assert((xte::array<int> { 0, 0 }).size() == 2);
static_assert((xte::array<int> { 0, 0, 0 }).size() == 3);

static_assert(xte::is_same<int&&, decltype(xte::array<int>()[0])>);
static_assert(xte::is_same<int&, decltype(xte::lvalue(xte::array<int>())[0])>);
static_assert(xte::is_same<const int&, decltype(xte::as_c(xte::lvalue(xte::array<int>())[0]))>);

static_assert(([] {
	xte::array<int> a;
	a.push(5);
	return a.size() == 1;
})());

static_assert(([] {
	xte::array<int> a;
	a.push(5);
	a.push(3);
	return (a.pop() == 3) && (a.size() == 1);
})());


static_assert(([] {
	xte::array<int> a;
	a.insert(0, 0);
	return a == xte::array<int> { 0 };
})());
static_assert(([] {
	xte::array<int> a { 0, 1, 2 };
	a.insert(0, 3);
	return a == xte::array<int> { 3, 0, 1, 2 };
})());
static_assert(([] {
	xte::array<int> a { 0, 1, 2 };
	a.insert(1, 3);
	return a == xte::array<int> { 0, 3, 1, 2 };
})());
static_assert(([] {
	xte::array<int> a { 0, 1, 2 };
	a.insert(2, 3);
	return a == xte::array<int> { 0, 1, 3, 2 };
})());
static_assert(([] {
	xte::array<int> a { 0, 1, 2 };
	a.insert(3, 3);
	return a == xte::array<int> { 0, 1, 2, 3 };
})());
static_assert(([] {
	xte::array<int> a { 0, 1, 2 };
	a.insert_range(0, xte::array<int> { 3, 4 });
	return a == xte::array<int> { 3, 4, 0, 1, 2 };
})());
static_assert(([] {
	xte::array<int> a { 0, 1, 2 };
	a.insert_range(1, xte::array<int> { 3, 4 });
	return a == xte::array<int> { 0, 3, 4, 1, 2 };
})());
static_assert(([] {
	xte::array<int> a { 0, 1, 2 };
	a.insert_range(2, xte::array<int> { 3, 4 });
	return a == xte::array<int> { 0, 1, 3, 4, 2 };
})());
static_assert(([] {
	xte::array<int> a { 0, 1, 2 };
	a.insert_range(3, xte::array<int> { 3, 4 });
	return a == xte::array<int> { 0, 1, 2, 3, 4 };
})());
static_assert(([] {
	xte::array<int> a { 0, 1, 2 };
	a.insert_range(2, xte::array<int> { 3, 4, 5, 6 });
	return a == xte::array<int> { 0, 1, 3, 4, 5, 6, 2 };
})());
