#include <stdio.h>

int main() {
    FILE *fo;
    fo=fopen("file.text","a");
    //fprintf(fo,"%s","hello");
    // char a='y';
    // fputc(a,fo);
    char *text="hello\n";
    fputs(text,fo);
    fclose(fo);
    return 0;
}