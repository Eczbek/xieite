#include <xte/math/approx_equal.hpp>
#include <xte/math/parse_number.hpp>
#include <xte/preproc/feature.hpp>
#include <xte/util/types.hpp>

static_assert(xte::parse_number<int>("123") == 123);
static_assert(xte::parse_number<int>("+123") == 123);
static_assert(xte::parse_number<int>("-123") == -123);
static_assert(xte::parse_number<int>("FF", 16) == 0xFF);
static_assert(xte::parse_number<int>("1101", 2) == 0b1101);
static_assert(xte::parse_number<int>("765", 8) == 0765);
static_assert(xte::parse_number<int>("111", 1) == 3);
static_assert(xte::parse_number<int>("10101", -1) == 3);
static_assert(xte::parse_number<int>("101010", -1) == -3);
static_assert(xte::parse_number<int>("-10101", -1) == -3);
static_assert(xte::parse_number<int>("12", -10) == -8);
static_assert(xte::parse_number<int>("10", -10) == -10);
static_assert(xte::parse_number<int>("0") == 0);
static_assert(xte::parse_number<int>("") == 0);
static_assert(xte::parse_number<int>("123", 0) == 0);
static_assert(xte::parse_number<int>("+") == 0);
static_assert(xte::parse_number<int>("-") == 0);
static_assert(xte::parse_number<int>("123.456") == 123);
static_assert(xte::parse_number<int>("123abc") == 123);
#if XTE_FEATURE_INT_8
static_assert(xte::parse_number<xte::u8>("256") == 0);
static_assert(xte::parse_number<xte::u8>("256", 10, {}, false) == 25);
#endif
static_assert(xte::parse_number<unsigned>("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF", 16) == -1u);

static_assert(xte::approx_equal(xte::parse_number<double>("123.456"), 123.456));
static_assert(xte::approx_equal(xte::parse_number<double>(".5"), 0.5));
static_assert(xte::approx_equal(xte::parse_number<double>("1."), 1.0));
static_assert(xte::approx_equal(xte::parse_number<double>("123.456e78"), 123.456e78));
static_assert(xte::approx_equal(xte::parse_number<double>("123.456e+78"), 123.456e78));
static_assert(xte::approx_equal(xte::parse_number<double>("123.456e-78"), 123.456e-78));
static_assert(xte::approx_equal(xte::parse_number<double>("FF.FF", 16), 255.0 + 255.0 / 256.0));
static_assert(xte::approx_equal(xte::parse_number<double>("10", 2.5), 2.5));
static_assert(xte::approx_equal(xte::parse_number<double>("11", 2.5), 3.5));
static_assert(xte::approx_equal(xte::parse_number<double>("123.456.789"), 123.456));
static_assert(xte::approx_equal(xte::parse_number<double>("1e2e3"), 1e2));
static_assert(xte::approx_equal(xte::parse_number<double>("1e"), 1));
static_assert(xte::approx_equal(xte::parse_number<double>("1e+"), 1));
static_assert(xte::approx_equal(xte::parse_number<double>("1e-"), 1));

static_assert(xte::parse_number<int>.with_index("123").index == 3);
static_assert(xte::parse_number<int>.with_index("-").index == 0);
static_assert(xte::parse_number<double>.with_index("+123.456e-78").index == 12);
