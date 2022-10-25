#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h = -1;
    do
    {
        h = get_int("Height: "); //get height
    }
    while (h < 1 || h > 8);
    for (int i = 1; i <= h; ++i)
    {
        int spaces = 0;
        if(h != i){
            do
            {
                printf(" ");
                ++spaces;
            }
            while (spaces<(h-i));
        }
        int hashes = 0;
        do {printf("#"); ++hashes;} while (hashes<i);
        printf("\n");
    }
}