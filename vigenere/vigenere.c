#include "vigenere.h"
int ChartoInt(char c)
{
    if (c=='a')
    {
        return 0;
    }
    else if (c=='b')
    {
        return 1;
    }
    else if (c=='c')
    {
        return 2;
    }
    else if (c=='d')
    {
        return 3;
    }
    else if (c=='e')
    {
        return 4;
    }
    else if (c=='f')
    {
        return 5;
    }
    else if (c=='g')
    {
        return 6;
    }
    else if (c=='h')
    {
        return 7;
    }
    else if (c=='i')
    {
        return 8;
    }
    else if (c=='j')
    {
        return 9;
    }
    else if (c=='k')
    {
        return 10;
    }
    else if (c=='l')
    {
        return 11;
    }
    else if (c=='m')
    {
        return 12;
    }
    else if (c=='n')
    {
        return 13;
    }
    else if (c=='o')
    {
        return 14;
    }
    else if (c=='p')
    {
        return 15;
    }
    else if (c=='q')
    {
        return 16;
    }
    else if (c=='r')
    {
        return 17;
    }
    else if (c=='s')
    {
        return 18;
    }
    else if (c=='t')
    {
        return 19;
    }
    else if (c=='u')
    {
        return 20;
    }
    else if (c=='v')
    {
        return 21;
    }
    else if (c=='w')
    {
        return 22;
    }
    else if (c=='x')
    {
        return 23;
    }
    else if (c=='y')
    {
        return 24;
    }
    else if (c=='z')
    {
        return 25;
    }
}
char InttoChar(int x)
{
    if(x==0)
		{
			return 'a';
		}
		else if(x==1)
		{
			return 'b';
		}
		else if(x==2)
		{
			return 'c';
		}
		else if(x==3)
		{
			return 'd';
		}
		else if(x==4)
		{
			return 'e';
		}
		else if(x==5)
		{
			return 'f';
		}
		else if(x==6)
		{
			return 'g';
		}
		else if(x==7)
		{
			return 'h';
		}
		else if(x==8)
		{
			return 'i';
		}
		else if(x==9)
		{
			return 'j';
		}
		else if(x==10)
		{
			return 'k';
		}
		else if(x==11)
		{
			return 'l';
		}
		else if(x==12)
		{
			return 'm';
		}
		else if(x==13)
		{
			return 'n';
		}
		else if(x==14)
		{
			return 'o';
		}
		else if(x==15)
		{
			return 'p';
		}
		else if(x==16)
		{
			return 'q';
		}
		else if(x==17)
		{
			return 'r';
		}
		else if(x==18)
		{
			return 's';
		}
		else if(x==19)
		{
			return 't';
		}
		else if(x==20)
		{
			return 'u';
		}
		else if(x==21)
		{
			return 'v';
		}
		else if(x==22)
		{
			return 'w';
		}
		else if(x==23)
		{
			return 'x';
		}
		else if(x==24)
		{
			return 'y';
		}
		else if(x==25)
		{
			return 'z';
		}
}
boolean IsSimbol(char c)
	{
		if(c=='!' || c=='@' || c=='#' || c=='$' || c=='%' || c=='^' || c=='&' ||
		   c=='*' || c=='(' || c==')' || c=='_' || c=='-' || c=='=' || c=='+' ||
		   c=='{' || c=='[' || c=='}' || c==']' || c=='|' || c==':' || c==';' ||
		   c=='"' || c=='<' || c==',' || c=='>' || c=='.' || c=='?' || c=='/' ||
		   c==' ' || c=='\n')
		{
			return true;
		}
		else
		{
			return false;
		}
	}
void Enkripsi()
{
    int i=0,n=0,a=0,e;
    char CC;
    char key[100],plain[100];
    FILE *file1=fopen("plain.txt", "r");
    FILE *file2=fopen("cipher.txt", "w");
    printf("masukkan key:");
    scanf("%s",key);
    printf("panjang key:%d",strlen(key));
    while(retval!=EOF){
        retval=fscanf(file1, "%c", &CC);
        if(retval==EOF)
            break;
        plain[n]=CC;
        n++;
    }
    for(i=0;i<n;i++)
    {
        if(!IsSimbol(plain[i]))
        {
            if(a==strlen(key))
            {
                a=0;
            }
            //printf("\n a=%d",ChartoInt(key[a]));
            //printf("\n i=%d",ChartoInt(plain[i]));
            e= ((ChartoInt(plain[i])+ChartoInt(key[a]))%26);
            //printf("\nhasil= %d",e);
            fputc(InttoChar(e), file2);
            a++;
        }
        else
        {
            fputc(plain[i], file2);
        }

    }

}
void Dekripsi()
{
    int i=0,n=0,a=0,e;
    char CC;
    char key[100],cipher[100];
    FILE *file1=fopen("cipher.txt", "r");
    FILE *file2=fopen("plain2.txt", "w");
    printf("masukkan key:");
    scanf("%s",key);
    while(retval!=EOF){

        retval=fscanf(file1, "%c", &CC);
        if(retval==EOF)
            break;
        cipher[n]=CC;
        n++;
    }
    for(i=0;i<n;i++)
    {

        if(!IsSimbol(cipher[i]))
        {
            if(a==strlen(key))
            {
                a=0;
            }
            //printf("\n%d",ChartoInt(key[a]));
            e= (((ChartoInt(cipher[i])+ 26 - ChartoInt(key[a])))%26);
            //printf("\nhasil= %d",e);
            fputc(InttoChar(e), file2);
            a++;

        }
        else
        {
            fputc(cipher[i], file2);
        }
    }

}

