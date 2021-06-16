#include <iostream>
#include <stack>
#include <queue>

using namespace std;
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


char canvas[100+10] = {0};

void print_tree(Node* root) {

    //// 트리의 level 갯수
    // 1. tree 너비를 찾는다.
    Node* tmp = root;
    queue<pair<Node,int>> q;

    vector<int> value_arr;
    vector<int> depth_arr;

    q.push(make_pair(*tmp, 0));

    while(!q.empty()) {
        Node idx = q.front().first;
        int depth = q.front().second;
        if( idx.left != nullptr ) {
            q.push(make_pair(*idx.left, depth+1));
        }

        if( idx.right != nullptr) {
            q.push(make_pair(*idx.right, depth+1));
        }

        value_arr.push_back(idx.value);
        depth_arr.push_back(depth);
        q.pop();
    }

    for(int i=0; i<value_arr.size(); i++) {
        cout << "depth : " << depth_arr[i] << ", value : " << value_arr[i] << endl;
    }
    cout << endl;

}


void print2DUtil(Node *root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += 10;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current node after space
    // count
    cout<<endl;
    for (int i = 10; i < space; i++)
        cout<<" ";
    cout<<root->value<<"\n";

    // Process left child
    print2DUtil(root->left, space);
}

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

    //print_tree(root);
    print2DUtil(root, 0);

}