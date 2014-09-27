#include <stdio.h>
#include <math.h>
#define MAX_AREA 1100

int area[MAX_AREA];

void create_possible_areas()
{
    int i, a, ra, s, mc;
    int temp[MAX_AREA];
    for (i = 1; i <= MAX_AREA; i++)
        temp[i] = i*i;

    area[0] = 0;
    area[1] = 1;
    int max_side = sqrt(MAX_AREA);
    for (a = 2; a < MAX_AREA; a++) { 
        mc = MAX_AREA;
        for (s = 1; s <= max_side; s++) { 
            ra = a - temp[s];
            if (ra < 0)
                break;

            if (ra == 0) {
                mc = 1;   
                break;
            }
            if ((area[ra]+1) < mc)
               mc = 1 + area[ra]; 
        }
        area[a] = mc;
//        printf("%d: %d\n", a, mc);
    }
}

int main()
{
    int t, a;
    create_possible_areas();
    scanf("%d", &t);
    while (t--){
        scanf("%d", &a);
        printf("%d\n", area[a]);
    }
    return 0;
}

