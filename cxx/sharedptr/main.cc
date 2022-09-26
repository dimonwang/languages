#include <iostream>
#include <memory>


class T
{
    public:
        T(){
            std::cout << "in T" << std::endl;
        }
        ~T(){
            std::cout << "in ~T" << std::endl;
        }
};

static void test2(std::shared_ptr<T>&& pt) {
    std::cout << "in test2:" << pt.use_count() << std::endl;
}

void test(std::shared_ptr<T>&& pt) {
    std::cout << "in test:" << pt.use_count() << std::endl;
    test2(std::move(pt));
}

int main()
{
    std::shared_ptr<T> t = std::make_shared<T>();
    std::cout << "in main:" << t.use_count() << std::endl;
    test(std::move(t));
    return 0;
}
