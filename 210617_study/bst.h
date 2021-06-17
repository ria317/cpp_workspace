
typedef struct Node{

    int value;
    Node* left;
    Node* right;

    Node(int v) {
        value = v;
        left = nullptr;
        right = nullptr;
    }

    Node() {
        value = -1;
        left = nullptr;
        right = nullptr;
    }
} Node;

class BST {

private:
    Node *root;

public:
    BST();
    ~BST();

    void insert(int value);
    Node* remove(Node* n, int value );
    Node *find(int val);

    Node* getRoot() { return root;}

    void inorder_travel();

    //void print2DUtil(int space);

};