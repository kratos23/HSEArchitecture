#ifndef INC_1_CONTAINER_H
#define INC_1_CONTAINER_H

#include "../matrix/matrix.h"

struct ContainerTag;

typedef struct ContainerTag {
    int size;
    Matrix data[10005];
} Container;

extern void addContainer(Container *containerPtr, Matrix *matrix);

extern void sortContainer(Container *containerPtr);

#endif //INC_1_CONTAINER_H
