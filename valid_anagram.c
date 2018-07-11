#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(void const *a,void const *b)
{
    return strcmp((char*)a,(char*)b);
}
int isAnagram(char* s,char* t)
{
    char *p;
    int count_s[26]={0};
    int count_t[26]={0};
    int i;
    for(p=s,*p,p++)
        count_s[*p-'a']++;
    for(p=t,*p,p++)
        count_t[*p-'a']++;
    for(i=0;i<26;i++){
        if(count_s[i]!=count_t[i])
            return -1
    }
    return 1;

}



 int main(int argc, char const *argv[]) {
    char a[12]="helloworld\0";
    char b[12]="howudoing\0";
    int t;
    t=isAnagram(a,b);
    puts(a);
    puts(b);
    return 0;
}
