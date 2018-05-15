#include <iostream>
#include <cstdlib>

using namespace std;

template <typename T>
class TreeNode {

public:
        using TN = TreeNode<T>;
        using TNP = TreeNode<T>*;
        TreeNode(const T e, TNP lc = nullptr, TNP rc = nullptr):
                _e(e), _lChild(lc), _rChild(rc)
        { }
        T _e;
        TNP _lChild;
        TNP _rChild;
};

template <typename T>
class BinTree {
        using TN = TreeNode<T>;
        using TNP = TreeNode<T>;
public:
        BinTree(): _root(nullptr) { }
        BinTree(const T& e) {
                _root = new TN(e);
                if (!_root) abort();
        }
        ~BinTree() { }
        void insert(const T& e);
        void showTree() const;
private:
        TNP _root;
};

template <typename T>
void BinTree<T>::showTree() const {
        int line = 0;
        int row = 0;
        TNP tmpP = _root;
        cout << _root->_ee << endl;
        cout << "©À--" << _root->lChild->_e << endl;
        cout << "©¸--" << _root->rChild->_e << endl;
}

template <typename T>
void BinTree<T>::insert(const T& e) {
        TNP tmpP = _root;
        if (e) {
                if (e < tmpP->_e) {
                        if (!e->lChild) {
                                e->lChild = new TN(e);
                                return;
                        }
                        else tmpP = tmpP->lChild;
                }
                else {
                        if (!e->rChild) {
                                e->rChild = new TN(e);
                                return;
                        }
                        else tmpP = tmpP->rChild;
                }
        }
        else tmpP = new TN(e);
}


int main() {
        BinTree<int> t(2);
        t.insert(1);
        t.insert(3);
        t.showTree();
        return 0;
}
