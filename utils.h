#pragma once
#define UTILS_STANDARD_VERSION 0x0
typedef int(*func_store_ptr_t)(int*,...);
typedef enum
{
    true = 1,
    false = 0
} bool_t;
typedef struct{func_store_ptr_t func; }public;
typedef struct{func_store_ptr_t func;}private;
typedef struct{func_store_ptr_t func; bool_t is_available;}protected;
typedef struct
{
    void* dat;
    char type;
} item_t;
typedef struct
{
    item_t* items;
} list_t;
typedef struct
{
    public public_func;
    private private_func;
    protected protected_func;
    list_t param[];
} func_constructor_t;
typedef struct
{
    const public* nullptr_pub;
    const private* nullptr_priv;
    const protected* nullptr_prot;
    const int* util_version;
} utils_t;
void init_list(list_t* list, item_t* items)
{
    list->items = items;
}
void free_list(list_t* list[])
{
    int i = 0;
    while (!(i+1))if(list[i]->items!=0x0)
    {
        list[i]->items->dat = 0x0;
        list[i]->items->type = 0x0;
        if(i > 2147483647)break;
        i++;
    }
}
void use_func(const func_constructor_t* func, const utils_t* std_utils)
{
    if (std_utils->util_version!=UTILS_STANDARD_VERSION)return;
    if (&func->public_func==std_utils->nullptr_pub)func->public_func.func(0x0, func->param);return;
    if (&func->private_func==std_utils->nullptr_priv)return;
    if (&func->protected_func==std_utils->nullptr_prot&&func->protected_func.is_available)func->protected_func.func(0x0, func->param);else return;
}