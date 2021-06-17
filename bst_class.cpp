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

Node::~Node() {


    //delete this

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

void Node::remove(Node* root, int value) {

    Node* remove_p = find(value);
    Node* switch_p;

    if( remove_p->left == nullptr && remove_p->right == nullptr) {


        Node* tmp = root;
        while(tmp != nullptr ) {

            if( tmp->getValue() == remove_p->getValue() ) {
                //같은경우
                if( tmp->left != nullptr && tmp->left->getValue() == remove_p->getValue() ) {
                    tmp->left = nullptr;
                    delete remove_p;
                    return ;
                }
                else if( tmp->right != nullptr && tmp->right->getValue() == remove_p->getValue() ) {
                    tmp->right = nullptr;
                    delete remove_p;
                    return ;
                }
            } else if( tmp->getValue() > remove_p->getValue() ) {
                if( tmp->left == remove_p ) {
                    tmp->left = nullptr;
                    delete remove_p;
                    return ;
                }
                /*if( tmp->left != nullptr && tmp->left->getValue() == remove_p->getValue() ) {
                    tmp->left = nullptr;
                    delete remove_p;
                    return ;
                }*/
                else {
                    tmp = tmp->left;
                }
            } else if( tmp->getValue() < remove_p->getValue() ) {

                if( tmp->right == remove_p ) {
                    tmp->right = nullptr;
                    delete remove_p;
                    return ;
                }
                /*if( tmp->right != nullptr && tmp->right->getValue() == remove_p->getValue() ) {
                    tmp->right = nullptr;
                    delete remove_p;
                    return ;
                }*/
                else {
                    tmp = tmp->right;
                }
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
            (remove_p->left)->remove(root, switch_p->getValue());

        } else {
            switch_p = switch_p->right;
            // right 에서 가장 작은값
            while( switch_p->left != nullptr) {
                switch_p = switch_p->left;
            }

            remove_p->setValue(switch_p->getValue());
            (remove_p->right)->remove(root, switch_p->getValue());
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
    Node *root = new Node(5);


    root->insert(2);
    root->insert(7);
    root->insert(1);
    root->insert(4);
    root->insert(3);
    root->insert(6);
    root->insert(9);
    root->insert(8);
    root->insert(10);


    root->print2DUtil(0);
cout << endl;
cout << "travel tree inoder " << endl;
    travel_tree_inorder(root);

    cout << endl;
    cout << "######### Delete 5 #########" << endl;

    root->remove(root, 5);

    cout << endl;
    root->print2DUtil(0);

    //travel_tree_inorder(root);
    return 0;

}
