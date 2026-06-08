class Node
{
    public:

    int key;
    int value;
    Node* next;
    Node* prev;

    Node(int key, int value)
    {
        this -> key = key;
        this -> value = value;
        next = nullptr;
        prev = nullptr;
    }
};


class LRUCache 
{
public:
int capacity;
Node* left;        //will keep track of the least recently used
Node* right;       //will keep track of the most recently used
unordered_map <int, Node* > cache;

    void remove(Node* node)  //used to remove the least recently used
    {
        Node* pre = node -> prev;
        Node* nxt = node -> next;
        pre -> next = nxt;
        nxt -> prev = pre;
    }

    void insert(Node* node) //when you insert a node, it becomes the most recently used node
    {
        Node* pre = right -> prev;
        pre -> next = node;
        node -> prev = pre;
        node -> next = right;
        right -> prev = node;
    }


    LRUCache(int capacity) 
    {
        this -> capacity = capacity;
        left = new Node(0,0);
        right = new Node(0,0);

        left -> next = right;
        right -> prev = left;
    }
    
    int get(int key) 
    {
        if(cache.find(key) != cache.end())
        {
            Node *node = cache[key];
            remove(node);
            insert(node); //makes it the most recently used key
            return cache[key] -> value;
        }
        else
        return -1;
    }
    
    void put(int key, int value) 
    {
        if(cache.find(key) != cache.end())
        {
            //now we are updating the value
            Node *node = cache[key];
            remove(node);
        }

        //now we insert; taking care of the capacity
        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        insert(newNode);

        if(cache.size() > this -> capacity)
        {
            //remove the LRU
            Node* lru = left -> next;
            remove(lru);
            cache.erase(lru -> key);
            delete lru;
        }
    }
};
