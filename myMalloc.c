//
// Created by Noam pnueli on 14/10/2016.
//

#include <unistd.h>
#include <string.h>

#define INITIAL_SIZE 10000

char* memory;

struct header
{
    int size;
    char flag;
};

void init()
{
    memory = sbrk(INITIAL_SIZE);
    struct header init_header;
    init_header.flag = 0;
    init_header.size = INITIAL_SIZE;

    memcpy(memory, &init_header, sizeof(init_header));
}

void* allocate(int size)
{
    struct header* ptr = (struct header*)memory;
    void* new_ptr = 0;
    while(ptr->flag == 1 || (ptr->size < size + sizeof(struct header) && ptr->flag == 0)) {
        if ((char *) ptr < memory + INITIAL_SIZE)
        {
            char *p = (char*)ptr;
            p += ptr->size;
            ptr = (struct header*)p;
        }
        else
            break;
    }
    if((char *)ptr < memory + INITIAL_SIZE)
    {
        int prev_size = ptr->size;
        ptr->size = size + sizeof(struct header);
        ptr->flag = 1;

        new_ptr = (char *)ptr + sizeof(struct header);

        ptr = (struct header*)((char *)ptr + ptr->size);
        if(ptr->size < prev_size)
        {
            ptr->size = prev_size - size - sizeof(struct header);
            ptr->flag = 0;
        }
    }

    return new_ptr;

}

void freeMem(void* addr)
{
    struct header* ptr = (struct header *)((char *)addr - sizeof(struct header));
    ptr->flag = 0;
    struct header* next = (struct header *)((char *)ptr + ptr->size);
    if(next->flag == 0)
    {
        ptr->size += next->size;
    }
}

