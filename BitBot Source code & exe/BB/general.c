

void general(){
     int year;
    printf("Enter the year\n");
    scanf("%d",&year);

    int month, day, weekday;
    int mon=0,tue=0,wed=0,thu=0,fri=0,sat=0,sun=0;
    int startdate,enddate;
    int stmonth,endmonth;

    printf("Enter Sem Start date in DD MM format\n");
    scanf("%d %d",&startdate,&stmonth);
    printf("Enter Sem end date in DD MM format\n");
    scanf("%d %d",&enddate,&endmonth);

    for (month =stmonth; month <= stmonth; month++) {
        weekday = (year + year/4 - year/100 + year/400 + (13*month + 8)/5 + 1) % 7;
        for (day = 1; day <= daysInMonth(month, year); day++) {
            
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
    
    for(month =stmonth+1; month <= endmonth-1; month++){
        weekday = (year + year/4 - year/100 + year/400 + (13*month + 8)/5 + 1) % 7;
        for (day=1;day<=daysInMonth(month, year);day++){
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
    for(month=endmonth;month<=endmonth;month++) {
        // Get the weekday of the first day of the month
        weekday = (year + year/4 - year/100 + year/400 + (13*month + 8)/5 + 1) % 7;      
        }
        for (day=1;day<=daysInMonth(month,year);day++){
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

        printf("Enter the number of holidays on \nconsider exam days are holidays\n");
        int hdmon,hdtue,hdwed,hdthu,hdfri,hdsat;
        printf("\nMonday-");
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
        
        mon-=hdmon;
        tue-=hdtue;
        wed-=hdwed;
        thu-=hdthu;
        fri-=hdfri;
        sat-=hdsat;
        
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

        

    //int mon=20,tue=20,wed=20,thu=20,fri=20,sat=20,pmon=2,ptue=2,pwed=2,pthu=2,psat=2,pfri=2;
    char subjects[10][8][50];
    printf("Enter number of subjects\n");
    int n;
    scanf("%d",&n);
    int num[n][4];
    
    
    for(int i=0;i<n;i++){
        printf("\nEnter the %d Subject name\n",i+1);
            char s1[50];
            scanf("%s",s1);
            strcpy(subjects[i][0],s1);
            printf("\nEnter number of classes\n");
            scanf("%d",&num[i][0]);
            printf("\nEnter the days when this class is available\n");
        for(int j=1;j<=num[i][0]+1;j++){
            char s2[10];
            gets(s2);
            strcpy(subjects[i][j],s2);
        }
    }

    for(int i=0;i<n;i++){
        num[i][1]=0;
        for(int j=1;j<num[i][0]+1;j++){
            
            if(strcmp(subjects[i][j],"monday"))
            num[i][1]+=mon;
            else if(strcmp(subjects[i][j],"tuesday"))
            num[i][1]+=tue;
            else if(strcmp(subjects[i][j],"wednesday"))
            num[i][1]+=wed;
            else if(strcmp(subjects[i][j],"thursday"))
            num[i][1]+=thu;
            else if(strcmp(subjects[i][j],"friday"))
            num[i][1]+=fri;
            else if(strcmp(subjects[i][j],"saturday"))
            num[i][1]+=sat;    
            }
        }
        int total_working_days=mon+tue+wed+thu+fri+sat;
        int total_present_days=pmon+ptue+pwed+pthu+pfri+psat;

        for(int i=0;i<n;i++){
            num[i][2]=0;
        for(int j=1;j<num[i][0]+1;j++){
            
            if(strcmp(subjects[i][j],"monday"))
            num[i][2]+=pmon;
            else if(strcmp(subjects[i][j],"tuesday"))
            num[i][2]+=ptue;
            else if(strcmp(subjects[i][j],"wednesday"))
            num[i][2]+=pwed;
            else if(strcmp(subjects[i][j],"thursday"))
            num[i][2]+=pthu;
            else if(strcmp(subjects[i][j],"friday"))
            num[i][2]+=pfri;
            else if(strcmp(subjects[i][j],"saturday"))
            num[i][2]+=psat;          

            }
        }
        printf("\nYour Total percentage might be= %.2f%%",percentage(total_present_days,total_working_days));
        printf("\nPercentages of each subjects are\n");
        for(int i=0;i<n;i++){

            printf("\n%s--------",subjects[i][0]);
                int p=num[i][2];
                int w=num[i][1];
               printf("%.2f%%",percentage(p,w));
               /*printf("/nSubject  PDAYS WDAYS/n");
                printf("/n%d %d",num[i][2],num[i][1]);*/

        }
        // return 0;
}