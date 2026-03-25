#include <xte/data/string.hpp>
#include <xte/trait/is_copy_constructible.hpp>
#include <xte/trait/is_noex_move_constructible.hpp>
#include <xte/trait/is_same.hpp>
#include <xte/util/as_c.hpp>
#include <xte/util/lvalue.hpp>
#include <xte/util/types.hpp>
#include <iterator>
#include <ranges>

static_assert(xte::is_same<xte::string::value_type, char>);
static_assert(xte::is_same<xte::string::reference, char&>);
static_assert(xte::is_same<xte::string::const_reference, const char&>);
static_assert(xte::is_same<xte::string::pointer, char*>);
static_assert(xte::is_same<xte::string::const_pointer, const char*>);
static_assert(xte::is_same<xte::string::iterator, char*>);
static_assert(xte::is_same<xte::string::const_iterator, const char*>);
static_assert(xte::is_same<xte::string::reverse_iterator, std::reverse_iterator<char*>>);
static_assert(xte::is_same<xte::string::const_reverse_iterator, std::reverse_iterator<const char*>>);

static_assert(requires { { xte::string() } noexcept; });
static_assert(xte::is_copy_constructible<xte::string>);
static_assert(xte::is_noex_move_constructible<xte::string>);
static_assert(requires { xte::string { 'a', 'b', 'c' }; });
static_assert(requires { xte::string(std::from_range, typename[:^^char[]:] { 'a', 'b', 'c' }); });
static_assert(requires { xte::string(3, 'a'); });
static_assert(requires { xte::string("abc"); });
static_assert(requires { xte::string("abc", 3); });
static_assert(([] {
	xte::string a;
	a = xte::string("abc");
	return a == "abc";
})());
static_assert(([] {
	xte::string a;
	a = xte::lvalue(xte::string("abc"));
	return a == "abc";
})());
static_assert(([] {
	xte::string a;
	a = "abc";
	return a == "abc";
})());
static_assert(([] {
	xte::string a;
	a = xte::array<char> { 'a', 'b', 'c' };
	return a == "abc";
})());


static_assert(xte::is_same<char&&, decltype(xte::string()[0])>);
static_assert(xte::is_same<char&, decltype(xte::lvalue(xte::string())[0])>);
static_assert(xte::is_same<const char&, decltype(xte::as_c(xte::lvalue(xte::string())[0]))>);
static_assert(xte::string("abc")[0] == 'a');
static_assert(xte::string("abc")[1] == 'b');
static_assert(xte::string("abc")[2] == 'c');
static_assert(xte::string("abc")[3] == '\0');

static_assert(xte::string("abc").data()[0] == 'a');
static_assert(xte::string("abc").data()[1] == 'b');
static_assert(xte::string("abc").data()[2] == 'c');
static_assert(xte::string("abc").data()[3] == '\0');

static_assert(xte::string().size() == 0);
static_assert(xte::string("a").size() == 1);
static_assert(xte::string("ab").size() == 2);
static_assert(xte::string("abc").size() == 3);

static_assert(xte::string().capacity() == 0);
static_assert(([] {
	auto a = xte::string(999);
	return a.capacity() >= a.size();
})());

static_assert(([] {
	xte::uz sum = 0;
	for (char c : xte::string("abcdef")) {
		sum += static_cast<xte::uz>(c);
	}
	return sum > 0;
})());

static_assert(xte::is_same<char&&, decltype(xte::string().front())>);
static_assert(xte::is_same<char&, decltype(xte::lvalue(xte::string()).front())>);
static_assert(xte::is_same<const char&, decltype(xte::as_c(xte::lvalue(xte::string()).front()))>);
static_assert(xte::string("abc").front() == 'a');
static_assert(xte::string("abc").front(0) == 'a');
static_assert(xte::string("abc").front(1) == 'b');
static_assert(xte::string("abc").front(2) == 'c');
static_assert(xte::string("abc").front(3) == '\0');

static_assert(xte::is_same<char&&, decltype(xte::string().back())>);
static_assert(xte::is_same<char&, decltype(xte::lvalue(xte::string()).back())>);
static_assert(xte::is_same<const char&, decltype(xte::as_c(xte::lvalue(xte::string()).back()))>);
static_assert(xte::string("abc").back() == 'c');
static_assert(xte::string("abc").back(0) == 'c');
static_assert(xte::string("abc").back(1) == 'b');
static_assert(xte::string("abc").back(2) == 'a');
static_assert(xte::string("abc").back(-1uz) == '\0');

static_assert(xte::string("abc") == "abc");
static_assert(xte::string("abc") != "xyz");
static_assert(xte::string("abc") < "xyz");
static_assert(xte::string("xyz") > "abc");

static_assert(([] {
	xte::string a;
	a.resize(1, 'a');
	return a[0] == 'a';
})());

static_assert(([] {
	xte::string a;
	a.reserve(10);
	a.reserve(10);
	return a.capacity() >= 20;
})());

static_assert(([] {
	xte::string a;
	a.reserve(10);
	xte::uz capacity = a.capacity();
	a.reserve_total(10);
	return a.capacity() == capacity;
})());

static_assert(([] {
	xte::string a;
	a.reserve(10);
	a.shrink();
	return a.capacity() == 0;
})());

static_assert(([] {
	xte::string a;
	a.insert(0, 'a');
	return a == "a";
})());
static_assert(([] {
	xte::string a = "abc";
	a.insert(0, 'x');
	return a == "xabc";
})());
static_assert(([] {
	xte::string a = "abc";
	a.insert(1, 'x');
	return a == "axbc";
})());
static_assert(([] {
	xte::string a = "abc";
	a.insert(2, 'x');
	return a == "abxc";
})());
static_assert(([] {
	xte::string a = "abc";
	a.insert(3, 'x');
	return a == "abcx";
})());

static_assert(([] {
	xte::string a = "abc";
	a.insert_string(0, "xyz");
	return a == "xyzabc";
})());
static_assert(([] {
	xte::string a = "abc";
	a.insert_string(1, "xyz");
	return a == "axyzbc";
})());
static_assert(([] {
	xte::string a = "abc";
	a.insert_string(2, "xyz");
	return a == "abxyzc";
})());
static_assert(([] {
	xte::string a = "abc";
	a.insert_string(3, "xyz");
	return a == "abcxyz";
})());

static_assert(([] {
	xte::string a = "abcdef";
	a.erase(1, 3);
	return a == "aef";
})());
static_assert(([] {
	xte::string a = "abcdef";
	a.erase(0, -1uz);
	return a == "";
})());

static_assert(([] {
	xte::string a = "abc";
	a.push('x');
	return a == "abcx";
})());

static_assert(([] {
	xte::string a = "abc";
	a.push_string("xyz");
	return a == "abcxyz";
})());

static_assert(([] {
	xte::string a = "a";
	return (a.pop() == 'a') && (a.size() == 0);
})());
static_assert(([] {
	xte::string a = "abc";
	return (a.pop() == 'c') && (a.size() == 2);
})());

static_assert(([] {
	xte::string a = "abc";
	a += 'x';
	return a == "abcx";
})());
static_assert(([] {
	xte::string a = "abc";
	a += "xyz";
	return a == "abcxyz";
})());

static_assert((xte::string("abc") + 'x') == "abcx");
static_assert((xte::string("abc") + "xyz") == "abcxyz");
static_assert((xte::string("abc") + xte::string("xyz")) == "abcxyz");
