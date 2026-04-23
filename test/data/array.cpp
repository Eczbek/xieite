#include <xte/data/array.hpp>
#include <xte/trait/is_copy_constructible.hpp>
#include <xte/trait/is_noex_move_constructible.hpp>
#include <xte/trait/is_same.hpp>
#include <xte/util/as_c.hpp>
#include <xte/util/lvalue.hpp>
#include <xte/util/numbers.hpp>
#include <ranges>

static_assert(xte::is_same<xte::array<int>::value_type, int>);
static_assert(xte::is_same<xte::array<int>::reference, int&>);
static_assert(xte::is_same<xte::array<int>::const_reference, const int&>);
static_assert(xte::is_same<xte::array<int>::pointer, int*>);
static_assert(xte::is_same<xte::array<int>::const_pointer, const int*>);
static_assert(xte::is_same<xte::array<int>::iterator, int*>);
static_assert(xte::is_same<xte::array<int>::const_iterator, const int*>);
static_assert(xte::is_same<xte::array<int>::reverse_iterator, std::reverse_iterator<int*>>);
static_assert(xte::is_same<xte::array<int>::const_reverse_iterator, std::reverse_iterator<const int*>>);

static_assert(requires { { xte::array<int>() } noexcept; });
static_assert(xte::is_copy_constructible<xte::array<int>>);
static_assert(xte::is_noex_move_constructible<xte::array<int>>);
static_assert(requires { xte::array<int> { 0, 1, 2 }; });
static_assert(requires { xte::array<int>(std::from_range, typename[:^^int[]:] { 0, 1, 2 }); });
static_assert(xte::array<int>(std::from_range, typename[:^^int[]:] { 5 })[0] == 5);
static_assert(requires { xte::array<int>(3); });
static_assert(requires { xte::array<int>(3, 0); });

static_assert(requires { xte::array { 0, 1, 2 }; });

static_assert(([] {
	xte::array<int> a;
	a = xte::array<int> { 0, 1, 2 };
	return a == xte::array<int> { 0, 1, 2 };
})());
static_assert(([] {
	xte::array<int> a;
	a = xte::lvalue(xte::array<int> { 0, 1, 2 });
	return a == xte::array<int> { 0, 1, 2 };
})());
static_assert(([] {
	xte::array<int> a;
	a = typename[:^^int[]:] { 0, 1, 2 };
	return a == xte::array<int> { 0, 1, 2 };
})());

static_assert(xte::is_same<int&&, decltype(xte::array<int>()[0])>);
static_assert(xte::is_same<int&, decltype(xte::lvalue(xte::array<int>())[0])>);
static_assert(xte::is_same<const int&, decltype(xte::as_c(xte::lvalue(xte::array<int>())[0]))>);
static_assert((xte::array<int> { 0, 1, 2 })[0] == 0);
static_assert((xte::array<int> { 0, 1, 2 })[1] == 1);
static_assert((xte::array<int> { 0, 1, 2 })[2] == 2);

static_assert((xte::array<int> { 0, 1, 2 }).data()[0] == 0);
static_assert((xte::array<int> { 0, 1, 2 }).data()[1] == 1);
static_assert((xte::array<int> { 0, 1, 2 }).data()[2] == 2);

static_assert((xte::array<int> {}).size() == 0);
static_assert((xte::array<int> { 0 }).size() == 1);
static_assert((xte::array<int> { 0, 1 }).size() == 2);
static_assert((xte::array<int> { 0, 1, 2 }).size() == 3);

static_assert((xte::array<int> {}).capacity() == 0);
static_assert(([] {
	auto a = xte::array<int>(999);
	return a.capacity() >= a.size();
})());

static_assert(([] {
	int sum = 0;
	for (int n : xte::array<int> { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }) {
		sum += n;
	}
	return sum == 55;
})());

static_assert(xte::is_same<int&&, decltype(xte::array<int>().front())>);
static_assert(xte::is_same<int&, decltype(xte::lvalue(xte::array<int>()).front())>);
static_assert(xte::is_same<const int&, decltype(xte::as_c(xte::lvalue(xte::array<int>()).front()))>);
static_assert((xte::array<int> { 0, 1, 2 }).front() == 0);
static_assert((xte::array<int> { 0, 1, 2 }).front(0) == 0);
static_assert((xte::array<int> { 0, 1, 2 }).front(1) == 1);
static_assert((xte::array<int> { 0, 1, 2 }).front(2) == 2);

static_assert(xte::is_same<int&&, decltype(xte::array<int>().back())>);
static_assert(xte::is_same<int&, decltype(xte::lvalue(xte::array<int>()).back())>);
static_assert(xte::is_same<const int&, decltype(xte::as_c(xte::lvalue(xte::array<int>()).back()))>);
static_assert((xte::array<int> { 0, 1, 2 }).back() == 2);
static_assert((xte::array<int> { 0, 1, 2 }).back(0) == 2);
static_assert((xte::array<int> { 0, 1, 2 }).back(1) == 1);
static_assert((xte::array<int> { 0, 1, 2 }).back(2) == 0);

static_assert(xte::array<int> { 0, 1, 2 } == xte::array<int> { 0, 1, 2 });
static_assert(xte::array<int> { 0, 1, 2 } != xte::array<int> { 0, 1, 999 });
static_assert(xte::array<int> { 0 } < xte::array<int> { 1 });
static_assert(xte::array<int> { 1 } > xte::array<int> { 0 });

static_assert((xte::array<int> { 0, 1, 2, 3, 4 }).slice(1, 3) == xte::array<int> { 1, 2, 3 });
static_assert((xte::array<int> { 0, 1, 2, 3, 4 }).slice(0, -1uz) == xte::array<int> { 0, 1, 2, 3, 4 });

static_assert(([] {
	xte::array<int> a;
	a.resize(1);
	return a[0] == 0;
})());
static_assert(([] {
	xte::array<int> a;
	a.resize(1, 5);
	return a[0] == 5;
})());

static_assert(([] {
	xte::array<int> a;
	a.reserve(10);
	a.reserve(10);
	return a.capacity() >= 20;
})());

static_assert(([] {
	xte::array<int> a;
	a.reserve(10);
	xte::uz capacity = a.capacity();
	a.reserve_total(10);
	return a.capacity() == capacity;
})());

static_assert(([] {
	xte::array<int> a;
	a.reserve(10);
	a.shrink();
	return a.capacity() == 0;
})());

static_assert(([] {
	xte::array<int> a = { 1, 2, 3 };
	a.reset();
	return !a.data() && !a.size() && !a.capacity();
})());

static_assert(([] {
	xte::array<int> a = { 1, 2, 3 };
	a.insert_uninit(1, 3);
	a[1] = 4;
	a[2] = 5;
	a[3] = 6;
	return a == xte::array<int> { 1, 4, 5, 6, 2, 3 };
})());

static_assert(([] {
	xte::array<int> a;
	a.insert(0);
	return a == xte::array<int> { 0 };
})());
static_assert(([] {
	xte::array<int> a;
	a.insert(0, 0);
	return a == xte::array<int> { 0 };
})());
static_assert(([] {
	xte::array<int> a = { 0, 1, 2 };
	a.insert(0, 3);
	return a == xte::array<int> { 3, 0, 1, 2 };
})());
static_assert(([] {
	xte::array<int> a = { 0, 1, 2 };
	a.insert(1, 3);
	return a == xte::array<int> { 0, 3, 1, 2 };
})());
static_assert(([] {
	xte::array<int> a = { 0, 1, 2 };
	a.insert(2, 3);
	return a == xte::array<int> { 0, 1, 3, 2 };
})());
static_assert(([] {
	xte::array<int> a = { 0, 1, 2 };
	a.insert(3, 3);
	return a == xte::array<int> { 0, 1, 2, 3 };
})());

static_assert(([] {
	xte::array<int> a;
	a.insert_range(0, { 0, 1, 2 });
	return a == xte::array<int> { 0, 1, 2 };
})());
static_assert(([] {
	xte::array<int> a = { 0, 1, 2 };
	a.insert_range(0, { 3, 4 });
	return a == xte::array<int> { 3, 4, 0, 1, 2 };
})());
static_assert(([] {
	xte::array<int> a = { 0, 1, 2 };
	a.insert_range(1, { 3, 4 });
	return a == xte::array<int> { 0, 3, 4, 1, 2 };
})());
static_assert(([] {
	xte::array<int> a { 0, 1, 2 };
	a.insert_range(2, { 3, 4 });
	return a == xte::array<int> { 0, 1, 3, 4, 2 };
})());
static_assert(([] {
	xte::array<int> a = { 0, 1, 2 };
	a.insert_range(3, { 3, 4 });
	return a == xte::array<int> { 0, 1, 2, 3, 4 };
})());
static_assert(([] {
	xte::array<int> a = { 0, 1, 2 };
	a.insert_range(2, { 3, 4, 5, 6 });
	return a == xte::array<int> { 0, 1, 3, 4, 5, 6, 2 };
})());

static_assert(([] {
	xte::array<int> a = { 0, 1, 2, 3, 4 };
	a.erase(1, 3);
	return a == xte::array<int> { 0, 4 };
})());
static_assert(([] {
	xte::array<int> a = { 0, 1, 2, 3, 4 };
	a.erase(0, 5);
	return !a.size();
})());
static_assert(([] {
	xte::array<int> a = { 0, 1, 2, 3, 4 };
	a.erase(0, -1uz);
	return a == xte::array<int> {};
})());

static_assert(([] {
	xte::array<int> a = { 0, 1, 2 };
	a.push();
	return a == xte::array<int> { 0, 1, 2, 0 };
})());
static_assert(([] {
	xte::array<int> a = { 0, 1, 2 };
	a.push(3);
	return a == xte::array<int> { 0, 1, 2, 3 };
})());

static_assert(([] {
	xte::array<int> a = { 0, 1, 2 };
	a.push_range({ 3, 4 });
	return a == xte::array<int> { 0, 1, 2, 3, 4 };
})());

static_assert(([] {
	xte::array<int> a { 5 };
	return (a.pop() == 5) && (a.size() == 0);
})());
static_assert(([] {
	xte::array<int> a { 0, 1, 2 };
	return (a.pop() == 2) && (a.size() == 2);
})());

static_assert(([] {
	xte::array<int> a = { 0, 1, 2 };
	a += xte::array<int> { 3, 4 };
	return a == xte::array<int> { 0, 1, 2, 3, 4 };
})());

static_assert((xte::array<int> { 0, 1, 2 } + xte::array<int> { 3, 4 }) == xte::array<int> { 0, 1, 2, 3, 4 });
