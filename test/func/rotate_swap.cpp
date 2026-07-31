#include <xte/func/rotate_swap.hpp>

static_assert(([] {
	int a = 1;
	int b = 2;
	int c = 3;
	int d = 4;
	xte::rotate_swap(a, b, c, d);
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
	xte::rotate_swap<0>(a, b, c, d);
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
	xte::rotate_swap<4>(a, b, c, d);
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
	xte::rotate_swap<2>(a, b, c, d, e, f, g, h);
	return (a == 3)
		&& (b == 4)
		&& (c == 5)
		&& (d == 6)
		&& (e == 7)
		&& (f == 8)
		&& (g == 1)
		&& (h == 2);
})());
