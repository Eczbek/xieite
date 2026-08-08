#include <xte/data/array.hpp>
#include <xte/trait/is_copy_constructible.hpp>
#include <xte/trait/is_move_constructible_noex.hpp>
#include <xte/trait/is_same.hpp>
#include <xte/util/as_const.hpp>
#include <xte/util/construct.hpp>
#include <xte/util/as_lvalue.hpp>
#include <xte/util/number_types.hpp>
#include <meta>
#include <ranges>
#include <vector>

struct non_destructible {
	~non_destructible() = delete;
};

struct throwing_destructor {
	~throwing_destructor() noexcept(false) {}
};

static_assert(!std::meta::can_substitute(^^xte::array, { ^^non_destructible }));
static_assert(!std::meta::can_substitute(^^xte::array, { ^^throwing_destructor }));

static_assert(([] {
	xte::array<int> a;
	a = xte::array<int> { 0, 1, 2 };
	return a == xte::array<int> { 0, 1, 2 };
})());
static_assert(([] {
	xte::array<int> a;
	a = xte::as_lvalue(xte::array<int> { 0, 1, 2 });
	return a == xte::array<int> { 0, 1, 2 };
})());
static_assert(([] {
	xte::array<int> a;
	a = typename[:^^int[]:] { 0, 1, 2 };
	return a == xte::array<int> { 0, 1, 2 };
})());

static_assert(xte::is_same<int&&, decltype(xte::array<int>()[0])>);
static_assert(xte::is_same<int&, decltype(xte::as_lvalue(xte::array<int>())[0])>);
static_assert(xte::is_same<const int&, decltype(xte::as_const(xte::as_lvalue(xte::array<int>())[0]))>);
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
static_assert(xte::is_same<int&, decltype(xte::as_lvalue(xte::array<int>()).front())>);
static_assert(xte::is_same<const int&, decltype(xte::as_const(xte::as_lvalue(xte::array<int>()).front()))>);
static_assert((xte::array<int> { 0, 1, 2 }).front() == 0);
static_assert((xte::array<int> { 0, 1, 2 }).front(0) == 0);
static_assert((xte::array<int> { 0, 1, 2 }).front(1) == 1);
static_assert((xte::array<int> { 0, 1, 2 }).front(2) == 2);

static_assert(xte::is_same<int&&, decltype(xte::array<int>().back())>);
static_assert(xte::is_same<int&, decltype(xte::as_lvalue(xte::array<int>()).back())>);
static_assert(xte::is_same<const int&, decltype(xte::as_const(xte::as_lvalue(xte::array<int>()).back()))>);
static_assert((xte::array<int> { 0, 1, 2 }).back() == 2);
static_assert((xte::array<int> { 0, 1, 2 }).back(0) == 2);
static_assert((xte::array<int> { 0, 1, 2 }).back(1) == 1);
static_assert((xte::array<int> { 0, 1, 2 }).back(2) == 0);

static_assert(xte::array<int> { 0, 1, 2 } == xte::array<int> { 0, 1, 2 });
static_assert(xte::array<int> { 0, 1, 2 } != xte::array<int> { 0, 1, 999 });
static_assert(xte::array<int> { 0 } < xte::array<int> { 1 });
static_assert(xte::array<int> { 1 } > xte::array<int> { 0 });

static_assert((xte::array<int> { 0, 1, 2, 3, 4 }).subrange(1, 3) == xte::array<int> { 1, 2, 3 });
static_assert((xte::array<int> { 0, 1, 2, 3, 4 }).subrange(0, -1uz) == xte::array<int> { 0, 1, 2, 3, 4 });

static_assert(([] {
	xte::array<int> a = { 1, 2, 3 };
	a.reset();
	return !a.data() && !a.size() && !a.capacity();
})());

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
	a.reserve_and_init(5, [](int* buffer, xte::uz size) {
		for (xte::uz i = 0; i < 5; ++i) {
			xte::construct(buffer[i], static_cast<int>(i));
		}
		return size;
	});
	return a == xte::array<int> { 0, 1, 2, 3, 4 };
})());

static_assert(([] {
	xte::array<int> a;
	a.reserve(10);
	a.shrink_to_fit();
	return a.capacity() == 0;
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
	xte::array<int> a = { 0, 1, 2 };
	a.insert_fill(1, 3, 999);
	return a == xte::array<int> { 0, 999, 999, 999, 1, 2 };
})());
static_assert(([] {
	xte::array<int> a = { 0, 1, 2 };
	a.insert_fill(1, 0, 999);
	return a == xte::array<int> { 0, 1, 2 };
})());

static_assert(([] {
	xte::array<int> a = { 1, 2, 3 };
	a.reserve_and_init(3, [](int* buffer, xte::uz size) {
		xte::construct(buffer[0], 4);
		xte::construct(buffer[1], 5);
		xte::construct(buffer[2], 6);
		return size;
	});
	return a == xte::array<int> { 1, 2, 3, 4, 5, 6 };
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
	a.append();
	return a == xte::array<int> { 0, 1, 2, 0 };
})());
static_assert(([] {
	xte::array<int> a = { 0, 1, 2 };
	a.append(3);
	return a == xte::array<int> { 0, 1, 2, 3 };
})());

static_assert(([] {
	xte::array<int> a = { 0, 1, 2 };
	a.append_range({ 3, 4 });
	return a == xte::array<int> { 0, 1, 2, 3, 4 };
})());

static_assert(([] {
	xte::array<int> a { 5 };
	return (a.pop_back() == 5) && (a.size() == 0);
})());
static_assert(([] {
	xte::array<int> a { 0, 1, 2 };
	return (a.pop_back() == 2) && (a.size() == 2);
})());

static_assert(([] {
	xte::array<int> a = { 0, 1, 2 };
	a += xte::array<int> { 3, 4 };
	return a == xte::array<int> { 0, 1, 2, 3, 4 };
})());

static_assert((xte::array<int> { 0, 1, 2 } + xte::array<int> { 3, 4 }) == xte::array<int> { 0, 1, 2, 3, 4 });
static_assert((xte::array<int> { 0, 1, 2 } + std::vector<int> { 3, 4}) == xte::array<int> { 0, 1, 2, 3, 4 });
static_assert((std::vector<int> { 0, 1, 2 } + xte::array<int> { 3, 4 }) == xte::array<int> { 0, 1, 2, 3, 4 });
