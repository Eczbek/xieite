#include <xte/data/array.hpp>
#include <xte/data/ptr.hpp>
#include <xte/util/init_list.hpp>
#include <xte/util/xvalue.hpp>

template<typename T>
struct test_array {
	xte::array<T> data;

	constexpr test_array(xte::init_list<T> list) {
		for (auto&& item : list) {
			this->data.push(xte::xvalue(item));
		}
	}
};

consteval {
	test_array<xte::ptr<int>> a = {
		xte::ptr<int>::make(5),
		nullptr
	};
}
