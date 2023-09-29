#include<bits/stdc++.h>
using namespace std;
#define max 25

main()
{
    int i, j, k, nf, np = 0, page[max], temp;
    int flag = 0, pageFault = 0, top = 0;

    printf("Enter size of Frames:");
    scanf("%d", &nf);
    int frames[nf];
    for (i = 0; i < nf; i++)
        frames[i] = -1;
    printf("Enter pages (press -999 to exit):\n");
    for (i = 0; i < max; i++)
    {
        scanf("%d", &temp);
        if (temp == -999)
            break;
        page[i] = temp;
        np++;
    }
    for (i = 0; i < np; i++)
    {
        flag = 0;
        for (j = 0; j < nf; j++)
        {
            if (frames[j] == page[i])
            {
                printf("\t\n");
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            frames[top] = page[i];
            top++;
            printf("\t\n");
            pageFault++;
            if (top >= nf)
                top = 0;
        }
        printf("%d:\t",page[i]);
        for (k = 0; k < nf; k++)
            printf("%d\t", frames[k]);
    }
    cout<<"\n\ntotal page faults: "<<pageFault<<endl;

}