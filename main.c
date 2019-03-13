#include <stdlib.h>
#include "lib/queue.h"

void clear(Queue queue, int divNumber) {
    int i = 0;
    while(queue->items[i]) {
        if(queue->items[i] % divNumber == 0) {
            for(int j = i; j < queue->total; j++) {
                queue->items[j] = queue->items[j+1];
            }
            queue->total--;
        }
        i++;
    }
}

int main(void) {
    Queue queue = startQueue(50);
    insertItem(queue, 1);
    insertItem(queue, 2);
    insertItem(queue, 3);
    insertItem(queue, 8);
    insertItem(queue, 5);
    insertItem(queue, 9);
    insertItem(queue, 4);
    insertItem(queue, 7);
    insertItem(queue, 2);
    clear(queue, 2);
    while(!isEmpty(queue)) {
        printf("%d ", removeItem(queue));
    }
    destroyQueue(&queue);
    return 0;
}
