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

wspFunct(){

    cout << endl;
    cout << endl;

    int* num = new int(11);
    shared_ptr<int> exe1(num);
    shared_ptr<int> exe2(num); // na koniec beda chcialy zwolnic pamiec....i nie wyjdzie

    cout << exe1.use_count() << " =-=-=-=> " << exe2.use_count() << endl; // bedzie 1 i 1 w rezultacie a potem....BLAD..

    cout << endl;
    cout << endl;

    // poprawiona wersja bez bledu.. u gory dla przestrogi..
    int* yexe1= new int(1111);
    shared_ptr<int> prz1(yexe1);
    shared_ptr<int> prz2(prz1);
    cout << prz1.use_count() << " =-=-=-=> " << prz2.use_count() << endl; // bedzie 2 i 2 w rezultacie a potem....BEZ JAKIEGOKOLWIEK BLEDU..
}

// unique_ptr - tworzy wskaznik(wylaczony)i potrafi zwolnic obiekty wskazywane gdy zostanie sam usuniety..

firstUnique(){
    cout << endl;
    cout << endl;

    unique_ptr<int> uptr(new int(12345));
    cout << "uptr przekazywany z 1 funkcji =====> " << *uptr << endl; // tutaj znika i zwalnia pamiec..
}

secondUnique(){
    unique_ptr<int> uptr2 = make_unique<int>(123456789);
    cout << "uptr2 przekazywany z 2 funkcji =====> " << *uptr2 << endl;
    uptr2.release();
    cout << "z 2 funkcji juz zwolniona pamiec z wartosci =====> " << *uptr2 << " JUZ BRAK " << endl;

    cout << endl;
    cout << endl;
}

// thirdUnique(){
//     auto theLambda = [](int* p){
//         cout << *p << " ====> " << p << endl;
//     };
//     unique_ptr<int,decltype(theLambda)> uptr(new int(35), theLambda);
// }                                                                       // z wykorzystaniem szblonu zawartego na samej gorze..
// uPtr<float>f(new float(5),[](float*p){
//   cout << *p << endl; delete p;
//})

weakFunct(){
    shared_ptr<string> boss = make_shared<string>("Man1exter");
    shared_ptr<string> peace = make_shared<string>("Kaselen");

    cout << *boss << " =====> " << boss << endl;
    cout << *peace << " =====> " << peace << endl;

    // z wykorzystaniem klasy..
    // Lider -> Kierownik.push_back(Lider);  // + dopisanie do kaselen po przecinku(Lider/Kierownik)
    // cout << Kierownik.use_count() << endl;
    // for(auto& ele: Lider->Kierownik){
    //    if(!ele.expired()) cout << ele.lock()->name << endl;
    //        else cout << "---------" << endl;
    //}
}

int main(){
    //wspoldzielone..
    sharedFunct();
    substrFunct();
    deleteFunct();
    newValueFunct();

    wspFunct();

    firstUnique();
    secondUnique();
    //thirdUnique();

    weakFunct();

    return 0;
}