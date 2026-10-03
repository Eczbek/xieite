#include <xte/preproc.hpp>
#include <string_view>

static_assert(true XTE_EAT(, false));

static_assert((void XTE_PAREN(), true));

#define TRUE() true
static_assert(XTE_SCAN(TRUE XTE_SCAN() ()));

using namespace std::literals;
static_assert(XTE_QUOTE(abc) == "abc"sv);

XTE_CAT(static, _assert)(true);

static_assert(XTE_ANY(,));
static_assert(!XTE_ANY());

static_assert(XTE_IF(1)(true)(false));
static_assert(XTE_IF(0)(false)(true));

XTE_UNWRAP((static_assert(true);))

static_assert(XTE_WRAPPED((0)));
static_assert(!XTE_WRAPPED(0));

static_assert(XTE_COUNT() == 0);
static_assert(XTE_COUNT(a) == 1);
static_assert(XTE_COUNT(,,) == 3);

#ifdef XTE_REVIVE
#	define SUM(X, ...) XTE_REVIVE(SUM) (X) __VA_OPT__(+ SUM(__VA_ARGS__))
static_assert(SUM(1, 2, 3) == 6);
static_assert(SUM(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) == 55);
#endif

static_assert(XTE_AT(0)(1, 2, 3, 4, 5) == 1);
static_assert(XTE_AT(1)(1, 2, 3, 4, 5) == 2);
static_assert(XTE_AT(2)(1, 2, 3, 4, 5) == 3);
static_assert(XTE_AT(3)(1, 2, 3, 4, 5) == 4);
static_assert(XTE_AT(4)(1, 2, 3, 4, 5) == 5);
