typedef struct {
    char* hashSet;
} MyHashSet;

/** Initialize your data structure here. */

MyHashSet* myHashSetCreate() {
    MyHashSet* hsp = malloc(sizeof(MyHashSet));
    hsp->hashSet = malloc(125001);
    memset(hsp->hashSet, 0, 125001);
    return hsp;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    int index = key >> 3, offset = key & 7;
    *(obj->hashSet + index) |= (1 << offset);
}

void myHashSetRemove(MyHashSet* obj, int key) {
    int index = key >> 3, offset = key & 7;
    *(obj->hashSet + index) &= ~(1 << offset);
}

/** Returns true if this set contains the specified element */
bool myHashSetContains(MyHashSet* obj, int key) {
    int index = key >> 3, offset = key & 7;
    return *(obj->hashSet + index) & (1 << offset);
}

void myHashSetFree(MyHashSet* obj) {
    free(obj->hashSet);
}

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);

 * myHashSetRemove(obj, key);

 * bool param_3 = myHashSetContains(obj, key);

 * myHashSetFree(obj);
*/