#include "../include/Search.h"
#include <iostream>

void BFS::bfsFun()
{
    int maze[5][5] =
    {
        0,1,0,0,0,
        0,1,0,1,0,
        0,0,0,0,0,
        0,1,1,1,0,
        0,0,0,1,0,
    };
    int startX = 0;
    int startY = 0;
    int next[4][2] =
        {
            -1, 0, // up
            1, 0,  // down
            0, -1, // left
            0, 1   // right
        };

    std::vector<Node> que;
    int indexHead = 0;
    int indexTail = 0;
    int step = 0;
    que.push_back(Node(0, 0, 0, -1));
    int min = 9999;
    bool book[5][5] = { false };
    book[0][0] = true;
    // std::cout << "(" << 0 << "," << 0 << ") -->";
    while (indexHead < que.size())
    {
        for (int i = 0; i < 4; ++i)
        {
            auto nextX = que[indexHead].x + next[i][0];
            auto nextY = que[indexHead].y + next[i][1];
            auto step = que[indexHead].step;
            
            if (step > min)
            {
                std::cout << std::endl;
                std::cout << "over step";

                for (auto index = indexHead; index != -1; index = que[index].fatherIndex)
                {
                    std::cout << "(" << que[index].x << "," << que[index].y << ") <--- ";
                }
                indexHead++;
                break;
            }

            if (nextX < 0 || nextX >= 5 || nextY < 0 || nextY >= 5 || (book[nextX][nextY] == true))
            {
                continue;
            }

            if (nextX == 4 && nextY == 4)
            {
                std::cout << "step : " << step << std::endl;
               // for (auto index = indexHead; index != -1; index = que[index].fatherIndex)
               // {
                //  std::cout << "(" << que[index].x <<"," << que[index].y<< ") <--- ";
                //}

                if (step < min)
                {
                    min = step;
                    indexHead++;
                    std::cout << std::endl;
                    break;
                }
            }

            if (maze[nextX][nextY] == 0)
            {
                //std::cout << "--->(" << nextX << "," << nextY << ")";
                book[nextX][nextY] = true;
                que.push_back(Node(nextX, nextY, step + 1, indexHead));
            }
            else
            {
                continue;
            }
        }

        for (auto index = indexHead; index != -1; index = que[index].fatherIndex)
        {
            std::cout << "(" << que[index].x << "," << que[index].y << ") <--- ";
        }
        std::cout << std::endl;
        indexHead++;
    }

    std::cout << min << std::endl;
}

DFS::DFS(std::vector<int> input)
{
    mInput = input;
    book.resize(mInput.size(), false);
    box.resize(mInput.size());
}

void DFS::dfsSearch(int step)
{
    if (step == mInput.size() - 1)
    {
        for (const auto &num : box)
        {
            std::cout << num;
        }
        std::cout << std::endl;
        return;
    }

    for (auto i = 0; i < mInput.size(); ++i)
    {
        if (book[i] == false)
        {
            box[step] = mInput[i];
            book[i] = true;
            dfsSearch(step + 1);
            book[i] = false;
        }
    }
}