#include <stdio.h>
#include <stdlib.h>

typedef struct RacingCars{
    char *name;
    int speed;
    struct RacingCars *next;
}Car;

Car* addCar();
Car* AddToLast(Car* last, Car* current);
void printList(Car* first);

int main(void)
{

    Car *first, *last, *current = NULL;
    int n;
    printf("How many cars? ");
    scanf("%d", &n);

    for(int i=0; i<n; i++)
    {
        current = addCar();
        if (i == 0)
        {
            first = last = current;
            continue;
        }
        last = AddToLast(last, current);
    }

    printList(first);


    return 0;
}

Car* addCar()
{
    Car *current = malloc(sizeof(Car));
    if(current == NULL) return NULL;
    current->name = malloc(20*sizeof(char));
    printf("Enter car name: ");
    scanf("%s", current->name);
    printf("Enter car speed: ");
    scanf("%d", &current->speed);
    current->next = NULL;
    return current;
}
Car* AddToLast(Car* last, Car* current)
{
    last->next = current;
    //last = current;
    return current;
}

void printList(Car* first) {
    Car* current;
    for(current=first; current != NULL; current = current->next) {
        printf("Name: %s, ", current->name);
        printf("Speed: %d\n", current->speed);
    }
}
