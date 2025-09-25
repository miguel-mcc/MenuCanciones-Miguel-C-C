#ifndef TREEMAP_H
#define TREEMAP_H

typedef struct TreeMap TreeMap;

TreeMap* createTreeMap(int (*lower_than)(void* key1, void* key2));
void insertTreeMap(TreeMap* tree, void* key, void* value);
void* searchTreeMap(TreeMap* tree, void* key);

int lower_than_int(void* key1, void* key2);

void* firstTreeMap(TreeMap* tree);
void* nextTreeMap(TreeMap* tree);

#endif
