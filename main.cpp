#include <iostream>

using namespace std;

class IntervalNode {
public:
    int r, l, max;
    IntervalNode *left;
    IntervalNode *right;

    IntervalNode() {
        this->r = 0;
        this->l = 0;
        max = 0;
        left = right = nullptr;
    }

    IntervalNode(int l, int r) {
        this->l = l;
        this->r = r;
        max = r;
        left = right = nullptr;
    }

    bool intersection(int ll, int rr) {
        if ((this->l < ll && this->r > ll) || (this->l < rr && this->r > rr)) {
            return true;
        }
        return false;
    }
};

class IntervalTree {

public:
    IntervalNode *root;

    IntervalTree() {
        root = nullptr;
    }

    void insert(int ll, int rr) {
        if (root == nullptr) {
            root = new IntervalNode(ll, rr);
        } else {
            IntervalNode *parent;
            IntervalNode *current = root;
            bool right = true;
            while (current != nullptr) {
                parent = current;
                if (current->l > ll) {
                    right = false;
                    if (rr > current->max) {
                        current->max = rr;
                    }
                    current = current->left;
                } else {
                    right = true;
                    if (rr > current->max) {
                        current->max = rr;
                    }
                    current = current->right;
                }
            }
            if (right) {
                parent->right = new IntervalNode(ll, rr);
            } else {
                parent->left = new IntervalNode(ll, rr);
            }
        }
    }

    void search(int ll, int rr) {
        IntervalNode *current = root;
        bool found = false;
        while (current != nullptr) {
            // cout<<"1"<<endl;
            if (current->intersection(ll, rr)) {
                cout << "the ( " << ll << " " << rr << " ) Interval is intersect with ---> ";
                cout << " low = " << current->l << " high = " << current->r << endl;
                found = true;
                break;
            } else if (current->left == nullptr || current->left->max < ll) {
                current = current->right;
                //  cout<<"right"<<endl;
            } else {
                //   cout<<"left"<<endl;
                current = current->left;
            }
        }
        if (!found) {
            cout << "the interval not found!!!!!!!!!" << endl;
        }
    }

    void deleteNode(int ll, int rr) {
        IntervalNode *current = root;
        IntervalNode *parent;
        bool found = false, right = true;
        while (current != nullptr && !found) {
            // cout<<"1"<<endl;
            if (current->l == ll && current->r == rr) {
                found = true;
                if (current->left == nullptr && current->right == nullptr) {
                    if (right)parent->right = nullptr;
                    else parent->left = nullptr;
                    delete current;
                } else if (current->left == nullptr && current->right != nullptr) {
                    if (right) parent->right = current->right;
                    else parent->left = current->right;
                    delete current;
                } else if (current->left != nullptr && current->right == nullptr) {
                    if (right)parent->right = current->left;
                    else parent->left = current->left;
                    delete current;
                }
                    //predecessor
                else {
                    IntervalNode *pred = current->right;
                    IntervalNode *predParent = current;
                    bool left = false;
                    while (pred->left != nullptr) {
                        left = true;
                        predParent = pred;
                        pred = pred->left;
                    }
                    current->l = pred->l;
                    current->r = pred->r;
                    if (left)predParent->left = nullptr;
                    else predParent->right = nullptr;
                    delete pred;
                }
            } else if (current->l > ll) {
                parent = current;
                right = false;
                current = current->left;
                //cout<<"left"<<endl;
            } else {
                parent = current;
                right = true;
                current = current->right;
                //cout<<"right"<<endl;
            }
        }
        if (!found)cout << "the Tree doesn't have this node to delete!!!!" << endl;
        updatePreorder(root);

    }

    void updateNode(IntervalNode *node) {
        int max = node->r;
        int max2 = update(node, max);
        node->max = max2;
    }

    int update(IntervalNode *current, int currentMax) {
        if (current == nullptr)
            return currentMax;
        if (current->r >= currentMax) currentMax = current->r;
        update(current->left, currentMax);
        update(current->right, currentMax);
    }

    void updatePreorder(IntervalNode *node) {
        if (node == nullptr)
            return;
        /* first print data of node */
        updateNode(node);

        /* then recur on left subtree */
        updatePreorder(node->left);

        /* now recur on right subtree */
        updatePreorder(node->right);
    }

    void printPreorder(IntervalNode *node) {
        if (node == nullptr)
            return;

        /* first print data of node */
        cout << node->l << " " << node->r << " max = " << node->max << endl;

        /* then recur on left subtree */
        printPreorder(node->left);

        /* now recur on right subtree */
        printPreorder(node->right);
    }
};

int main() {
    IntervalTree tree;

    tree.insert(17, 19);
    tree.insert(21, 24);
    tree.insert(5, 8);
    tree.insert(4, 8);
    tree.insert(15, 18);
    tree.insert(16, 22);
    tree.insert(7, 10);
    tree.search(16, 20);
    cout << "print Tree in preorder method before delete: " << endl;
    tree.printPreorder(tree.root);
    cout << "print Tree in preorder method after delete: " << endl;
    tree.deleteNode(16, 22);
    tree.deleteNode(5, 8);
    tree.printPreorder(tree.root);
//cout<<tree.root->left->max;

}
