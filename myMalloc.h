//
// Created by Noam pnueli on 14/10/2016.
//

#ifndef SEQFIT_MYMALLOC_H
#define SEQFIT_MYMALLOC_H

void init();

void* allocate(int size);

void freeMem(void* addr);

#endif //SEQFIT_MYMALLOC_H
