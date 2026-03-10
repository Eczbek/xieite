#include <xte/data/string.hpp>
#include <xte/util/lvalue.hpp>
#include <ranges>

static_assert(xte::string().size() == 0);
static_assert(xte::string().capacity() == 0);
static_assert(xte::string("abc").size() == 3);
static_assert(xte::string("abc").capacity() >= 3);
static_assert(xte::string("abc")[0] == 'a');
static_assert(xte::string("abc")[1] == 'b');
static_assert(xte::string("abc")[2] == 'c');
static_assert(xte::string("abc")[3] == '\0');
static_assert(xte::string("abc") == "abc");
static_assert(([] {
	xte::string s = "abc";
	return s == xte::string(s);
})());
static_assert(auto(xte::lvalue(xte::string("abc"))) == "abc");
static_assert(auto(xte::string("abc")) == "abc");

static_assert(std::ranges::input_range<xte::string>);

static_assert(([] {
	xte::string s = "abc";
	s = "xyz";
	return s == "xyz";
})());
static_assert(([] {
	xte::string s = "abc";
	s += "xyz";
	return s == "abcxyz";
})());
static_assert(([] {
	xte::string s = 'a';
	s += 'b';
	return s == "ab";
})());
