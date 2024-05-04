// Your First C++ Program
#include <thread>
#include <iostream>
#include <vector>
#include <atomic>


using namespace std;

std::atomic<int> counter(0);


void sumVector(std::vector<int>* v){
    for (std::vector<int>::iterator it = v->begin();
    it != v->end(); ++it)
    {
        counter.fetch_add(*it);
    }
}


int main() {
    vector<int> vector1 = { 10, 20, 40, 60, 80 };
    vector<int> vector2 = { 1, 3, 5, 7, 9 };
    vector<int> vector3 = { 10, 30, 50, 70, 90 };
    thread t0(sumVector, &vector1);
    thread t1(sumVector, &vector2);
    thread t2(sumVector, &vector3);
    
    t0.join();
    t1.join();
    t2.join();
    cout<<"this is the counter:"<<counter<<endl;
    return 0;

}
