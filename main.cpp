#include <iostream>
#include <array>
#include <vector>
#include <map>
#include <set>
#include <iomanip>   //setw..
#include <list>
#include <forward_list>
#include <typeinfo>
#include <string>
#include <ctime>
#include <algorithm>
#include <deque>
#include <functional>
#include <typeinfo>
#include <iterator>
#include <set>
#include <chrono>
#include <thread>
#include <future>
#include "numbers.h"

// unikatowe - moze byc tylko 1 na jeden wskaznik..  (znika wskaznik = zostaje zwolniona pamiec)
// wspoldzielony - usuwany 1 = nic sie nie stanie , usuwany 2 = nic sie nie stanie , usuwany 3 = zostaje zwolnion pamiec jezeli all..
// slaby - jezeli 2 wspoldzielone zgina to 2 slabe zostana puste (nullptr)..

using namespace std;

// template<typename T>
// using uPtr = unique_ptr< T , void (*) (T*) >;

// class A{
//     public:
//      string name;
//      shared_ptr<A> Lider;
//      vector<weak_ptr<A>> Kierownik;
//      A(const string& n, shared_ptr<A> s=nullptr) : name(n), Lider(s) {}
//      ~A(){ cout << name << endl; }
// } // do slabych inteligentnych wskanzikow, przykladowy szablon z klasa oraz podanymi werami..

sharedFunct(){
    // metoda nr.1 z funkcja make_shared..
    shared_ptr<int> ptr1 = make_shared<int>(10);
    shared_ptr<int> ptr2;
    ptr2.reset(new int(20));
    shared_ptr<int> ptr3(new int(30));

    cout << "ptr1: " << ptr1 << " =====> " << *ptr1 << endl;
    cout << "ptr2: " << ptr2 << " =====> " << *ptr2 << endl;
    cout << "ptr3: " << ptr3 << " =====> " << *ptr3 << endl;
    cout << endl;
}

substrFunct(){
shared_ptr<string> kot = make_shared<string>("Mireczek");
shared_ptr<string> pies = make_shared<string>("Maniek");
cout << "Imie kota: " << *kot << endl;
cout << "Imie psa: " << *pies << endl;
cout << kot->substr(0,4) << endl; //wyswietlenie od 0 literki do 4 literki z ,,kot,,..
cout << pies->substr(0,5) << endl; //wyswietlenie od 0 literki do 5 literki z ,,pies,,..

cout << endl;

cout << "ile wskaznikow wskauje na kota? ====> " << kot.use_count() << endl;
cout << "ile wskaznikow wskazuje na psa? ====> " << pies.use_count() << endl;

cout << endl;
}

deleteFunct(){
    shared_ptr<int[]> temp(new int[100],[](int* p){
        cout << p << " " << *p << endl;
        delete[]p;
    });
}

newValueFunct(){
    shared_ptr<double> ex3(new double(13.75),
    [](double* p){
        cout << "usuwana wartosc ======> " << *p << endl;
        cout << "usunieto =====> " << *p << endl;
        delete p;
    });
    cout << endl;
    cout << endl;

    shared_ptr<double> ex4(new double(193.33),
    [](double* n){
        cout << "usuwana wartosc ======> " << *n << endl;
        cout << "usunieto =====> " << *n << endl;
        delete n;
    });
}


int main(){
    //wspoldzielone..
    sharedFunct();
    substrFunct();
    deleteFunct();
    newValueFunct();

    return 0;
}