/* The following code example is taken from the book
* "The C++ Standard Library - A Tutorial and Reference, 2nd Edition"
* by Nicolai M. Josuttis, Addison-Wesley, 2012
*
* (C) Copyright Nicolai M. Josuttis 2012.
* Permission to copy, use, modify, sell and distribute this software
* is granted provided this copyright notice appears in all copies.
* This software is provided "as is" without express or implied
* warranty, and with no claim as to its suitability for any purpose.
*/
#include <tuple>
#include <iostream>
#include <complex>
#include <string>

using namespace std;

// helper: print elements with index IDX and higher of tuple t having MAX elements
template <int IDX, int MAX, typename... Args>
struct PRINT_TUPLE
{
	static void print(std::ostream& strm, const std::tuple<Args...>& t)
	{
		strm << std::get<IDX>(t) << (IDX + 1 == MAX ? "" : ",");
		PRINT_TUPLE<IDX + 1, MAX, Args...>::print(strm, t);
	}
};

// partial specialization to end the recursion
template <int MAX, typename... Args>
struct PRINT_TUPLE<MAX, MAX, Args...>
{
	static void print(std::ostream& strm, const std::tuple<Args...>& t)
	{
	}
};

// output operator for tuples
template <typename... Args>
std::ostream& operator << (std::ostream& strm, const std::tuple<Args...>& t)
{
	strm << "[";
	PRINT_TUPLE<0, sizeof...(Args), Args...>::print(strm, t);
	return strm << "]";
}

int main()
{
	// create a four-element tuple
	// - elements are initialized with default value (0 for fundamental types)
// 	tuple<string, int, int, complex<double>> t;
// 
// 	// create and initialize a tuple explicitly
// 	tuple<int, float, string> t1(41, 6.3, "nico");
// 
// 	// "iterate" over elements:
// 	cout << get<0>(t1) << " ";
// 	cout << get<1>(t1) << " ";
// 	cout << get<2>(t1) << " ";
// 	cout << endl;
// 
// 	// create tuple with make_tuple()
// 	// - auto declares t2 with type of right-hand side
// 	// - thus, type of t2 is tuple
// 	auto t2 = make_tuple(22, 44, "nico");
// 
// 	// assign second value in t2 to t1
// 	get<1>(t1) = get<1>(t2);
// 
// 	// comparison and assignment
// 	// - including type conversion from tuple<int,int,const char*>
// 	//   to tuple<int,float,string>
// 	if (t1 < t2) {  // compares value for value
// 		t1 = t2;    // OK, assigns value for value
// 	}

	tuple <int, float, string> t(77, 1.1, "more light");
	cout << "io: " << t << endl;
}
