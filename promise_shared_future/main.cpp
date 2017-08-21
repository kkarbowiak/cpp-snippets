#include <future>
#include <thread>
#include <chrono>
#include <vector>
#include <sstream>
#include <iostream>


void printText(std::string text)
{
    std::ostringstream oss;
    oss << "t" << std::this_thread::get_id() << ": " << text;
    std::cout << oss.str() << std::endl;
}

void threadFun(std::shared_future<void> sfut)
{
    printText("waiting ...");
    sfut.wait();
    printText("... done");
}

int main()
{
    std::promise<void> pro;
    std::shared_future<void> sfut = pro.get_future().share();

    std::vector<std::thread> threads;
    for (std::size_t i = 0; i < 4; ++i)
    {
        threads.push_back(std::thread(&threadFun, sfut));
    }

    printText("threads created, sleeping...");
    std::this_thread::sleep_for(std::chrono::seconds(2));

    printText("setting value");
    pro.set_value();

    for (auto & th : threads)
    {
        th.join();
    }
}
