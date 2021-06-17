
class Node {

private:

    int m_value;

public:
    Node* left;
    Node* right;

    Node(int val);
    ~Node();
    int getValue(){ return m_value; }
    void setValue(int val) { m_value = val; }

    bool insert(int value);
    Node* remove(int value );
    Node *find(int val);
    Node *find_parent(int val);
    void print2DUtil(int space);

};