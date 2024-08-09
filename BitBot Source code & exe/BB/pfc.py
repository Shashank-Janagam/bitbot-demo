def average(ls):
    n=len(ls)
    return sum(ls)/n
def sort(ls):
    return sorted(ls)
while True:
    ls=list(map(int,input("Enter the list of numbers: ").split()))
    while True:
        print("1.Sum\n2.Average\n3.sort\n4.Break\n")
        ch=int(input("Enter:"))
        if(ch==1):
            print("Sum is:",sum(ls))
        elif ch==2:
            print("Average is:",average(ls))
        elif ch==3:
            print("Sorted list is:",sort(ls))
        elif ch==4:
            break
    choice=input("Re EEnter the List...?")
    if choice=="no":
        break