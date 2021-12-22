#include <memory>
#include <iostream>
#include <vector>

class Tree : public std::enable_shared_from_this<Tree>
{
public:
    struct BiTree
    {
        int data;
        std::shared_ptr<BiTree> lchild;
        std::shared_ptr<BiTree> rchild;
    };
	using BiTreePtr = std::shared_ptr<BiTree>;

    BiTreePtr createTree(std::vector<int> nums)
    {
        BiTreePtr rootNode;
        for (int i = 0; i < (int)nums.size(); ++i)
        {
            auto node = _createTreeNode(nums[i]);
            if (i + 1 < nums.size())
            {
                node->lchild = _createTreeNode(nums[i + 1]);
                ++i;
            }
            if (i + 1 < nums.size())
            {
                node->rchild = _createTreeNode(nums[i + 2]);
                ++i;
            }

            if (!rootNode)
            {
                rootNode = node;
            }
        }

        return rootNode;
    }
    // root-->left-->right
    void preOrderTraverse(BiTreePtr root)
    {
        if (!root)
        {
            return;
        }

        mResult.push_back(root->data);
        preOrderTraverse(root->lchild);
        preOrderTraverse(root->rchild);
    }

    // left-->root-->right
    void inOrderTraverse(BiTreePtr root)
    {
        if (!root)
        {
            return;
        }

        preOrderTraverse(root->lchild);
        mResult.push_back(root->data);
        preOrderTraverse(root->rchild);
    }

    // left-->right-->root
    void postOrderTraverse(BiTreePtr root)
    {
        if (!root)
        {
            return;
        }

        preOrderTraverse(root->lchild);
        preOrderTraverse(root->rchild);
        mResult.push_back(root->data);
    }
    std::vector<int> mResult;

private:
    BiTreePtr _createTreeNode(int data)
    {
        BiTree node;
        node.data = data;
        return std::make_shared<Tree::BiTree>(node);
    }
};