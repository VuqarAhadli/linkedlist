#include <print>
#include <any>


class DataNode
{
public:
    std::any data;
    DataNode* prev;
    DataNode* next;
    DataNode  (std::any dat, DataNode* pre, DataNode* nex) : data(dat), prev(pre), next(nex)
    {
    }
    void intPrint()
    {
        std::println("data: {}", std::any_cast<int>(data));
    }
};

int main()
{
    DataNode sixth{87, nullptr, nullptr};
    DataNode fifth{3, nullptr, nullptr};
    DataNode fourth{11, nullptr, nullptr};
    DataNode third{77, nullptr, nullptr};
    DataNode second{3421, nullptr, nullptr};
    DataNode init{124, nullptr, nullptr};
    
    init.next = &second;
    second.next = &third;
    third.next = &fourth;
    fourth.next = &fifth;
    fifth.next = &sixth;
    
    second.prev = &init;
    third.prev = &second;
    fourth.prev = &third;
    fifth.prev = &fourth;
    sixth.prev = &fifth;
    
    DataNode* k = &init;
    
    while(k)
    {
        k->intPrint();
        k = k->next;
    }
    k = &sixth;
    while (k)
    {
        k->intPrint();
        k = k->prev;
    }


    return 0;
}
