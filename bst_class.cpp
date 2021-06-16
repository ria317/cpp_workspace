#include <iostream>
#include <queue>
#include <stack>

#include "bst_class.h"

using namespace std;

Node::Node(int val) {
    m_value = val;
    left = nullptr;
    right = nullptr;
}

Node::Node() {

    left = nullptr;
    right = nullptr;
}

Node::~Node() {

}


bool Node::insert(int value)
{
    Node *p = this;

    while( p != nullptr) {
        if( p->getValue() < value ) {
            if( p->right == nullptr) {
                p->right = new Node(value);
                return true;
            } else {
                p = p->right;
            }
        } else if( p->getValue() > value ) {
            if( p->left == nullptr) {
                p->left = new Node(value);
                return true;
            } else {
                p = p->left;
            }
        } else {
            // m_value == value;r
            return false;
        }
    }

    return false;

}

Node* Node::find(int value)
{

    Node* res = this;
    while(res != nullptr) {
        if( res->getValue() == value) {
            return res;
        } else {
            if( res->getValue() > value ) {
                res = res->left;
            } else {
                res = res->right;
            }
        }
    }
    return nullptr;
}

Node* Node::find_parent(int value)
{

    Node* res = this;

    if( res->getValue() == value) {
        return nullptr;
    }

    while( res != nullptr )
    {
        if( res->left->getValue() == value || res->right->getValue() == value ) {
            return res;
        } else {
            if( res->getValue() > value ) {
                //go to right
                res = res->right;
            } else {
                // go to left
                res = res->left;
            }
        }
    }
    return nullptr;
}

void Node::remove(int value) {

    Node* parent = find_parent(value);
    Node* remove_p = find(value);
    Node* switch_p;

    if( remove_p->left == nullptr && remove_p->right == nullptr) {
        if( parent == nullptr) {
            //head 임..
            delete remove_p;

        } else {
            if( parent->right->getValue() == value ) {
                parent->right = nullptr;
                delete remove_p;

            } else if( parent->left->getValue() == value ) {
                parent->left = nullptr;
                delete remove_p;
            }
        }
    } else {
        switch_p = remove_p;

        if( switch_p->left != nullptr) {
            switch_p = switch_p->left;
            // left 에서 가장 큰값
            while( switch_p->right != nullptr ) {
                switch_p = switch_p->right;
            }
            remove_p->setValue(switch_p->getValue());
            (remove_p->left)->remove(switch_p->getValue());

        } else {
            switch_p = switch_p->right;
            // right 에서 가장 작은값
            while( switch_p->left != nullptr) {
                switch_p = switch_p->left;
            }

            remove_p->setValue(switch_p->getValue());
            (remove_p->right)->remove(switch_p->getValue());
        }
    }

}


void Node::print2DUtil(int space)
{
    // Base case
    Node* curr = this;
    if (curr == nullptr)
        return;

    // Increase distance between levels
    space += 10;

    // Process right child first

    curr->right->print2DUtil(space);

    // Print current node after space
    // count
    cout<<endl;
    for (int i = 10; i < space; i++)
        cout<<" ";
    cout<<curr->getValue()<<"\n";

    // Process left child
    curr->left->print2DUtil(space);
}

void travel_tree_inorder(Node *node) {
    stack<Node> sp;
    Node *p = nullptr;

    p = node;

    while(!sp.empty() || p != nullptr) {

        if( p == nullptr) {
            Node tmp = sp.top();
            cout << tmp.getValue() << endl;

            p = tmp.right;
            sp.pop();

        } else {

            sp.push(*p);
            p = p->left;
        }
    }
}


int main()
{
    Node *root = new Node(4);


    root->insert(2);
    root->insert(1);
    root->insert(3);
    root->insert(6);
    root->insert(5);
    root->insert(7);


    root->print2DUtil(0);

    cout << endl;
    cout << "######### Delete 2 #########" << endl;

    root->remove(2);

    cout << endl;
    root->print2DUtil(0);
    return 0;

}
