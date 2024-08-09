#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<time.h>
#include<conio.h>
#include <dirent.h>
#include <sys/types.h>

#define MAX_NAME_LENGTH 50
#define MAX_MESSAGE_LENGTH 1000
#define MAX_PATH_LENGTH MAX_PATH

char loginID[MAX_NAME_LENGTH];
char store[MAX_NAME_LENGTH];

void read3(char *acc, int maxLength) {
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
void welcomechat(){
    system("cls");
        printf("\033[32m");
    printf("\r" "-------------------------------");
    printf("\033[1m");
    printf("Welcome to ChatLink");
    printf("-------------------------------\n");
    printf("\033[0m");
}

void setdi() {
    char currentDirectory[MAX_PATH_LENGTH];

    DWORD result = GetCurrentDirectoryA(MAX_PATH_LENGTH, currentDirectory);
    if (result == 0) {
        fprintf(stderr, "Error getting current directory\n");
        exit(EXIT_FAILURE);
    }

    char *lastBackslash = strrchr(currentDirectory, '\\');
    if (lastBackslash == NULL) {
        fprintf(stderr, "Error: Current directory is the root directory\n");
        exit(EXIT_FAILURE);
    }

    *lastBackslash = '\0';

    if (!SetCurrentDirectoryA(currentDirectory)) {
        fprintf(stderr, "Error setting parent directory as current directory\n");
        exit(EXIT_FAILURE);
    }
}

void sendmespert(char open[50]) {
    FILE *openme = fopen(open, "a");
    if (openme == NULL) {
        printf("Error");
        return;
    }

    printf(BHYEL"\nEnter the Message:"BHGRN);
    char mis[MAX_MESSAGE_LENGTH];
    printf("\e[0;36m");
    scanf(" %[^\n]s", mis);
    printf("\033[0m");
    fprintf(openme, "\n%s:  %s\n", store, mis);
    fclose(openme);
    SetCurrentDirectoryA(loginID);
    printf(RES);
        // printf("_______________________________________________________________________________");

}

void sendmes() {
    char mslo[MAX_NAME_LENGTH];
    welcomechat();
    sprintf(mslo, "%s_message", store);

    printf(BHBLU"\n\n\n\n                           Enter the user name:"BHGRN);
    char name[MAX_NAME_LENGTH];
    scanf(" %[^\n]s", name);

    char open[MAX_NAME_LENGTH];
    sprintf(open, "%s@%s", strlwr(name), strlwr(store));
    setdi();

    FILE *openme = fopen(open, "r");
    if (openme == NULL) {
        sprintf(open, "%s@%s", strlwr(store), strlwr(name));
        openme=fopen(open,"r");
        if(openme==NULL){
            openme=fopen(open,"a");
        }else{
            openme=fopen(open,"a");
        }
        
    }else{
        openme=fopen(open,"a");
    }

    printf(BHBLU"                           Enter the Message:"BHGRN);
    char mis[MAX_MESSAGE_LENGTH];
    printf("\e[0;36m");
    printf(BHGRN);
    scanf(" %[^\n]s", mis);
    printf("\033[0m");
    fprintf(openme, "\n%s:  %s\n", store, mis);
    fclose(openme);
    SetCurrentDirectoryA(loginID);

}

void view() {
    welcomechat();
    printf(BHBLU"\n\n\n\n\n                           Enter the user name:"BHGRN);
    char name[MAX_NAME_LENGTH];
    scanf(" %[^\n]s", name);

    char open[MAX_NAME_LENGTH];
    sprintf(open, "%s@%s", strlwr(name), strlwr(store));
    setdi();

    FILE *openme = fopen(open, "r");
    if (openme == NULL) {
        sprintf(open, "%s@%s", strlwr(store), strlwr(name));
        openme=fopen(open,"r");
        if(openme==NULL){
            printf("\033[31m");
            welcomechat();
            printf(RED"\n\n\n\n                            Chat Not Found...!");
                printf("\033[0m");

                    SetCurrentDirectoryA(loginID);
            return;
        }
    }

    char line[MAX_MESSAGE_LENGTH];
    welcomechat();
    printf(BHGRN"                            %s's Chat",name);
    while (fgets(line, sizeof(line), openme) != NULL) {
        printf("\e[0;36m");
        printf("%s", line);
        printf("\033[0m");
    }
    // printf("-------------------------------------------------------------------------------");
    fclose(openme);

    printf(BHYEL"\n Reply..(yes/no)");
    char ch[4];
    scanf(" %[^\n]s", ch);
    if (strcmp(ch, "no") == 0) {
        // printf("_______________________________________________________________________________");

        SetCurrentDirectoryA(loginID);
        return;
    }
    sendmespert(open);
}

void chatlink() {
    system("cls");
            printf(BHYEL"\n\n\n\n\n\n\n\n                                 ChatLink"RES);
            sleep(1);
            printf(BHGRN"\r                                 ChatLink"RES);
            sleep(1);

    FILE *fname = fopen("name", "r");
    if (fname == NULL) {
        printf("Error opening file 'name'\n");
        return;
    }

    fscanf(fname, "%49s", store);
    sprintf(loginID, "%s@travasso.com", strlwr(store));
    fclose(fname);

    while (1) {
        welcomechat();
        printf(BHGRN"\n\n\n\n\n\n                     1. Send a Message               2. View Chats");
        printf(BHYEL"\n\n                                      3. Exit\n"RES);
        char choice;
        // scanf("%d", &choice);
        read3(&choice,1);
        printf("\n");
        switch (choice) {
            case '1':
                sendmes();
                // getche();
                break;
            case '2':
                view();
                getche();
                break;
            case '3':
                system("cls");
            printf(BHYEL"\n\n\n\n\n\n\n\n                                 Exiting ChatLink"RES);
            sleep(1);
            printf(BHGRN"\r                                 Exiting ChatLink"RES);
            sleep(1);
                return; // Exit the program

        }
    }
}


