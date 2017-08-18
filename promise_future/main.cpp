#include <future>
#include <thread>
#include <exception>
#include <functional>
#include <string>
#include <chrono>
#include <iostream>


class CustomException : public std::exception
{
    public:
        explicit CustomException(std::string const & text) : mText(text) {}
        char const * what() const noexcept override { return mText.c_str(); }
        std::string const & getText() const { return mText; }

    private:
        std::string mText;
};

template<typename T>
void delayed(std::promise<T> & promise, T const & value)
{
    std::this_thread::sleep_for(std::chrono::seconds(1));

    promise.set_value(value);
}

template<typename T>
void throwing_stdexc(std::promise<T> & /* promise */, T const & /* value */)
{
    throw std::exception();
}

template<typename T>
void throwing_custom(std::promise<T> & /* promise */, T const & /* value */)
{
    throw CustomException("custom error");
}

template<typename T>
void thread_function(void fun(std::promise<T> &, T const &), std::promise<T> & promise, T const & value)
{
    try
    {
        fun(promise, value);
    }
    catch (std::exception const &)
    {
        promise.set_exception(std::current_exception());
    }
}

template<typename T>
void test(void fun(std::promise<T> &, T const &), T const & value)
{
    std::promise<T> pr;
    std::future<T> ft = pr.get_future();

    std::thread th(thread_function<T>, fun, std::ref(pr), std::cref(value));

    try
    {
        std::cout << "futval: " << ft.get() << std::endl;
    }
    catch (CustomException const & ce)
    {
        std::cout << "cusexc: " << ce.what() << std::endl;
    }
    catch (std::exception const & e)
    {
        std::cout << "stdexc: " << e.what() << std::endl;
    }

    th.join();
}

template<typename T>
void test(T const & value)
{
    std::cout << "testing delayed" << std::endl;
    test<T>(delayed<T>, value);
    std::cout << "testing throwing_stdexc" << std::endl;
    test<T>(throwing_stdexc<T>, value);
    std::cout << "testing throwing_custom" << std::endl;
    test<T>(throwing_custom<T>, value);
    std::cout << std::endl;
}

int main()
{
    test(10);
    test(2.113);
    test(std::string("text"));
}
