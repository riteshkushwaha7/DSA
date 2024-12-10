class Node {
public:
    pair<int, int> data;
    Node* next;
    Node* prev;

    Node(pair<int, int> data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class LRUCache {
public:
    map<int, Node*> mpp;
    Node *head, *tail;
    int capacity;

    void deleteNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertNode(Node* node) {
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
    }

    LRUCache(int c) {
        capacity = c;
        mpp.clear();
        head = new Node({-1, -1});
        tail = new Node({-1, -1});
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mpp.find(key) == mpp.end()) return -1;
        Node* node = mpp[key];
        deleteNode(node);
        insertNode(node);
        return node->data.second;
    }

    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()) {
            Node* node = mpp[key];
            node->data.second = value;
            deleteNode(node);
            insertNode(node);
        } else {
            if (mpp.size() == capacity) {
                Node* node = tail->prev;
                mpp.erase(node->data.first);
                deleteNode(node);
                delete node;
            }
            Node* node = new Node({key, value});
            insertNode(node);
            mpp[key] = node;
        }
    }
};
