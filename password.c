#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

int main() {
    int trynum = 0;
    char password[] = "12345678";
    int l = strlen(password);
    char input[200] = { 0 };//注意此处要填写数值,否则导致栈空间溢出
    int falsetimes = 0;
    
retry:

    printf("Please input your password.\n");
    scanf("%s", input);
    int ls = strlen(input);

    for (int i = 0; i < l; i++)
    {

        if (ls > l || ls < l || falsetimes != 0)
        {

            if (trynum >= 3)
            {
                printf("Too many error,the account is locked.\n");
                return 0;
            }
            printf("Wrong password,please retry.\n");
            trynum++;
            goto retry;
        }
        
        if (password[i] != input[i]) {
            falsetimes++;
        }
    }

    printf("Accpected , welcome to HUTB");
    return 0;
}
