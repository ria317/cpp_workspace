#include <iostream>
#include <queue>
#include <stack>

#include "bst_class.h"

using namespace std;


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
    cout << root->getValue() << endl;

    if (prev) {
        prev->str = prev_str;
    }
    trunk->str = "   |";

    printTree(root->left, trunk, false);
}

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


Node* Node::remove(int value ) {

    if( this->getValue() == value) {
        if( this->left != nullptr ) {
            //왼쪽 최대값
            Node* switch_p = this->left;
            while(switch_p->right!=nullptr) {
                switch_p = switch_p->right;
            }
            this->setValue(switch_p->getValue());
            this->left = this->left->remove(switch_p->getValue());
        } else if( this->right != nullptr ) {
            // 오른쪽의 최소값 찾기
            Node* switch_p = this->right;
            while(switch_p->left != nullptr) {
                switch_p = switch_p->left;
            }
            this->setValue(switch_p->getValue());
            this->right = this->right->remove(switch_p->getValue());
        } else {
            return nullptr;
        }
    } else if( this->getValue() > value ) {
        Node* temp = this->left;
        this->left = this->left->remove( value);
        if( this->left == nullptr)
            delete temp;
    } else {

        this->right = this->right->remove(value);
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


    //root->print2DUtil(0);

    printTree(root, nullptr, false);

cout << endl;
cout << "travel tree inoder " << endl;
    //travel_tree_inorder(root);

    cout << endl;
    //cout << "######### Delete 5 #########" << endl;

    //root->remove( 5);

    cout << endl;
    //root->print2DUtil(0);
    printTree(root, nullptr, false);

    //printTree(root, nullptr, false);
/*
    for(int i=1; i <=10; i++) {
        root = root->remove(i);
        printTree(root, nullptr, false);
    }*/
    travel_tree_inorder(root);
    return 0;

}
