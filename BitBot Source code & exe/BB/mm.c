#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
void main(){
    
        if(CreateDirectoryA("BITBOT_USERS",NULL))
        printf("ERRorrr");
        if(SetCurrentDirectoryA("BITBOT_USERS"))
        printf("ERRRORRR");
    
}