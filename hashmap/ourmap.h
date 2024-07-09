#include <iostream>
#include "string.h"
using namespace std;

template<typename v>
class MapNode {
public:
    string key;
    v value;
    MapNode* next;

    MapNode(string key, v value) {
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~MapNode() {
        delete next;
    }
};

template<typename v>
class ourmap {
    int count;
    MapNode<v>** buckets;
    int numbuck;

public:
    ourmap() {
        count = 0;
        numbuck = 5;
        buckets = new MapNode<v>*[numbuck];
        for (int i = 0; i < numbuck; i++) {
            buckets[i] = NULL;
        }
    }

    ~ourmap() {
        for (int i = 0; i < numbuck; i++) {
            delete[] buckets[i];
        }
        delete[] buckets;
    }

private:
    int getbucketind(string key) {
        int hascode = 0;
        int currentcoff = 1;
        for (int i = key.length() - 1; i >= 0; i--) {
            hascode += key[i] * currentcoff;
            hascode = hascode % numbuck;
            currentcoff *= 37;
            currentcoff = currentcoff % numbuck;
        }
        return hascode % numbuck;
    }

    void rehash() {
        MapNode<v>** temp = buckets;
        buckets = new MapNode<v>*[2 * numbuck];
        for (int i = 0; i < numbuck; i++) {
            buckets[i] = 0;
        }
        int oldBucketcount = numbuck;
        numbuck *= 2;
        count = 0;
        for (int i = 0; i < oldBucketcount; i++) {
            MapNode<v>* head = temp[i];
            while (head != NULL) {
                string key = head->key;
                v value = head->value;
                insert(key, value);
                head = head->next;
            }
        }
        for (int i = 0; i < oldBucketcount; i++) {
            MapNode<v>* head = temp[i];
            delete head;
        }
        delete[] temp;
    }

public:
    int size() {
        return count;
    }

    v getvalue(string key) {
        int bucketind = getbucketind(key);
        MapNode<v>* head = buckets[bucketind];
        while (head != NULL) {
            if (head->key == key) {
                return head->value;
            }
            head = head->next;
        }
        return 0; // Fix: Add a proper default value or change the return type to v.
    }

    void insert(string key, v value) {
        int bucketind = getbucketind(key);
        MapNode<v>* head = buckets[bucketind];
        while (head != NULL) {
            if (head->key == key) {
                head->value = value;
                return;
            }
            head = head->next;
        }
        head = buckets[bucketind];
        MapNode<v>* node = new MapNode<v>(key, value);
        node->next = head;
        buckets[bucketind] = node;
        count++;
        double loadfactor = (1.0 * count) / numbuck;
        if (loadfactor > 0.7) {
            rehash();
        }
    }

    v remove(string key) {
        int bucketind = getbucketind(key);
        MapNode<v>* head = buckets[bucketind];
        MapNode<v>* prev = NULL;
        while (head != NULL) {
            if (head->key == key) {
                if (prev == NULL) {
                    buckets[bucketind] = head->next;
                }
                else {
                    prev->next = head->next;
                }
                v value = head->value;
                head->next = NULL;
                delete head;
                count--;
                return value;
            }
            prev = head;
            head = head->next;
        }
        return 0; // Fix: Add a proper default value or change the return type to v.
    }
};
