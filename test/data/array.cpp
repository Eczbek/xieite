#include <xte/data/array.hpp>
#include <xte/data/fixed_array.hpp>
#include <xte/trait/is_same.hpp>
#include <xte/util/xvalue.hpp>

static_assert(([] {
	xte::array<int> a;
	xte::array<int> b = a;
	return true;
})());
static_assert(([] {
	xte::array<int> a;
	xte::array<int> b = xte::xvalue(a);
	return true;
})());
static_assert(xte::array<int>(xte::fixed_array<int, 1> { 5 })[0] == 5);

static_assert(!xte::array<int>().size());
static_assert(!xte::array<int>().capacity());
static_assert(!xte::array<int>().data());

static_assert(xte::is_same<int&&, decltype(xte::array<int>()[0])>);
static_assert(([] {
	xte::array<int> a;
	return xte::is_same<int&, decltype(a[0])>;
})());
static_assert(([] {
	const xte::array<int> a;
	return xte::is_same<const int&, decltype(a[0])>;
})());

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
