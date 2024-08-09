#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include <unistd.h>
#include<time.h>
#include "cse_j_attendence.c"
#include "general.c"
#include "game.c"
#include "finddetails.c"
#include "PayHub.c"
#include "save.c"
#include "chatlink.c"
#include "test.c"
#include "v1.c"
#include "bmi.c"
#include "hand.c"

#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"  
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"
#define RES "\033[0m"
#define BGRN "\e[1;32m"

#define BHBLK "\e[1;90m"
#define BHRED "\e[1;91m"
#define BHGRN "\e[1;92m"
#define BHYEL "\e[1;93m"
#define BHBLU "\e[1;94m"
#define BHMAG "\e[1;95m"
#define BHCYN "\e[1;96m"
#define BHWHT "\e[1;97m"
void welcome(){
    system("cls");
        printf("\033[32m");
    printf("\r" "-------------------------------");
    printf("\033[1m");
    printf("Welcome to TRAVASSO");
    printf("-------------------------------\n");
    printf("\033[0m");
}




int time_(){
    time_t currenttime;
    struct tm*localTime;
    currenttime=time(NULL);
    localTime=localtime(&currenttime);
    // printf("%d",localTime->tm_hour);
    return localTime->tm_hour;
    
}

void read1(char *acc, int maxLength) {
    int i = 0;
    char ch;
    maxLength++;
  while (i < maxLength - 1 && (ch = _getch()) != '\r') {
        if (ch == '\b' && i > 0) {
            printf("\b \b");
            i--;
        } else {
            acc[i++] = ch;
            printf("%c",ch);
        }
    }
    acc[i] = '\0';
}
char loginID[50];
void signin(){
system("cls");
printf("\033[32m");
    printf("\r" "-------------------------------");
    printf("\033[1m");
    printf("Welcome to TRAVASSO");
    printf("-------------------------------\n");
    printf("\033[0m");
    // printf("\e[0;34m");
            printf("\e[0;36m");
            printf(RES);
printf("\r                         Your GOOD Name Please...");
        char accname1[20],accname1d[20],accname2[20];
        char loginID[50];
        char name[20];
        while(1){        
        printf("\033[1m");
        printf(BHBLU"\n                  First Name      -"RES);
        printf(BGRN);
        scanf("%s",accname1);
        printf(RES);
        strcpy(accname1d,accname1);
        printf(BHBLU"\n                  Last Name       -"RES);
        printf(BGRN);
        scanf("%s",accname2);
        printf(RES);
        printf("\033[4m");
        
        strcpy(name,accname1);
        welcome();
        
        sprintf(loginID, "%s@travasso.com", strlwr(name));

        if(SetCurrentDirectoryA(loginID)){
            // printf("HEllo");
            setdir();
            welcome();
            printf(RED);
            printf("\n              Username Already Exist... Please Choose another One\n");
            printf(RES);
            sleep(1);
        }
        else{
            break;
        }
        }
        welcome();
        printf(BHBLU"\n                      Your LOGIN ID is-  "RES);
        printf(BGRN);
        printf("%s",loginID);
        printf(RES);
        printf("\033[0m");
        printf(YEL);
        printf("\n                           Please Do Remember...\n\n\n");
        sleep(1);
        printf(RES);
        printf("\033[1m");
        printf(YEL"          SET a Password (Must be 8 Characte1rs only and spaces NOT ALLOWED)\n"RES);
        char pass1[20],pass2[20];
       
        while(1){
            printf("\n                         Password      -");
            printf(YEL);
            readPassword(pass1,9);
            printf(RES);
            if(strlen(pass1)!=8){
                printf(RED);
                printf("\r                      Password must be 8 characters only Try again\n");
                        printf(RES);
                continue;
        
            } 
            // printf("\r                          All Right..............\n");
            printf("\r                           Re-Enter      -");
            printf(YEL);
            read1(pass2,8);
            // printf("\n")
            printf(RES);
            if(strcmp(pass1,pass2)==0){
                printf("-All Right-\n");
                break;
            }       
             printf(RED);
            printf("\r                      Passwords didn't MATCH  Please Re-try\n");
                        printf(RES);
        }
        LPCSTR login= loginID;
        if(CreateDirectoryA(loginID,NULL))
        printf(".");
         
        if(SetCurrentDirectoryA(loginID))
        printf(".");
        FILE *acco;
        acco=fopen("logininfo","w");
         if (acco != NULL) {
                
                fprintf(acco, "%s\n", pass1);
               
                fclose(acco);
                acco=fopen("name","w+");
                fprintf(acco,"%s %s",accname1d,accname2);
                fclose(acco);
         }
    system("cls");
    printf("\n\n\n\n\n\n");
    printf("                                      Adding User");
    sleep(1);
    printf(BHYEL"\r                                      Adding User");
    sleep(1);
    printf(BHGRN"\r                                      Adding User");
    sleep(1);
    printf("\r                                      Adding User");
    printf(RES);
    system("cls");
}
        
void bitbot(){
    
    //printf("\033[4m");
    printf("\033[32m");
    printf("\r" "-------------------------------");
    printf("\033[1m");
    printf("Welcome to TRAVASSO");
    printf("-------------------------------\n");
    printf("\033[0m");
    // printf("\e[0;34m");

    FILE *sc=fopen("Speed Test Scoor","r");
    if(sc==NULL){
        sc=fopen("Speed Test Scoor","w");
        int zero=0;
        fprintf(sc,"%d",zero);
        fclose(sc);
    }
    printf(BHBLU);
    printf("\n");
    printf("                                      LOGIN                  \n");
    printf("                                     SIGN UP                 \n");
    printf("\033[0m");
    char acc[4];
    
    read1(acc,5);
    printf("\r");
        // printf("\n");

    if(strcmp(acc,"login")==0||strcmp(acc,"LOGIN")==0||strcmp(acc,"Login")==0){
        char password[20];
        welcome();
    // printf("\e[0;34m");
            printf("\e[0;36m");
        int flag=1;
               int att=0;
        while(att<3){
            printf("\033[1m");
        printf(BHBLU"\n                          LOGIN ID-");
        printf("\033[32m");
        printf(RES);
            printf("\033[32m");
            printf("\033[4m");
            printf("\033[1m");

        // scanf("%s",loginID);
        gets(loginID);
        strlwr(loginID);
        printf("\033[0m");
        
        if(SetCurrentDirectoryA(loginID))
            break;
        if(att==2){
            printf("\033[31m");
            welcome();
        printf(RED "                  Sorry User Not Found... Try Again Later\n");
                printf("\033[0m");
                sleep(3);
                system("cls");

        return;
        }
        
        else{   
                    welcome();
                  
                    
        printf(RED "                          User Not FOUND Please re enter."RES);
        }
        
        att++;
        }
    welcome();

    printf(BGRN"\n                              Connecting User...");
    sleep(1);
    welcome();
        
        FILE *acco=fopen("logininfo","r");
        int attempts=0;
        int flag2=0;
       while(attempts<3){
        
        printf(BHBLU"\n                          PASSWORD-"RES);
        printf("\e[0;33m");
        readPassword(password,9);
        printf("\033[0m");
        char c;
        char stored[20];
        int i=0;
        while(i<8){
            c=getc(acco);
            stored[i]=c;
            i++;          
        }
        rewind(acco);
        int k=0; 
        flag2=0;
        // printf("\033[32m");
        welcome();
        printf(BHGRN);
        printf("\r\n                                 -Verifying-        ");
        sleep(1); 
        printf("\r                              ----Verifying----      ");
        sleep(1);
        printf("\r                           -------Verifying--------    ");
        sleep(1);
        
        printf("\033[0m");
        while(k<8){
             
            if(password[k]!=stored[k]){

                if(stored[k]==' ')
                continue;

                
                attempts++;
                flag2=1;
                if(attempts==3){
                    welcome();
                         printf("\033[1;33m");
                printf("\r                              Sorry Try Again Later\n");
                                printf("\033[0m");
                // flag2=1;
                }
                else if(attempts<3){
                    welcome();
                printf("\033[31m");
                printf("\r""             Wrong Password");
                printf(" Try again.. %d attempt(s) more...",3-attempts);
                printf("\033[0m");
                }
                break;
            
            }
            k++;
        }
        if(flag2==0)
        break;
    }
    if(flag2==1){
    printf("hello");
    sleep(2);
    system("cls");
    return;
    }
    }
    else if(strcmp(acc,"sign ")==0||strcmp(acc,"SIGN ")==0||strcmp(acc,"Sign ")==0)
    {
        signin();
        
    }
    else{
        system("cls");
        return;
    }
    
        // printf("\033[0m");
    welcome();
    printf(BGRN"\n\n                           Login Successfully" RES);
    sleep(1);
    

    while(1){
        welcome();
    printf("\r");
        char c;
        char greet[50];
        // int i=0;       
        FILE*acco;
    acco=fopen("name","r");
    // printf("\n");
        printf("\033[32m");

        printf("\033[1m");
        int curtime=time_();
        printf("                   ");
        if(curtime<=11)
        printf("Good Morning..!");
        else if(curtime<=17)
        printf("Good AfterNoon..!");
        else if(curtime<=21)
        printf("Good Evening..!");
        else
        printf("Good Night...!");
        printf("\t");
        printf("\033[32m");
        while((c=getc(acco))!=EOF){
            printf("%c",c);
            // i++;
        }
        printf("\033[0m");
        printf("\n"); 
        printf("\033[0m");
        fclose(acco);
        // welcome();
    printf(BGRN"\n\n                            Travasso Offers-"RES);
    printf("\n\n");
    printf(BHCYN"\n                   1.PayHub                        2.Attendence Calculation\n\n");
    printf("                   3.Games                         4.Existing Attendence DATA\n\n");
    printf("                   5.ChatLink                      6.TypePro\n");
    printf("\n                   7Stop Watch\n");
    printf("\n");
    printf(BHYEL"                                  8.Logout\n"RES);
    char s;
    char s1[10];
    read1(&s,1);
    printf("\n");
    switch(s){
        case '1':
            
            welcomepay();
            // printf("Welcome To Travasso's PayHub\n");
            PAYHUB();
            break;
        case '2':
            printf("Intrested To know your percentage..!");
            printf("Are You a student of CSE J\n");
            read1(s1,3);
                printf("\n");

            if(strcmp(s1,"yes")==0||strcmp(s1,"YES")==0||strcmp(s1,"Yes")==0){
            csej();
            getche();
            }
            else
            general();
            break;
        case '3':
            while(1){welcome();
            printf("\n1.Rock Paper Scissors\t\t\t2.Save The Kid\n3.BMI( Body Mass Index)\t\t\t4.Hand Cricket");
            char s2;
            read1(&s2,1);
            
            switch(s2){
                case '1':
                    welcome();
                    gamemain();
                    getche();
                    break;
                case '2':
                welcome();
                    save_kid();
                    getche();
                    break;
                case '3':
                    welcome();
                    bmi();
                    getche();
                    break;
                case '4':
                    welcome();
                    hand();
                    getche();
                    break;
            } 
            printf("Exit Games...(Stay/Exit)");
            read1(s1,4);
                printf("\n");

            if(strcmp(s1,"exit")==0||strcmp(s1,"Exit")==0||strcmp(s1,"EXIT")==0)
            break;
            }
            break;
        case '4':
            printf("\nExisting data are as Follows\n");
            find();
            getche();
            break;
        case '5':
            chatlink();
            break;
        case '6':
            test();
            getche();
            break;
        case '7':
            welcome();
            stop();
            welcome();
            break;

        case'8':
            system("cls");
            printf(BHYEL"\n\n\n\n\n\n\n\n                                 Signing Off"RES);
            sleep(1);
            printf(BHGRN"\r                                 Signing Off"RES);
            sleep(1);
            setdir();
            system("cls");
            return;
    }
    }

}
void main(){
    system("cls");
    if(SetCurrentDirectoryA("BITBOT_USERS")){
        
    }else{
        if(CreateDirectoryA("BITBOT_USERS",NULL)){
            printf("");
        }
        SetCurrentDirectoryA("BITBOT_USERS");
    }
    while(1)
    bitbot();
}