#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

void processArray();
void enterArray();
int readFileArray(FILE *fp, char *fname, int *x);
int readFile(FILE *fp, char *fname);
void printArray(int *x, int n);
void writeFile(FILE *fp, char *fname, int *x);


int i=0;
int size;
int arr[N], arr2[N];

int main()
{
    int mode, count;
    FILE *text;
    char readMode[30];
    char *menu[] = {"MENU",
    "1. Enter a new array",
    "2. Work with an existing array",
    "3. Read array from file",
    "4. Write array to file",
    "5. Masiv2 ot chetni ",
    "6. Izhod"};

    do
    {

        for(i=0; i<7; i++)
        printf("%s\n", menu[i]);
        printf("\n\nIzberete rejim [1-6]: ");
        scanf("%d", &mode);
        switch(mode)
        {
        case 1:
                enterArray();
                processArray();
                break;
        case 2:
                processArray();
                    break;
        case 3:
                printf("Enter a file name to read from. Enter 'def' for default file\n");
                scanf("%s", &readMode);
                if(!strncmp(readMode, "def", 3))
                {
                    count = readFileArray(text, "Test.txt",arr);
                    if(count >=0)
                    {
                        printArray(arr, count);
                        size = count;
                    }
                    else
                        printf("Ne moje da otvori fail za chetene.\n");
                    break;
                }
                else
                {
                    count = readFileArray(text, readMode, arr);
                    if(count >=0)
                    {
                        printArray(arr, count);
                        size = count;
                    }
                    else
                        printf("Ne moje da otvori fail za chetene.\n");
                    break;
                }
        case 4:
                count = 0;
                printf("Chetene....\n");
                count = readFile(text, "Test.txt");
                if(count >= 0)
                    printf("%d celi chisla \n", count);
                else
                    printf("Ne moje da otvori faila za chetene.\n");
                    break;
      /*  case 5:
                chetni(arr, count, masiv2, &n2);
                if(count>=0)
                    printArray(arr,count);
                else
                    printf("Ne moje da otvori faila za chetene.\n");

                if(n2>=0)
                {
                    printf("\nMasiv ot chetni:\n");
                    printArray(masiv2, n2);
                }
                else
                    printf("niama chetni.\n");
                system("pause");
                break;*/
        case 6:
                //system("pause");
                break;
        default:
                printf("\nGreshen izbor!\n");

        }
    }
    while(mode != 6);
    return 0;
}


    void enterArray(){

    printf("\nEnter array size: ");
    scanf("%d", &size);

    for(i=0; i<size; i++)
    {
        printf("Enter element %d: ", i);
        scanf("%d", &arr[i]);
    }

    printf("\n");

    for(i=0; i<size; i++)
    {
        printf("Element %d of arr: %d\n", i, arr[i]);
    }
    printf("\n");
}

void processArray()
{
    int m,n,swap;
    int size2=0;

    for(i=0; i<size; i++)
    {
        m = arr[i];
        if(m < 0)
            m*=-1;
        while(m > 0)
        {
            n=m%10;
            m=m/10;
            if(n == 3)
            {
                arr2[size2] = arr[i];
                size2++;
            }
        }
    }

    for (i = 0 ; i < size2 - 1; i++)
    {
        for (m = 0 ; m < size2 - i - 1; m++)
        {
        if (arr2[m] > arr2[m+1]) /* For decreasing order use < */
        {
            swap       = arr2[m];
            arr2[m]   = arr2[m+1];
            arr2[m+1] = swap;
        }
        }
    }

    for(i=0; i<size2; i++)
    {
        printf("Element %d of arr2: %d\n", i, arr2[i]);
    }
    printf("\n");

}

int readFileArray(FILE *fp, char *fname, int *x)
{
    int n=0;
    i=0;

    fp = fopen(fname, "r");
    if(!fp) return -1;
    while(fscanf(fp, "%d", &x[i]) != EOF)
    {
        i++;
        n++;
    }
    fclose(fp);
    return n;
}

int readFile(FILE *fp, char *fname)
{
    int number, n=0;
    fp = fopen(fname, "r");
    if(!fp)return -1;
    while(fscanf(fp, "%d", &number) != EOF)
    {
        printf("%d\n", number);
        n++;
    }
    fclose(fp);
    return n;
}

void writeFile(File *fp, char *fname)
{
    fp = fopen("/tmp/test.txt", "w+");
    fprintf(fp, "This is testing for fprintf...\n");
    fputs("This is testing for fputs...\n", fp);
    fclose(fp);
}

void printArray(int *x, int n)
{
    for(i=0; i<n; i++)
        printf("arr[%d]=%d\n", i, x[i]);
}
