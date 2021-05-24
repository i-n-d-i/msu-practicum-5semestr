#include <iostream>
#include <memory>

struct TNode {
    int Elem = 0;
    std::unique_ptr<TNode> Left = nullptr;
    std::unique_ptr<TNode> Right = nullptr;

    TNode(int value);
};

TNode::TNode(int value) {
    Elem = value;
    Left = nullptr;
    Right = nullptr;
}

class Tree {
private:
    std::unique_ptr<TNode> Root;

    void Insert(int value, std::unique_ptr<TNode> &leaf);
    int FindHeight(std::unique_ptr<TNode> &leaf) const;

public:
    Tree();
    void Insert(int value);
    int FindHeight();
};

Tree::Tree()
    : Root(nullptr)
{}

void Tree::Insert(int value) {
    Insert(value, Root);
}

void Tree::Insert(int value, std::unique_ptr<TNode> &leaf) {
    if (leaf == nullptr) {
        leaf.reset(new TNode(value));
        return;
    } else if (value < leaf->Elem) {
        Insert(value, leaf->Left);
    } else if (value > leaf->Elem) {
        Insert(value, leaf->Right);
    }
}

int Tree::FindHeight(std::unique_ptr<TNode> &leaf) const {
  if (leaf == nullptr) {
      return 0;
  }
  return 1 + std::max(FindHeight(leaf->Left), FindHeight(leaf->Right));
}

int Tree::FindHeight() {
    return FindHeight(Root);
}

int main() {
    Tree btree;
    int elem;
    std::cin >> elem;
    while (elem != 0) {
        btree.Insert(elem);
        std::cin >> elem;
    }
    std::cout << btree.FindHeight() << std::endl;
    return 0;
}
