#include "../include/wechat.h"
int main()
{
    int sockfd = Socket(TCPCLIENT);

    int select;
    char ch;
    LoginMenu();
    scanf("%d",&select);
    while((ch = getchar()) != '\n' && ch != EOF);
    switch(select)
    {
        case 1:
            sign_in(sockfd);
            break;
        case 2:
            sign_up(sockfd); 
            break;
        case 3:
            break;
        default:
            printf("\n******************选择错误,请重新选择**************\n");
            LoginMenu(); 
            sign_up(sockfd); 
            break;
    }
    return 0;
}