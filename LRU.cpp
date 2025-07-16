struct Node {
    int key, val;
    Node* next = nullptr;
    Node* prev = nullptr;
    Node(int key, int val) : key(key), val(val) {}
};

class LRUCache {
    int cc, mc;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> mp;

    void insert_at_head(Node* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void remove_before_tail() {
        Node* temp = tail->prev;
        remove(temp);
        mp.erase(temp->key);
        delete temp;
        cc--;
    }

public:
    LRUCache(int capacity) : mc(capacity), cc(0) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            int val = node->val;
            remove(node);
            insert_at_head(node);
            return val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->val = value;
            remove(node);
            insert_at_head(node);
        } else {
            if (cc == mc) {
                remove_before_tail();
            }
            Node* new_node = new Node(key, value);
            mp[key] = new_node;
            insert_at_head(new_node);
            cc++;
        }
    }
};
