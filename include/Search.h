#include <stdio.h>
#include <vector>
#include <memory>

class BFS : public std::enable_shared_from_this<BFS>
{
public:
    void bfsFun();

public:
    struct Node
    {
        int x;
        int y;
        int step;
        int fatherIndex;

        Node(int _x, int _y, int _step, int _fatherIndex)
            : x(_x)
            , y(_y)
            , step(_step)
            , fatherIndex(_fatherIndex)
        {
        }
    };
};


// Search
class DFS : public std::enable_shared_from_this<DFS>
{
public:
    DFS(std::vector<int> input);

    void dfsSearch(int step);

private:
    std::vector<int> mInput;
    std::vector<bool> book;
    std::vector<int> box;
};