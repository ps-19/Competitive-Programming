class Node {
public:
    int key;
    Node* prev;
    Node* next;
    Node(int x){
        key = x;
        prev = this;
        next = this;
    }
    Node(){
        key = 0;
        prev = this;
        next = this;
    }
};
