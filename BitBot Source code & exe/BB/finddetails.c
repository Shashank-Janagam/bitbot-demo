#include<stdio.h>
#include<stdlib.h>
void find(){
    FILE *fp;
    char line[100];
    fp=fopen("existing_att","r");
    if(fp==NULL){
        printf("No Details found\nCheck weather you calculated in BIBOT\n");
    }
    else{
    //  printf("Student details found");
        fp=fopen("existing_att","r");
        while(fgets(line, sizeof(line),fp)!=NULL){
            printf("%s",line);
        }
        fclose(fp);
    }
    
}