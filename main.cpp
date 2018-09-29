//#include <boost/thread.hpp>
//#include <boost/chrono.hpp>
#include <iostream>
#include "src/MPointer.cpp"
//#include "src/MPointerGC.cpp"


//void thread() {
//    try {
//        while (true) {
//            MPointerGC *s = MPointerGC::getInstance();;
//            s->update();
//            boost::this_thread::sleep_for(boost::chrono::seconds{5});
//        }
//    }
//    catch (boost::thread_interrupted const &) {}
//}


int main() {
    // init thread
//    boost::thread t{thread};
    // ............................................

    MPointer<int> mPointer1 = MPointer<int>::New();
    MPointer<int> mPointer2 = MPointer<int>::New();

    mPointer1 = 5;
    int valor = &mPointer1;
    std::cout << "\n" << "valor: " << valor << "\n";

    mPointer2 = mPointer1;

    int valor2 = &mPointer2;
    std::cout << "\n" << "valor: " << valor2 << "\n";

    // ............................................
    // finish test
//    t.interrupt();
//    t.join();
    return 0;
}