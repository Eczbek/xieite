#include <xte/preproc/lambda.hpp>

static_assert(XTE_LAMBDA($0 + $1)(1, 2) == 3);

constexpr struct : decltype(XTE_LAMBDA_THIS($this.x + $0)) { int x = 5; } f;
static_assert(f(2) == 7);

static_assert(([] {
	int x = 5;
	return XTE_LAMBDA_LOCAL(x + $0)(2) == 7;
})());

static_assert(([] {
	int x = 5;
	return (XTE_LAMBDA_LOCAL(x += $0)(2) == 7) && (x == 7);
})());
