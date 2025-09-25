#include <stdio.h>
#include <stdlib.h>
#include "treemap.h"

typedef struct TreeNode {
    void* key;
    void* value;
    struct TreeNode* left;
    struct TreeNode* right;
    struct TreeNode* parent;
} TreeNode;

struct TreeMap {
    TreeNode* root;
    int (*lower_than)(void* key1, void* key2);
    TreeNode* current;
};

TreeNode* createTreeNode(void* key, void* value) {
    TreeNode* node = (TreeNode*) malloc(sizeof(TreeNode));
    node->key = key;
    node->value = value;
    node->left = node->right = node->parent = NULL;
    return node;
}

TreeMap* createTreeMap(int (*lower_than)(void* key1, void* key2)) {
    TreeMap* map = (TreeMap*) malloc(sizeof(TreeMap));
    map->root = NULL;
    map->lower_than = lower_than;
    map->current = NULL;
    return map;
}

void insertTreeMap(TreeMap* tree, void* key, void* value) {
    TreeNode* parent = NULL;
    TreeNode* current = tree->root;

    while (current != NULL) {
        parent = current;
        if (tree->lower_than(key, current->key))
            current = current->left;
        else
            current = current->right;
    }

    TreeNode* newNode = createTreeNode(key, value);
    newNode->parent = parent;

    if (parent == NULL) {
        tree->root = newNode;
    } else if (tree->lower_than(key, parent->key)) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
}

void* searchTreeMap(TreeMap* tree, void* key) {
    TreeNode* current = tree->root;
    while (current != NULL) {
        if (tree->lower_than(key, current->key)) {
            current = current->left;
        } else if (tree->lower_than(current->key, key)) {
            current = current->right;
        } else {
            return current->value;
        }
    }
    return NULL;
}

int lower_than_int(void* key1, void* key2) {
    return (*(int*)key1 < *(int*)key2);
}

static TreeNode* leftmost(TreeNode* node) {
    while (node && node->left) node = node->left;
    return node;
}

void* firstTreeMap(TreeMap* tree) {
    tree->current = leftmost(tree->root);
    return tree->current ? tree->current->value : NULL;
}

void* nextTreeMap(TreeMap* tree) {
    if (!tree->current) return NULL;
    TreeNode* nodo = tree->current;

    if (nodo->right) {
        nodo = leftmost(nodo->right);
    } else {
        TreeNode* parent = nodo->parent;
        while (parent && nodo == parent->right) {
            nodo = parent;
            parent = parent->parent;
        }
        nodo = parent;
    }

    tree->current = nodo;
    return tree->current ? tree->current->value : NULL;
}