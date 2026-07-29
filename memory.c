#include <stdio.h>

#include "memory.h"

static unsigned long totalAllocations = 0UL;
static unsigned long totalFrees = 0UL;

void memoryInit(void)
{
    totalAllocations = 0UL;
    totalFrees = 0UL;
}

void incrementAllocations(void)
{
    totalAllocations++;
}

void incrementFrees(void)
{
    totalFrees++;
}

void displayMemoryStatistics(void)
{
    printf("\n====================================\n");
    printf("MEMORY STATISTICS\n");
    printf("====================================\n");
    printf("Total Allocations : %lu\n", totalAllocations);
    printf("Total Frees       : %lu\n", totalFrees);
    printf("====================================\n");
}
