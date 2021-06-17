#include <iostream>
#include <stack>
#include "bst.h"

using namespace std;


BST::BST() {
    root = nullptr;

}

BST::~BST() {

}

void BST::inorder_travel() {

    stack<Node> sp;
    Node* p;

    p = this->root;
    Node tmp;
    while( !sp.empty() || p != nullptr ) {
        if( p == nullptr ) {
            tmp = sp.top();
            cout << tmp.value << endl;
            sp.pop();

            p = tmp.right;
        } else {
            sp.push(*p);
            p = p->left;
        }
    }
}

void BST::insert(int value) {
    Node *p = this->root;

    if( p == nullptr) {
        this->root = new Node(value);
        return ;
    }

    while( p != nullptr) {
        if( p->value < value ) {
            if( p->right == nullptr) {
                p->right = new Node(value);
                return ;
            } else {
                p = p->right;
            }
        } else if( p->value > value ) {
            if( p->left == nullptr) {
                p->left = new Node(value);
                return ;
            } else {
                p = p->left;
            }
        } else {
            // m_value == value;r
            return ;
        }
    }
}


Node* BST::remove(Node* node, int value ) {

    cout << " ########## remove :" << value << " ############ "<< endl;

    if( node->value == value ) {
        // 대체자를 찾기
        //Node* switch_p = node;

        if( node->left != nullptr) {
            // left의 최대값 찾기
            Node* switch_p = node->left;
            while(switch_p->right != nullptr) {
                switch_p = switch_p->right;
            }
            node->value = switch_p->value;
            node->left = remove(node->left, switch_p->value);

        } else if( node->right != nullptr) {
            //right의 최소값
            Node* switch_p = node->right;
            while(switch_p->left != nullptr) {
                switch_p = switch_p->left;
            }
            node->value = switch_p->value;
            node->right = remove(node->right, switch_p->value);

        } else {
            // 둘다 nullptr, leaf node 인 경우 switch 필요없음.
            // delete node-
            node = nullptr;
            delete node;
            return nullptr;
        }
    } else if( node->value > value ) {
        node->left = remove(node->left, value);
    } else {
        node->right = remove( node->right, value);
    }

}
Node* BST::find(int value) {

    Node* p = this->root;

    while( p != nullptr ) {
        if( p->value == value) return p;
        else if( p->value > value ) {
            p = p->left;
        } else {
            p = p->right;
        }
    }

    return nullptr;
}

struct Trunk
{
    Trunk *prev;
    string str;

    Trunk(Trunk *prev, string str)
    {
        this->prev = prev;
        this->str = str;
    }
};

// Helper function to print branches of the binary tree
void showTrunks(Trunk *p)
{
    if (p == nullptr) {
        return;
    }

    showTrunks(p->prev);
    cout << p->str;
}

// Recursive function to print a binary tree.
// It uses the inorder traversal.
void printTree(Node* root, Trunk *prev, bool isLeft)
{
    if (root == nullptr) {
        return;
    }

    string prev_str = "    ";
    Trunk *trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev) {
        trunk->str = "———";
    }
    else if (isLeft)
    {
        trunk->str = ".———";
        prev_str = "   |";
    }
    else {
        trunk->str = "`———";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->value << endl;

    if (prev) {
        prev->str = prev_str;
    }
    trunk->str = "   |";

    printTree(root->left, trunk, false);
}

int main(void) {

    BST* tree = new BST();

    tree->insert(5);
    tree->insert(2);
    tree->insert(7);
    tree->insert(1);
    tree->insert(4);
    tree->insert(3);
    tree->insert(6);
    tree->insert(9);
    tree->insert(8);
    tree->insert(10);

    printTree(tree->getRoot(), nullptr , false);


    tree->remove(tree->getRoot(), 1);
    printTree(tree->getRoot(), nullptr , false);
    tree->remove(tree->getRoot(), 2);
    printTree(tree->getRoot(), nullptr , false);
    tree->remove(tree->getRoot(), 3);
    printTree(tree->getRoot(), nullptr , false);
    tree->remove(tree->getRoot(), 4);
    printTree(tree->getRoot(), nullptr , false);

}