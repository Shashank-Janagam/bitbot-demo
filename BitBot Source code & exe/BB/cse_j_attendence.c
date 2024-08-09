#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to check if the year is a leap year or not
int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return 1;
    else
        return 0;
}

const char* monthname(int monthNumber) {
    const char* monthNames[] = {
        "January", "February", "March", "April", "May", "June", "July",
        "August", "September", "October", "November", "December"
    };

    // Validate month number
    if (monthNumber < 1 || monthNumber > 12) {
        return "Invalid Month";
    }

    return monthNames[monthNumber - 1]; // Adjust index to match month number (0-indexed)
}

// Function to get the number of days in a month
int daysInMonth(int month, int year) {
    switch(month) {
        case 1:
        case 3:
        case 5: 
        case 7:
        case 8: 
        case 10:
        case 12: 
            return 31;
        case 4: 
        case 6: 
        case 9: 
        case 11: 
            return 30;
        case 2: 
            if (isLeapYear(year))
                return 29; // Leap year
            else
                return 28; // Not a leap year
        default:
            return -1;
    }
}
int calculateDayOfWeek(int day, int month, int year) {
    if (month < 3) {
        month += 12;
        year--;
    }
    int dayofdate;

    dayofdate = (day + (13 * (month + 1) / 5) + (year % 100) +
        ((year % 100) / 4) + ((year / 100) / 4) + 5 * (year / 100)) % 7;
    return dayofdate;
    
}
float percentage(int pdays,int wdays){
    return pdays*100/wdays;
}


void csej() {
    int year=2024;
    char name[50];
    FILE *fp5=fopen("name","r");
    char c;
        while((c=getc(fp5))!=EOF){
            printf("%c",c);
            // i++;
        }
        rewind(fp5);
    FILE *fp;
    fp=fopen("existing_att","w");
    

    int month, day, weekday;
    int mon=0,tue=0,wed=0,thu=0,fri=0,sat=0,sun=0;
    int startdate=19;
    int enddate;
    int stmonth=2,endmonth;
    //printf("\nEnter Start date in DD/MM formate of 2024 Year : ");
    //scanf("%d/%d",&startdate,&stmonth);
    printf("\nEnter End date in DD/MM formate of 2024 Year   : ");
    scanf("%d/%d",&enddate,&endmonth);
    

    
    

    for (month =stmonth; month <= stmonth; month++) {
        weekday = (year + year/4 - year/100 + year/400 + (13*month + 8)/5 + 1) % 7;
        for (day = startdate; day <= daysInMonth(month, year); day++) {
            
            if(day>=startdate){
            switch(weekday){
                case 0:
                    sun++;
                    break;
                case 1:
                    mon++;
                    break;
                case 2:
                    tue++;
                    break;
                case 3:
                    wed++;
                    break;
                case 4:
                    thu++;
                    break;
                case 5:
                    fri++;
                    break;
                case 6:
                    sat++;
                    break;

            }
            weekday++;
            if (weekday > 6) {
            
                weekday = 0;
            }
            }
        }
        
    
    }
    
    for (month =stmonth+1; month <= endmonth-1; month++) {
      
        weekday = (year + year/4 - year/100 + year/400 + (13*month + 8)/5 + 1) % 7;
        for (day = 1; day <= daysInMonth(month, year); day++) {
        
            switch(weekday){
                case 0:
                    sun++;
                    break;
                case 1:
                    mon++;
                    break;
                case 2:
                    tue++;
                    break;
                case 3:
                    wed++;
                    break;
                case 4:
                    thu++;
                    break;
                case 5:
                    fri++;
                    break;
                case 6:
                    sat++;
                    break;

            }
            weekday++;
            if (weekday > 6) {
                
                weekday = 0;
            }
        }
        
    }
    for (month =endmonth; month <= endmonth; month++) {
      
        // Get the weekday of the first day of the month
        weekday = (year + year/4 - year/100 + year/400 + (13*month + 8)/5 + 1) % 7;
        
      
        }
        
        // Print days of the month
        for (day = 1; day <= enddate; day++) {
            
            if(day<=enddate){
            switch(weekday){
                case 0:
                    sun++;
                    break;
                case 1:
                    mon++;
                    break;
                case 2:
                    tue++;
                    break;
                case 3:
                    wed++;
                    break;
                case 4:
                    thu++;
                    break;
                case 5:
                    fri++;
                    break;
                case 6:
                    sat++;
                    break;

            }
            weekday++;
            if (weekday > 6) {
               
                weekday = 0;
            }
            }
        }
            // printf("\nThere are \n%d Sundays\n%d Mondays\n%d Tuesdays\n%d Wednesdays\n%d Thursdays\n%d Fridays\n%d Saturdays",sun,mon,tue,wed,thu,fri,sat);
        int hdmon=0,hdtue=0,hdwed=0,hdthu=0,hdfri=0,hdsat=0;
        /*printf("\nMonday-");
        scanf("%d",&hdmon);
        printf("\nTuesday-");
        scanf("%d",&hdtue);
        printf("\nWednesday-");
        scanf("%d",&hdwed);
        printf("\nThursday-");
        scanf("%d",&hdthu);
        printf("\nFriday-");
        scanf("%d",&hdfri);
        printf("\nSaturday-");
        scanf("%d",&hdsat);
        */
       for(int i=stmonth;i<=endmonth;i++){
            /*printf("Enter the dates of %s month when there are Holidays\nTo skip to next month type 0\n",monthname(i));
            
            int day;
            while(1){
            scanf("%d",&day);

            if(day==0)
            break;
            else{
            int week=calculateDayOfWeek(day,i,year);
            switch(week){
                case 2:
                    hdmon++;
                    break;
                case 3:
                    hdtue++;
                    break;
                case 4:
                    hdwed++;
                    break;
                case 5:
                    hdthu++;
                    break;
                case 6:
                    hdfri++;
                    break;
                case 0:
                    hdsat++;
                    break;
            }
            }
            }*/
            switch(i){
                case 2:
                        break;
                case 3:
                        hdfri+=3;
                        hdthu++;
                        hdmon++;
                        hdsat++;
                        break;
                case 4:
                        hdtue++;
                        hdthu++;
                        hdwed++;
                        hdfri++;
                        hdsat++;
                        break;
                case 5:
                        break;
                case 6:
                        break;
                case 7:
                        break;

            }
       }

        mon-=hdmon;
        tue-=hdtue;
        wed-=hdwed;
        thu-=hdthu;
        fri-=hdfri;
        sat-=hdsat;

   
    
       int eng=mon+wed+thu;
       int ala=mon+tue+wed+thu+fri;
       int ap=mon+tue+thu+fri+sat;
       int evs=thu+fri+sat;
       int pfc=thu+tue;
       int dsc=wed+thu+sat;
       int dscl=mon;
       int pfcl=sat;
       int apl=wed;
       int ebx=fri;
       int ews=tue;
       // printf("THere are total\n");
       // printf("\n%d eng\n%d ala\n%d ap\n%d evs\n%d pfc\n%d dsc\n%d dscl\n%d pfcl\n%d apl\n%d ebx\n%d ews",eng,ala,ap,evs,pfc,dsc,dscl,pfcl,apl,ebx,ews);
        
        
        
        int amon=0,atue=0,awed=0,athu=0,afri=0,asat=0;

        for(int i=stmonth;i<=endmonth;i++){
            printf("Enter the dates of %s month when you are absent\nTo skip to next month type 0\n",monthname(i));
            
            int day;
            while(1){
            scanf("%d",&day);

            if(day==0)
            break;
            else{
            int week=calculateDayOfWeek(day,i,year);
            switch(week){
                case 2:
                    amon++;
                    break;
                case 3:
                    atue++;
                    break;
                case 4:
                    awed++;
                    break;
                case 5:
                    athu++;
                    break;
                case 6:
                    afri++;
                    break;
                case 0:
                    asat++;
                    break;
            }
            }
            }
            
        }

        int pmon=mon-amon;
        int ptue=tue-atue;
        int pwed=wed-awed;
        int pthu=thu-athu;
        int pfri=fri-afri;
        int psat=sat-asat;

       int peng=pmon+pwed+pthu;
       int pala=pmon+ptue+pwed+pthu+pfri;
       int pap=pmon+ptue+pthu+pfri+psat;
       int pevs=pthu+pfri+psat;
       int ppfc=pthu+ptue;
       int pdsc=pwed+pthu+psat;
       int pdscl=pmon;
       int ppfcl=psat;
       int papl=pwed;
       int pebx=pfri;
       int pews=ptue;
       int total_working_days=mon+tue+wed+thu+fri+sat;
       int total_present_days=pmon+ptue+pwed+pthu+pfri+psat;

    //    printf("\nAccording to CSE-J \n");
        printf("From %d/%d To %d/%d\n",startdate,stmonth,enddate,endmonth);
        char mm;
        while((mm=getc(fp5))!=EOF){
            printf("%c",mm);
            // i++;
        }
        rewind(fp5);
        printf("'s total percentage might be= %.2f%%",percentage(total_present_days,total_working_days));

        printf("\nPercentage in each Subject will be\n");

        printf("\nApplied Physics-     %.2f%%",percentage(pap,ap));
        printf("\nApplied MAthematics- %.2f%%",percentage(pala,ala));
        printf("\nPython-              %.2f%%",percentage(ppfc,pfc));
        printf("\nDSC-                 %.2f%%",percentage(pdsc,dsc));
        printf("\nEVS-                 %.2f%%",percentage(pevs,evs));
        printf("\nEnglish-             %.2f%%",percentage(peng,eng));
        printf("\nDSC LAb-             %.2f%%",percentage(pdscl,dscl));
        printf("\nPFC Lab-             %.2f%%",percentage(ppfcl,pfcl));
        printf("\nApplied Physics LAb- %.2f%%",percentage(papl,apl));
        printf("\nWorkshop -           %.2f%%",percentage(pews,ews));
        printf("\nE BoX Lab-           %.2f%%",percentage(pebx,ebx)); 
        char ll;
        fprintf(fp,"From %d/%d To %d/%d\n",startdate,stmonth,enddate,endmonth);
        while((ll=getc(fp5))!=EOF){
            fprintf(fp,"%c",ll);
            //i++;
        }
        
        fprintf(fp,"'s Total percentage might be= %.2f%%",percentage(total_present_days,total_working_days));
        fprintf(fp,"\nPercentage in each Subject is\n");
        fprintf(fp,"\nApplied Physics-     %.2f%%",percentage(pap,ap));
        fprintf(fp,"\nApplied MAthematics- %.2f%%",percentage(pala,ala));
        fprintf(fp,"\nPython-              %.2f%%",percentage(ppfc,pfc));
        fprintf(fp,"\nDSC-                 %.2f%%",percentage(pdsc,dsc));
        fprintf(fp,"\nEVS-                 %.2f%%",percentage(pevs,evs));
        fprintf(fp,"\nEnglish-             %.2f%%",percentage(peng,eng));
        fprintf(fp,"\nDSC LAb-             %.2f%%",percentage(pdscl,dscl));
        fprintf(fp,"\nPFC Lab-             %.2f%%",percentage(ppfcl,pfcl));
        fprintf(fp,"\nApplied Physics LAb- %.2f%%",percentage(papl,apl));
        fprintf(fp,"\nWorkshop -           %.2f%%",percentage(pews,ews));
        fprintf(fp,"\nE BoX Lab-           %.2f%%",percentage(pebx,ebx));
        //fprintf(fp,"Applied Physics-     %.2f%%\nApplied MAthematics- %.2f%%\nPython-              %.2f%%\nDSC-                 %.2f%%\nEVS-                 %.2f%%\nEnglish-             %.2f%%\nDSC LAb-             %.2f%%\nPFC Lab-             %.2f%%\nApplied Physics LAb- %.2f%%\nWorkshop -           %.2f%%\nE BoX Lab-           %.2f%%",percentage(pap,ap),percentage(pala,ala),percentage(ppfc,pfc),percentage(pdsc,dsc),percentage(pevs,evs),percentage(peng,eng),percentage(pdscl,dscl),percentage(ppfcl,pfcl),percentage(papl,apl),percentage(pews,ews),percentage(pebx,ebx));
        fclose(fp);

    // return 0;
}
    