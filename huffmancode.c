#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
typedef struct HuffmanNode
{
    char character;
    int frequency;
    struct HuffmanNode *left, *right;
} HuffmanNode;
typedef struct PriorityQueue
{
    int size;
    HuffmanNode **array;
} PriorityQueue;
HuffmanNode *createNode(char character, int frequency)
{
    HuffmanNode *node = (HuffmanNode *)malloc(sizeof(HuffmanNode));
    node->character = character;
    node->frequency = frequency;
    node->left = node->right = NULL;
    return node;
}
PriorityQueue *createPriorityQueue(int capacity)
{
    PriorityQueue *pq = (PriorityQueue *)malloc(sizeof(PriorityQueue));
    pq->size = 0;
    pq->array = (HuffmanNode **)malloc(capacity * sizeof(HuffmanNode *));
    return pq;
}
void swapNodes(HuffmanNode **a, HuffmanNode **b)
{
    HuffmanNode *temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(PriorityQueue *pq, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < pq->size && pq->array[left]->frequency < pq->array[smallest]->frequency)
        smallest = left;
    if (right < pq->size && pq->array[right]->frequency < pq->array[smallest]->frequency)
        smallest = right;
    if (smallest != idx)
    {
        swapNodes(&pq->array[smallest], &pq->array[idx]);
        heapify(pq, smallest);
    }
}

void insertPriorityQueue(PriorityQueue *pq, HuffmanNode *node)
{
    int idx = pq->size++;
    pq->array[idx] = node;

    while (idx && pq->array[idx]->frequency < pq->array[(idx - 1) / 2]->frequency)
    {
        swapNodes(&pq->array[idx], &pq->array[(idx - 1) / 2]);
        idx = (idx - 1) / 2;
    }
}

HuffmanNode *extractMin(PriorityQueue *pq)
{
    if (pq->size == 0)
        return NULL;

    HuffmanNode *root = pq->array[0];
    pq->array[0] = pq->array[--pq->size];
    heapify(pq, 0);

    return root;
}

HuffmanNode *buildHuffmanTree(char characters[], int frequencies[], int size)
{
    PriorityQueue *pq = createPriorityQueue(size);

    for (int i = 0; i < size; ++i)
        insertPriorityQueue(pq, createNode(characters[i], frequencies[i]));

    while (pq->size != 1)
    {
        HuffmanNode *left = extractMin(pq);
        HuffmanNode *right = extractMin(pq);

        HuffmanNode *top = createNode('\0', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
        insertPriorityQueue(pq, top);
    }
    return extractMin(pq);
}

void generateHuffmanCodes(HuffmanNode *root, char *code, int length, char **codes, char *characters, int size)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        code[length] = '\0';
        codes[root->character] = strdup(code);
        return;
    }

    code[length] = '0';
    generateHuffmanCodes(root->left, code, length + 1, codes, characters, size);

    code[length] = '1';
    generateHuffmanCodes(root->right, code, length + 1, codes, characters, size);
}

void printHuffmanCodes(char **codes, char *characters, int size)
{
    printf("Character\tCode\n");
    for (int i = 0; i < size; i++)
    {
        printf("%c\t\t%s\n", characters[i], codes[characters[i]]);
    }
}
int main()
{
    char characters[] = {'A', 'T', 'E', 'O'};
    int frequencies[] = {03, 07, 10, 05};
    int size = sizeof(characters) / sizeof(characters[0]);
    HuffmanNode *root = buildHuffmanTree(characters, frequencies, size);
    char *codes[256] = {0};
    char code[100];
    generateHuffmanCodes(root, code, 0, codes, characters, size);

    printHuffmanCodes(codes, characters, size);
    return 0;
}
