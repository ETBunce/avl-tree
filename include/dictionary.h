#ifndef _DICTIONARY_H_
#define _DICTIONARY_H_
#include <vector>
#include "avl_tree.h"

//PART 1: The Pair structure
template <typename K, typename V>
struct Pair {
    K key;
    V value;
    bool operator<(const Pair& p) { return key < p.key; }
    bool operator>(const Pair& p) { return key > p.key; }
    bool operator==(const Pair& p) { return key == p.key; }
    friend std::ostream& operator<<(std::ostream& out, const Pair& p) {
        out << "(" << p.key << ", " << p.value << ")";
        return out;
    }
};

// PART 2: The Dictionary class

template <typename K, typename V>
class Dictionary : private AVLTree<Pair<K,V>> {
private:

public:
    Dictionary() : AVLTree<Pair<K,V>>() {}
    Dictionary(const Dictionary<K,V>& d) : AVLTree<Pair<K,V>>(d) {}

    bool empty() { return AVLTree<Pair<K,V>>::empty(); } //returns true if the dictionary is empty.

    int size() { return AVLTree<Pair<K,V>>::size(); } // returns the number of pairs in the dictionary.
    
    // returns a pointer to the value associated with key or null otherwise.
    V* get(K key) {
        auto node = AVLTree<Pair<K,V>>::search(Pair<K,V> {key});
        if (node) return &(node->info.value);
        return nullptr;
    }

    // inserts the pair of key and value into the dictionary if 
    // it does not exist or change the value of the pair with key to value.
    void put(K key, V value) { AVLTree<Pair<K,V>>::insert(Pair<K,V>{key,value}); } 

    // removes the pair with key from the dictionary.
    void del(K key) { AVLTree<Pair<K,V>>::remove(Pair<K,V>{key}); }

    // remove all the pairs from the dictionary.
    void clear() { AVLTree<Pair<K,V>>::destroy(AVLTree<Pair<K,V>>::root); }

    void addKeyToVector(std::vector<K>& vec, Node<Pair<K,V>>* node) {
        if (node) {
            addKeyToVector(vec, node->left);
            vec.push_back(node->info.key);
            addKeyToVector(vec, node->right);
        }
    }

    void addValueToVector(std::vector<V>& vec, Node<Pair<K,V>>* node) {
        if (node) {
            addValueToVector(vec, node->left);
            vec.push_back(node->info.value);
            addValueToVector(vec, node->right);
        }
    }

    std::vector<K> keys() { // returns a vector of all the keys in the dictionary in no particular order.
        std::vector<K> vec;
        addKeyToVector(vec,AVLTree<Pair<K,V>>::root);
        return vec;
    }

    std::vector<V> values() { // returns a vector of all the values in the dictionary in no particular order.
        std::vector<V> vec;
        addValueToVector(vec,AVLTree<Pair<K,V>>::root);
        return vec;
    }

    friend std::ostream& operator<<(std::ostream& out, const Dictionary& d) {
        d.inorderTraversal(out);
        return out;
    }
};

#endif