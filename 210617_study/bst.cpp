#include <iostream>
#include <stack>
#include <queue>
#include <vector>
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

int BST::BFS_travel() {

    queue<Node> q;
    queue<int> depth;
    int i=0;

    Node idx = 0x00;
    int d = 0;

    int ret = 0;

    q.push(*this->root);
    depth.push(i);

    while(!q.empty()) {

        idx = q.front();
        q.pop();
        d = depth.front();
        depth.pop();
        ret = max(d, ret);

//cout << "val : " << idx.value << ", depth : " << d << endl;

        if( idx.left != nullptr ) {
            q.push(*idx.left);
            depth.push(d+1);
        }
        if( idx.right != nullptr) {
            q.push(*idx.right);
            depth.push(d+1);
        }

    }

    return ret;
}

void rec_print(vector<vector<char>>&map, Node* p, int x, int y) {

    //print
    if( p->value  >= 10 ) {
        map[x][y] = ((p->value)/10) + 48;
        map[x][y+1] = ((p->value)%10) + 48;
    } else {
        map[x][y] = (p->value)+48;
    }

    if(p->left != nullptr) {
        map[x+1][y-1] = '/';
        if( map[x+2][y-2] != 0 ) {
            rec_print(map, p->left, x+2, y-1);
        } else {
            rec_print(map, p->left, x+2 , y-2);
        }
    }
    if( p->right != nullptr) {
        map[x+1][y+1] = '\\';
        if( map[x+2][y+2] != 0 ) {
            rec_print(map, p->right, x+2, y+3);
        } else {
            rec_print(map, p->right, x+2, y+2);
        }
        //rec_print(map, p->right, x+2, y+2);
    }

}

void BST::print_tree() {

    int y_max = this->BFS_travel();
    vector<vector<char>> map(y_max*4, vector<char>(120));

    Node* p = this->root;

    //세로 depth는 BFS로 구하기

    //.가로는 root로 시작해서 왼쪽 끝, 오른쪽 끝지점 각각 구함.
    rec_print(map, p, 0, map[0].size()/2);

    for(int i=0; i<map.size(); i++){
        for(int j=0; j<map[0].size(); j++) {
            cout << map[i][j];
        }
        cout << endl;
    }
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

    tree->print_tree();

    //tree->remove(tree->getRoot(), 1);
    //tree->remove(tree->getRoot(), 2);
    //tree->remove(tree->getRoot(), 3);
    //tree->remove(tree->getRoot(), 4);


}