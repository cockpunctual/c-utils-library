#ifndef __HASH_MAP_H__
#define __HASH_MAP_H__
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

enum element_type {
    NUMBER_TYPE = 0,
    STRING_TYPE = 1,
    CUSTOM_TYPE = 2
};

struct key_field {
    unsigned int key_type : 3;
    unsigned int key_len : 5;
    uintptr_t key;
};

struct value_field {
    unsigned int val_type : 3;
    unsigned int val_len : 5;
    uintptr_t value;
};

struct bucket
{
    struct key_field key;
    struct value_field value;
    unsigned int hash_val;
    struct bucket* next;
};

struct hash_map
{
    unsigned long capacity;
    unsigned long buckets_cnt; 
    float load_factor;
    unsigned long size;
    struct bucket* buckets;
};

typedef struct hash_map hash_map;
typedef struct key_field key_field;
typedef struct value_field val_field;

struct hash_map* hashmap_create();
void hashmap_destory(hash_map* map);
bool hashmap_insert(hash_map* map, key_field key, val_field val);
bool hashmap_get(hash_map* map, key_field key, val_field* val);
bool hashmap_delete(hash_map* map, key_field key);

#endif