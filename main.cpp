#include <iostream>

template<int32_t v>
struct Int {
    static constexpr int32_t value = v;
};

struct Nil {
    typedef Nil Head;
    typedef Nil Tail;
};

template<class H, class T = Nil>
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
struct Length<Nil> {
    static constexpr uint32_t length = 0;
};

template<class List>
using Head = typename List::Head;

template<class List>
using Tail = typename List::Tail;

template<class List, uint32_t N>
struct Nth {
	typedef Tail<List> CurTail;
	typedef class Nth<CurTail, N-1>::value value;
};

template<class List>
struct Nth<List, 0> {
	typedef Head<List> value;
};

template<class X, class Y>
struct Equal {
	static constexpr bool result = false;
};

template<class X>
struct Equal<X, X> {
	static constexpr bool result = true;
};

template<class Elem, class List>
struct IsInList {
	static constexpr bool result = Equal<Elem, Head<List>>::result ||
			IsInList<Elem, Tail<List>>::result;
};

template<class Elem>
struct IsInList<Elem, Nil> {
	static constexpr bool result = false;
};

int main() {
    typedef List<Int<1>, List<Int<2>, List<Int<3>, List<Int<4>, List<Int<5>>>>>> list;
    typedef Length<list> list_length;
    std::cout << "List length: " << list_length::length << std::endl;
    std::cout << "List head: " << Head<list>::value << std::endl;
    std::cout << "List second element: " << Head<Tail<list>>::value << std::endl;
    std::cout << "List third element: " << Nth<list, 2>::value::value << std::endl;
    std::cout << "List third element: " << IsInList<Int<3>, list>::result << std::endl;
    return 0;
}