#pragma once
void _023(); // wstęp 001
void _003(); // inicjalizacją zmiennych z wykorzystaniem nawiasów: () i {} // 002
void _009(); // r-value, l-value  // 003
void _002(); // if, switch z ograniczonym zasięgiem zmiennej ( + przestrzeń nazw) // 004
void _010(); // array + wstęp do iteratorów // 005
void _014(); // para, niejawnie podany typ // 006
void _013(); // krotki, niejawnie podany typ // 00701, 00702 
void _001(); // rozpakowywanie // 008
void _008(); // wektory, iteratory rozwinięcie  // 00901-00902

void _004(); // kolejka o dwóch końcach deque // 010

void _011(); // list // 11
void _024(); // map/multimap // 12
void _025(); // zbiory, wielozbiory // 13
void _021(); // kontenery nieporządkujące // 14
void _020(); // algorytmy // 15
void _019(); // cechy typowe //16
void _016(); // funktory/lambdy // 17
void _017(); // predykaty // 18
void _018(); // inteligentne ptr // 19

void _022(); // wtłaczanie referencji
void _015(); // numeric_limits
void _006(); // inline - biblioteki z osadzonymi zmiennymi
void _005(); // constexpr-if
void _007(); // folding
void _012(); // czas std::chrono::




void _026();
void _027();
void _028();
void _029();
void _030();

#include <iostream>
#include <string>
using namespace std;

template <typename T1>
void printSTL(const T1& stl, const std::string& separator, bool size) {	
	auto elems = stl.size();			
	for (const auto& elem : stl) {
		std::cout << elem;
		if (--elems > 0) std::cout << separator;
	}	
	if (size) std::cout << "\t[count: " << stl.size() << " elements]" << std::endl;
	std::cout << std::endl;
}
template <typename T1, size_t N>
void printSTL(T1(&stl)[N], const std::string& separator, bool size) {	
	auto elems = N;	
	for (const auto& elem : stl) {
		std::cout << elem;
		if (--elems > 0) std::cout << separator;
	}	
	if (size) std::cout << "\t[count: " << N << " elements]" << std::endl;
	std::cout << std::endl;
}
template <typename T1, typename T2>
void printSTL(const pair<T1, T2>& stl, const std::string& separator) {
	std::cout << stl.first << separator << stl.second << std::endl;
}

template <size_t I = 0, typename ... Telems>
void printSTL(std::tuple<Telems...>& tup, const std::string& separator, bool size=false) {
	if constexpr (I == sizeof...(Telems)) {
		if (size) std::cout << "\t[" << sizeof...(Telems) << "]";
		std::cout << std::endl;
		
		return; // stop rekurencja
	}
	else {
		std::cout << get<I>(tup);
		if (I+1 < sizeof...(Telems)) cout << separator;
		printSTL<I + 1>(tup, separator, size);
	}
}
// ck:96
// c++11: 357
// c++17 rec: 66