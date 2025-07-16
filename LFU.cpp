struct Node {
    int key, val, freq;
    Node *next, *prev;
    Node(int k, int v) : key(k), val(v), freq(1), next(nullptr), prev(nullptr) {}
};

struct DList {
    Node *head, *tail;
    DList() {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void insert(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    bool empty() {
        return head->next == tail;
    }

    Node* removeLast() {
        if (empty()) return nullptr;
        Node* last = tail->prev;
        remove(last);
        return last;
    }
};

class LFUCache {
    int cap, size, minf;
    Node* nodes[10005] = {};          // key -> Node*
    DList* freqList[10005] = {};      // freq -> DList*

public:
    LFUCache(int c) : cap(c), size(0), minf(0) {}

    void update(Node* n) {
        int f = n->freq;
        freqList[f]->remove(n);
        if (f == minf && freqList[f]->empty()) minf++;
        n->freq++;
        if (!freqList[n->freq]) freqList[n->freq] = new DList();
        freqList[n->freq]->insert(n);
    }

    int get(int key) {
        Node* n = nodes[key];
        if (!n) return -1;
        update(n);
        return n->val;
    }

    void put(int key, int val) {
        if (!cap) return;
        if (nodes[key]) {
            nodes[key]->val = val;
            update(nodes[key]);
        } else {
            if (size == cap) {
                Node* old = freqList[minf]->removeLast();
                nodes[old->key] = nullptr;
                delete old;
                size--;
            }
            Node* n = new Node(key, val);
            if (!freqList[1]) freqList[1] = new DList();
            freqList[1]->insert(n);
            nodes[key] = n;
            minf = 1;
            size++;
        }
    }
};
