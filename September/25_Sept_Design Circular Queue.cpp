class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        this->data = val;
        this->next = NULL;
    }
};

class MyCircularQueue {
    int cap;
    int size;
    Node* head;
    Node* tail;
public:
    
    MyCircularQueue(int k) {
        head = NULL;
        tail =NULL;
        cap = k;
        size = 0;
    }
    
    bool enQueue(int value) {
        if(size == cap) return false;
        Node* cur = new Node(value);
        if(head == NULL){
            head = cur;
            tail = cur;
        }else{
            tail->next = cur;
            tail = tail->next;
        }
        size++;
        return true;
    }
    
    bool deQueue() {
        if(size == 0)return false;
        Node* curr = head;
        head = head->next;
        delete curr;
        size--;
        return true;
    }
    
    int Front() {
        if(size == 0) return -1;
        return head->data;
    }
    
    int Rear() {
        if(size == 0) return -1;
        return tail->data;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == cap;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
