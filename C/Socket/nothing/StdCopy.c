#include <stdio.h>

#define BUF_SIZE 256

int main(int argc, char const *argv[])
{
    FILE *fp1 = NULL;
    FILE *fp2 = NULL;

    char buf[BUF_SIZE] = "\0";

    fp1 = fopen("data.txt", "r");
    fp2 = fopen("temp.txt", "w");

    while (fgets(buf, sizeof(buf),fp1) != NULL)
    {
        fputs(buf, fp2);
    }

    fclose(fp1);
    fclose(fp2);

    return 0;
}
