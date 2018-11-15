typedef struct FreeBlock {
  int start;
  int len;
  struct FreeBlock *prev, *next;
} FreeBlock;

typedef struct {
  FreeBlock *head;
  int len;
} Memory;

void initMemory(Memory *memory, int length);
void printMemory(Memory *memory);
void allocateMemory(Memory *memory, int start, int length);
void freeMemory(Memory *memory, int start, int length);

