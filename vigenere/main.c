#include "vigenere.h"

int main()
{
    int p;
    printf("MENU");
    printf("\n1.Enkripsi");
    printf("\n2.Dekripsi");
    printf("\n3.Exit");
    printf("\npilihan:");
    scanf("%d",&p);
    if(p==1)
    {
        Enkripsi();
    }
    else if(p==2)
    {
        Dekripsi();
    }
    else if(p==3)
    {
        return 0;
    }
    else
    {
        printf("input anda salah");
    }
    return 0;
}
