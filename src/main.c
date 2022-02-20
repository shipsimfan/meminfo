#include <los/memory.h>
#include <stdio.h>
#include <string.h>

int main() {
    MemoryUsage memory_usage;
    memset(&memory_usage, 0, sizeof(MemoryUsage));

    get_memory_usage(&memory_usage);

    printf("Page Size: %lu B\n", memory_usage.page_size);
    printf("Available Memory: %lu KB\n",
           memory_usage.available_pages * memory_usage.page_size / 1024);
    printf("Free memory: %lu KB\n",
           memory_usage.free_pages * memory_usage.page_size / 1024);
    printf("Kernel Heap: %lu KB\n",
           memory_usage.kernel_heap_pages * memory_usage.page_size / 1024);
    printf("Userspace: %lu KB\n",
           memory_usage.userspace_pages * memory_usage.page_size / 1024);
    printf("Kernel Stack: %lu KB\n", memory_usage.kernel_stack_usage / 1024);
}