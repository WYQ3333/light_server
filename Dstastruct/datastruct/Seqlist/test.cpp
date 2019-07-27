#include "Seqlist.hpp"

int main()
{
    Seqlist<int> seq;
    seq.array_init(10);
    seq.Seq_Print();
    seq.Seq_PushBack(1);
    seq.Seq_PushBack(2);
    seq.Seq_PushBack(3);
    seq.Seq_PushBack(4);
    seq.Seq_Print();
    seq.Seq_PushFront(5);
    seq.Seq_PushFront(6);
    seq.Seq_PushFront(7);
    seq.Seq_PushFront(8);
    seq.Seq_Print();

    seq.Seq_PushFront(9);
    seq.Seq_PushFront(10);
    seq.Seq_PushFront(11);
    seq.Seq_PushFront(12);
    seq.Seq_Print();

    std::cout << seq.Seq_find(9) << std::endl;
    seq.Seq_Insert(5, 20);
    seq.Seq_Print();
    seq.Seq_Erase(20);
    seq.Seq_Print();
    return 0;
}

