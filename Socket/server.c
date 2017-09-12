#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>



void sendm(int fd,char *message,int size);                  //傳送訊息給client端
int command_control(int* clientfd,char* receive);
int work(int choice,int clientfd);

int main()
{
    int sockfd;
    int switches=1;
    struct sockaddr_in server;
    char welcome[1024] = "############################\nWelcom to Internet editer\n############################\nThere are some option you can choose below:\n############################\n(C)reate\n(E)dit\n(R)emove\n(L)ist\n(D)ownload\n(E)xit\n############################\nWhich do you want to choose?(C,E,R,L,D,Q)\n";
    char receive[1];
    FILE *fp;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);    //建立socket
    bzero(&server, sizeof(server));                // 初始 structure sockaddr_in 
    server.sin_family = AF_INET;
    server.sin_port = htons(3000);
    server.sin_addr.s_addr = htons(INADDR_ANY);
    bind(sockfd, (struct sockaddr*)&server, sizeof(server));     //指定port
    listen(sockfd, 20);  										//開始listen
    printf("**********SERVER Online**********\n");	
    while(switches==1){													//無限回圈 持續接受client端連線
        int clientfd;
        struct sockaddr_in clientAddr;
        int addrlen = sizeof(clientAddr);
        /* 等待客戶端連線 */
        clientfd = accept(sockfd, (struct sockaddr*)&clientAddr, &addrlen);
        send(clientfd,welcome,sizeof(welcome),0);       		 //發送邀請訊息
        bzero(receive,sizeof(receive));
		int choice=command_control(&clientfd,receive);  		//接收client端的input並辨認要執行哪種功能 最後回傳0~6之間的值 存進choice變數
		switches=work(choice,clientfd);                          //接受choice的值 並實際執行功能 當執行quit時會回傳-1 並關掉server
    }
    printf("**********SERVER Offline**********\n");	
    close(sockfd);
    return 0;

}

int command_control(int* clientfd,char* receive){
	recv(*clientfd,receive,sizeof(receive),0);           //接受client傳送指令
	
	if(*receive =='c'|| *receive=='C'){                  //判斷用戶輸入什麼指令 return特定的數字 
		return 1;
	}
	else if(*receive =='e'||*receive=='E'){
		return 2;
	}
	else if(*receive =='r'||*receive=='R'){
		return 3;
	}
	else if(*receive =='l'||*receive=='L'){
		return 4;
	}
	else if(*receive =='d'||*receive=='D'){
		return 5;
	}
	else if(*receive =='q'||*receive=='Q'){
		return 6;
	}
	else
		return 0;
}



void sendm(int fd,char* message,int len){
	send(fd,message,len,0);             //傳送訊息給client
    bzero(message ,len);                //清空暫存訊息的變數
}

int work(int choice,int clientfd){
	int check=-1;
	FILE *fp;
	switch(choice){
		case 1:{                           //當choice為1 則為創建檔案
			char create[80] ="Create file:Please input name of the file:";   
			sendm(clientfd,create,sizeof(create));          //傳送創建檔案的訊息
			recv(clientfd,create,sizeof(create),0);			//接受client輸入要創建的檔案名
			printf("Client create file:%s\n",create);      
			fp = fopen(create,"w");                         //創建檔案
			if(fp){
				strcpy(create,"Create file success!");        //成功 則傳送創建城東的訊息
				sendm(clientfd,create,sizeof(create));
			}
			else{
				strcpy(create,"Create file fail!");        		//失敗 則傳送創建失敗的訊息
				sendm(clientfd,create,sizeof(create));
			}
			fclose(fp);
			break;
		}


		case 2:{                                  //當choice為2 則是編輯檔案
			char edit[200]= "Edit file:please input name of the file:";
			sendm(clientfd,edit,sizeof(edit));
			recv(clientfd,edit,sizeof(edit),0);      	//接受client輸入要編輯的檔案名
			printf("Client open file:%s\n",edit);
			fp = fopen(edit,"a+");                         //以寫入模式 開啟檔案
			bzero(edit,sizeof(edit));
			strcpy(edit,"Please input words(input :end to quit):");   //傳送訊息 告知使用者可以輸入要填入檔案的訊息 輸入:end時結束編輯
			sendm(clientfd,edit,sizeof(edit));      
			while(1){                              //無窮回圈 接收使用者輸入的訊息
				recv(clientfd,edit,sizeof(edit),0);
				if(!strcmp(edit,":end")){              //如果輸入的訊息 為:end則跳出回圈
					printf("Edit file done!\n");
					break;
				}
				fprintf(fp,"%s\n",edit);           //如果是一般的輸入 則將文字寫入編輯的文字檔
				bzero(edit,sizeof(edit));
			}
    		fclose(fp);                           //關閉檔案
    		break;
		}

		case 3:{                                  //當choice為3 則是刪除檔案
			char removed[50] = "Delete file:Please input name of the file:";
			sendm(clientfd,removed,sizeof(removed));           
			recv(clientfd,removed,sizeof(removed),0);  //接受client輸入要刪除的檔案名
			if(remove(removed)==0){                  //刪除成功remove會回傳0
				strcpy(removed,"Remove success!");       //傳送刪除成功訊息
				sendm(clientfd,removed,sizeof(removed));
			}
			else{
				strcpy(removed,"Remove fail!");             //失敗則傳送刪除失敗的訊息
				sendm(clientfd,removed,sizeof(removed));
			}
			break;
		}

         
		case 4:{             //當choice為4 則是列出目錄下的檔案
			char list[30] = "Document list:\n";
			DIR* dir;
			struct dirent* ptr;
			dir = opendir(".");
			sendm(clientfd,list,sizeof(list));
			while((ptr =readdir(dir)) != NULL){      //將目錄下的檔案名稱一個一個傳送給client
				strcpy(list,ptr->d_name);
				send(clientfd,list,sizeof(list),0);
			}
			close(dir);
			strcpy(list,"-end");           		//傳送完所有檔案名稱則傳送-end
			sendm(clientfd,list,sizeof(list));
			break;
		}
		
		case 5:{ 	 				//當choice為5 則是列出目錄下的檔案
			char down[60]="Download:Please input the file name";
			sendm(clientfd,down,sizeof(down));
			recv(clientfd,down,sizeof(down),0);        //接收使用者輸入要下載的檔案名稱
			fp =fopen(down,"r");                       //嘗試開啟檔案 檢查檔案是否存在 
			if (fp == NULL){
				printf("Can not find the file:%s\n",down);
			}
			else{
				printf("Client download file:%s\n",down);      
				bzero(down,sizeof(down));
				while(fgets(down,50,fp)!=NULL){          //開始一行一行讀取server端檔案的內容 並傳送給client
					sendm(clientfd,down,sizeof(down));
					bzero(down,sizeof(down));
				}
				strcpy(down,"done");                  //傳送完所有內容 則傳送done
				sendm(clientfd,down,sizeof(down));
				printf("End download\n");
			}
			fclose(fp);
			break;
		}

		case 6:{				 //當choice為6 則是離開server
			char quit[30]="Are you sure to exit?(Y/N)";     
			sendm(clientfd,quit,sizeof(quit));       //詢問client是否要離開
			recv(clientfd,quit, sizeof(quit),0);
			if(*quit == 'y'|| *quit =='Y'){            //若用戶回傳y 則代表確定離開
			 	printf("Disconnected!\n");
			 	strcpy(quit,"See you!");
				sendm(clientfd,quit,sizeof(quit));
				close(clientfd);                        //結束傳輸
				return -1;
			}
			break;
		}
		default: {                 //如果都不是現有的指令 則回傳錯誤
			char err[15]="No command!";
			sendm(clientfd,err,sizeof(err));
		}
	}
	return 1;
}
