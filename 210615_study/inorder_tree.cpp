#include <iostream>
#include <stack>

using namespace std;

void print_bst_inorder() {

}

typedef struct Node {

    int value;
    Node *left;
    Node *right;

    Node(int val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
} Node;

Node *insert(Node *root, int value)
{
    Node* idx = root;

    if( idx == nullptr) {
        idx = new Node(value);
        return idx;
    } else {
        while(idx != nullptr ) {
            if( idx->value < value ) {
                if( idx->right == nullptr) {
                    idx->right = new Node(value);
                    break;
                }else {
                    idx = idx->right;
                }
            } else if( idx->value > value ) {
                if( idx->left == nullptr) {
                    idx->left = new Node(value);
                    break;
                } else {
                    idx = idx->left;
                }
            } else {
                return idx;
            }
        }

    }
    return root;
}


void travel_tree_inorder(Node *node) {
    stack<Node> sp;
    Node *p = nullptr;

    p = node;

    while(!sp.empty() || p != nullptr) {

        if( p == nullptr) {
            Node tmp = sp.top();
            cout << tmp.value << endl;

            p = tmp.right;
            sp.pop();

        } else {

            sp.push(*p);
            p = p->left;
        }
    }
}

int main() {

    int pre_order[7] = {4,2,1,3,6,5,7};

    Node *root = nullptr;

    for(int i=0; i<7; i++) {
        root = insert(root, pre_order[i]);
    }

    travel_tree_inorder(root);

}