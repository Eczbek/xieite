#include <xte/func/rotate.hpp>

static_assert(([] {
	int a = 1;
	int b = 2;
	int c = 3;
	int d = 4;
	xte::rotate(a, b, c, d);
	return (a == 2)
		&& (b == 3)
		&& (c == 4)
		&& (d == 1);
})());

static_assert(([] {
	int a = 1;
	int b = 2;
	int c = 3;
	int d = 4;
	xte::rotate<0>(a, b, c, d);
	return (a == 1)
		&& (b == 2)
		&& (c == 3)
		&& (d == 4);
})());

static_assert(([] {
	int a = 1;
	int b = 2;
	int c = 3;
	int d = 4;
	xte::rotate<4>(a, b, c, d);
	return (a == 1)
		&& (b == 2)
		&& (c == 3)
		&& (d == 4);
})());

static_assert(([] {
	int a = 1;
	int b = 2;
	int c = 3;
	int d = 4;
	int e = 5;
	int f = 6;
	int g = 7;
	int h = 8;
	xte::rotate<2>(a, b, c, d, e, f, g, h);
	return (a == 3)
		&& (b == 4)
		&& (c == 5)
		&& (d == 6)
		&& (e == 7)
		&& (f == 8)
		&& (g == 1)
		&& (h == 2);
})());

static_assert(([] {
	int a = 1;
	int b = 2;
	int c = 3;
	int d = 4;
	int e = 5;
	int f = 6;
	xte::rotate<4>(a, b, c, d, e, f);
	return (a == 5)
		&& (b == 6)
		&& (c == 1)
		&& (d == 2)
		&& (e == 3)
		&& (f == 4);
})());
