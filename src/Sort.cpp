#include <iostream>
#include <vector>
#include "../include/Sort.h"

std::vector<int> Buddle::sortFun(std::vector<int> input)
{
    for (auto i = 0; i < input.size(); ++i)
    {
        for (auto j = 0; j + 1 < input.size() - i; ++j)
        {
            if (input[j] > input[j + 1])
            {
                // SortBase::swapFun(input[j], input[j + 1]);
                int a = input[j];
                input[j] = input[j + 1];
                input[j + 1] = a;
            }
        }
    }

    return input;
}

std::vector<int> Quick::sortFun(std::vector<int> input)
{
    quickSort(0, int(input.size() - 1), input);
    return input;
}

void Quick::quickSort(int left, int right, std::vector<int> &mInput)
{
    if (left > right)
    {
        return;
    }
    auto tmp = mInput[left];
    auto i = left;
    auto j = right;
    while (i != j)
    {
        while (mInput[j] >= tmp && i < j)
        {
            j--;
        }
        while (mInput[i] <= tmp && i < j)
        {
            i++;
        }

        if (i < j)
        {
            // swapFun(mInput[i], mInput[j]);
            int a = mInput[i];
            mInput[i] = mInput[j];
            mInput[j] = a;
        }
    }

    // swapFun(mInput[left], mInput[i]);
    mInput[left] = mInput[i];
    mInput[i] = tmp;
    quickSort(left, i - 1, mInput);
    quickSort(i + 1, right, mInput);
}

std::vector<int> Chain::sortFun(std::vector<int> input)
{
    nodePtr head{nullptr};
    // nodePtr tail{ nullptr };
    // nodePtr mNodeChain = std::make_shared<Node>();
    nodePtr headNodeChain = std::make_shared<Node>();

    for (const auto &data : input)
    {
        if (!head)
        {
            headNodeChain->data = data;
            head = headNodeChain;
            // tail = mNodeChain->next;
        }
        else
        {
            for (auto iter = head; iter != nullptr; iter = iter->next)
            {
                nodePtr nodeChain = std::make_shared<Node>();
                if (data > iter->data)
                {
                    // hou
                    if (!iter->next)
                    {
                        iter->next = nodeChain;
                        nodeChain->before = iter;
                        break;
                        // tail = nodeChain->next;
                    }
                    else if (iter->next->data <= iter->data)
                    {
                        iter->next->before = nodeChain;
                        nodeChain->next = iter->next;
                        iter->next = nodeChain;
                        nodeChain->before = iter;
                        break;
                    }
                }
                else
                {
                    // qian
                    if (!iter->before)
                    {
                        iter->before = nodeChain;
                        nodeChain->next = iter;
                        head = nodeChain;
                        break;
                    }
                    else if (iter->before->data >= iter->data)
                    {
                        iter->before->next = nodeChain;
                        nodeChain->before = iter->before;
                        iter->before = nodeChain;
                        nodeChain->next = iter;
                        break;
                    }
                }

                if (iter->next == nullptr)
                {
                    iter->next = nodeChain;
                    nodeChain->before = iter;
                }
            }
        }
    }
    std::vector<int> output;
    for (auto iter = head; iter != nullptr; iter = iter->next)
    {
        output.push_back(iter->data);
    }

    return output;
}
