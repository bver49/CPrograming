#include <sys/types.h>         
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void sendm(int fd,char *message,int len);
void command_control(char *choose,int fd);

int main(int argc, char* const argv[])
{
    int sockfd;
    struct sockaddr_in server;
	char message[1024];
	char choose[1];
    bzero(message,sizeof(message));
	bzero(choose,sizeof(choose));
    /* create socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(3000);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
	if(connect(sockfd, (struct sockaddr*)&server, sizeof(server))<0){   //確定是否連上server端
		printf("Can't connect!\n");
		exit(1);
	}
    recv(sockfd, message, sizeof(message),0);    //接受server端的welcome訊息
    printf("%s\n", message);                    //印出訊息內容
    scanf("%c",choose);                        //接收使用者輸入指令
	printf("Your choice: %c\n",*choose);
	send(sockfd,choose,sizeof(choose),0);       //傳送指令
	command_control(choose,sockfd);              //執行client端的指令
	close(sockfd);

    return 0;
}

void sendm(int fd,char message[],int len){
	send(fd,message,len,0);
    bzero(message,len);
}


void command_control(char *choose,int sockfd){
	if(*choose =='c'||*choose=='C'){                   //如果輸入的是c則代表創建檔案
        char create[80] ;  
		bzero(create,80);
        recv(sockfd, create, sizeof(create),0);
    	printf("%s", create);
        bzero( create,sizeof(create) );
		scanf("%s",create);                        //接收要創建的檔案名稱
		printf("The file name is: %s\n",create);
        sendm(sockfd,create,sizeof(create));		//傳送要創建的檔案名稱
        recv(sockfd, create, sizeof(create),0);      //接受創建是否成功的訊息
        printf("%s\n",create);
    }

	else if(*choose =='e'||*choose=='E'){		//如果輸入的是e則代表編輯檔案
        char edit[200] ;
		bzero(edit,200);
    	recv(sockfd,edit, sizeof(edit),0);
    	printf("%s\n",edit);
        bzero( edit,sizeof(edit));
		scanf("%s",edit);        		//接收要編輯的檔案名稱
		printf("The file name is: %s\n",edit);
        sendm(sockfd,edit,sizeof(edit));
        recv(sockfd,edit,sizeof(edit),0);
        printf("%s\n",edit);
        bzero(edit,sizeof(edit));  
		while(1){                         //無窮回圈 讓client一直輸入要填入的內容 直到輸入:end
			gets(edit);                    
			send(sockfd,edit,sizeof(edit),0);
			if(!strcmp(edit,":end")){        //比對目前輸入的是否為:end
				break;
			}
        	bzero(edit,sizeof(edit));
		}
    	printf("Edit done\n");

    }

	else if(*choose =='r'|| *choose=='R'){      //如果輸入的是r則代表刪除檔案
        char removed[50] ;
		bzero(removed,50);
    	recv(sockfd, removed, sizeof(removed),0);
    	printf("%s\n", removed);
        bzero(removed,sizeof(removed));
		scanf("%s",removed);                 //接受要刪除的檔案名稱
		printf("The file name is: %s\n",removed);
        sendm(sockfd,removed,sizeof(removed));
        recv(sockfd,removed,sizeof(removed),0);  //接受 檔案是否刪除成功的訊息
        printf("%s\n",removed);
    }


	else if(*choose =='l'||*choose =='L'){ 	//如果輸入的是l則代表列出server端的檔案列表
		char list[30];
		bzero(list,30);
		while(1){                        //無窮回圈 開始接收server端的檔案名稱
    		recv(sockfd, list, sizeof(list),0);
			if(!strcmp(list,"-end")){       //如果接受到的內容為-end則代表 已經列出所有檔案 則可以結束回圈
				break;
			}
    		printf("%s\n", list);            //一一的列出檔案名稱
        	bzero( list,sizeof(list) );
		}
	}
	


	else if(*choose =='d'|| *choose =='D'){   //如果輸入的是d則代表下載檔案
		char down[60];
		FILE* fp;
		bzero(down,sizeof(down));
		recv(sockfd,down,sizeof(down),0);
    	printf("%s\n",down);
        bzero( down,sizeof(down) );
		scanf("%s",down);                 //輸入要下載的檔案名稱
        send(sockfd,down,sizeof(down),0);
		fp = fopen(down,"wb");              //以寫入模式創建檔案
		if(fp == NULL ){
			printf("Can not open the file\n");
			exit(1);
		}
        bzero(down,sizeof(down));
    	while(1){                                  //無窮回圈 用來接受server端檔案的內容 並一行行寫入client端的檔案
			recv(sockfd, down ,sizeof(down), 0);
			if(!strcmp(down,"done"))
				break;
			fprintf(fp,"%s\n",down);
        	bzero(down,sizeof(down));	
		}
		printf("Receive file\n");
		fclose(fp);
	}

	else if(*choose =='q'||*choose =='Q'){ 	//如果輸入的是q則代表離開server
		char quit[30];
		bzero(quit,30);
    	recv(sockfd, quit, sizeof(quit),0);
    	printf("%s\n", quit);
        bzero( quit,sizeof(quit));
		scanf("%s",quit);                   //讓使用者輸入是否離開並關閉server
        sendm(sockfd,quit,sizeof(quit));
    	recv(sockfd, quit,sizeof(quit),0);
    	printf("%s\n",quit);
	}
	else{                           //如果都不是現有的指令 則印出error
		char err[15];
		bzero(err,15);
		recv(sockfd,err,sizeof(err),0);
		printf("%s\n",err);
	}
}
