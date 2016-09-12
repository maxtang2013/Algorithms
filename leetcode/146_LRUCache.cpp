#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
#include <unordered_map>

using namespace std;

struct MyListNode {
    int key;
    int val;
    MyListNode* next;
    MyListNode* prev;
    MyListNode():val(0),next(NULL),prev(NULL){}
};

class LRUCache{
public:
    LRUCache(int capacity)
    {
        // free list is treated as a singlely linked list.
        mAllNodes = new MyListNode[capacity];
        for (int i = 0; i < capacity-1; ++i) {
            mAllNodes[i].next = &mAllNodes[i+1];
        }
        mFreeListHead.next = mAllNodes;
        
        mLRUHead.next = mLRUHead.prev = &mLRUHead;
    }
    
    ~LRUCache()
    {
        delete[] mAllNodes;
    }
    
    int get(int key) {
        if (mKeyToNode.count(key) == 0) return -1;
        
        MyListNode *node = mKeyToNode[key];
        // Remove
        remove(node);
        
        // Add to tail.
        addToTail(node);
        
        return node->val;
    }
    
    void set(int key, int value) {
        
        if (get(key) > - 1) {
            MyListNode* node = mKeyToNode[key];
            node->val = value;
            return;
        }
        
        if (mFreeListHead.next == NULL) {
            removeLRU();
        }
        MyListNode* n = mFreeListHead.next;
        mFreeListHead.next = n->next;
        
        addToTail(n);
        
        n->val = value;
        n->key = key;
        mKeyToNode[key] = n;
    }
    
private:
    
    void addToTail(MyListNode* node) {
        node->next = &mLRUHead;
        node->prev = mLRUHead.prev;
        mLRUHead.prev->next = node;
        mLRUHead.prev = node;
    }
    
    void remove(MyListNode* node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }
    
    void removeLRU()
    {
        MyListNode* n = mLRUHead.next;
        remove(n);
        
        n->next = n->prev = NULL;
        mFreeListHead.next = n;
        
        mKeyToNode.erase(mKeyToNode.find(n->key));
    }
    
    MyListNode mLRUHead;
    // free list is treated as a singlely linked list.
    MyListNode mFreeListHead;
    unordered_map<int, MyListNode*> mKeyToNode;
    MyListNode* mAllNodes;
};

void Test0()
{
    LRUCache cache(3);
    
    cache.set(1, 3);
    cache.set(2, 5);
    cache.set(4, 1);
    
    cout << cache.get(4) << endl;
    cout << cache.get(3) << endl;
    cout << cache.get(1) << endl;
    
    cache.set(3, 9);
    cout << cache.get(2) << endl;
    
}

void Test1()
{
    LRUCache cache(10);
    cache.set(7,28);
    cache.set(7,1);
    cache.set(8,15);
    cout << cache.get(6) <<endl;
    cache.set(10,27);
    cache.set(8,10);
    cout << cache.get(8) << endl;
    cache.set(6,29);
    cache.set(1,9);
    cout << cache.get(6) << endl;
    cache.set(10,7);
    cout << cache.get(1) << endl;
    cout <<cache.get(2)<< endl;
    cout << cache.get(13)<< endl;
    cache.set(8,30);
    cache.set(1,5);
    cout << cache.get(1)<< endl;
    cache.set(13,2);
    cout << cache.get(12)<< endl;
}

int main()
{
    //Test0();
    Test1();
    
    return 0;
}
