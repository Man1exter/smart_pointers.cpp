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

sharedfunct(){
    // metoda nr.1 z funkcja make_shared..
    shared_ptr<int> ptr1 = make_shared<int>(10);
    shared_ptr<int> ptr2;
    ptr2.reset(new int(20));
    shared_ptr<int> ptr3(new int(30));

    cout << "ptr1: " << ptr1 << " =====> " << *ptr1 << endl;
    cout << "ptr2: " << ptr2 << " =====> " << *ptr2 << endl;
    cout << "ptr3: " << ptr3 << " =====> " << *ptr3 << endl;
}


int main(){
    sharedfunct();

    return 0;
}