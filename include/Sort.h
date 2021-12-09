#include <stdio.h>
#include <vector>
#include <memory>

class SortBase
{
public:
    virtual std::vector<int> sortFun(std::vector<int> input) = 0;

    void swapFun(int &a, int &b)
    {
        auto tmp = a;
        a = b;
        b = a;
    }
};

class Buddle : public SortBase, public std::enable_shared_from_this<Buddle>
{
public:
    std::vector<int> sortFun(std::vector<int> input) override;
};

class Quick : public SortBase, public std::enable_shared_from_this<Quick>
{
public:
    std::vector<int> sortFun(std::vector<int> input) override;

private:
    void quickSort(int left, int right, std::vector<int> &mInput);
};

class Chain : public SortBase, public std::enable_shared_from_this<Chain>
{
public:
    std::vector<int> sortFun(std::vector<int> input) override;

private:
    struct Node
    {
        int data;
        std::shared_ptr<Node> next{nullptr};
        std::shared_ptr<Node> before{nullptr};
    };
    using nodePtr = std::shared_ptr<Node>;
};