#include <xte/array.hpp>
#include <xte/init_list.hpp>
#include <xte/ptr.hpp>
#include <xte/qual_traits.hpp>

template<typename type>
struct test_array {
	xte::array<type> data;

	constexpr test_array(xte::init_list<type> list) {
		for (auto&& item : list) {
			this->data.append(xte::as_xvalue(item));
		}
	}
};

consteval {
	test_array<xte::ptr<int>> a = {
		xte::ptr<int>::make(5),
		nullptr
	};
}
