#include <iostream>

template<int32_t v>
struct Int {
    static constexpr int32_t value = v;
};

struct NIL {
    typedef NIL Head;
    typedef NIL Tail;
};

template<class H, class T = NIL>
struct List {
    typedef H Head;
    typedef T Tail;
};

template<class LIST>
struct Length {
    typedef class LIST::Tail Tail;
    static constexpr uint32_t length = 1 + Length<Tail>::length;
};

template<>
struct Length<NIL> {
    static constexpr uint32_t length = 0;
};

template<class List>
using Head = typename List::Head;

template<class List>
using Tail = typename List::Tail;

template<class List, uint32_t N>
struct Nth {
	typedef Tail<List> tail;
	typedef class Nth<tail, N-1>::value value;
};

template<class List>
struct Nth<List, 0> {
	typedef Head<List> value;
};

int main() {
    typedef List<Int<1>, List<Int<2>, List<Int<3>, List<Int<4>, List<Int<5>>>>>> list;
    typedef Length<list> list_length;
    std::cout << "List length: " << list_length::length << std::endl;
    std::cout << "List head: " << Head<list>::value << std::endl;
    std::cout << "List second element: " << Head<Tail<list>>::value << std::endl;
    std::cout << "List third element: " << Nth<list, 2>::value::value << std::endl;
    return 0;
}