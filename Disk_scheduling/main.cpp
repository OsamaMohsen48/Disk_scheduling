#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

int initial,NumOF_P,*requests,*sequence,*SCAN_sequance,*CSCAN_sequance,*CLOOK_sequance,*OP_sequance;
/******** First Come First Served *********/
int FCFS(int ini)
{
    int differance=0;
    for(int i=0;i<NumOF_P;i++)
    {
        differance+=abs(ini-requests[i]);
        ini=requests[i];
    }
    return differance;
}
/***** Shortest Seek Time First *******/
int SSTF(int ini)
{
    int s=0,difference=0,diff,minimum,MIN_index;
        int *req;
        req=new int[NumOF_P];
        for(int i=0;i<NumOF_P;i++)
        {
            req[i]=requests[i];
        }
        for(int x=0;x<NumOF_P;x++)
        {
            MIN_index=0;
            minimum=abs(req[MIN_index]-ini);
            for(int i=0;i<NumOF_P;i++)
            {
                diff=abs(req[i]-ini);
                if(req[i]!=1e9&&diff<=minimum)
                {
                    minimum=diff;
                    MIN_index=i;
                }
            }
            difference+=minimum;
            sequence[s++]=req[MIN_index];
            ini=req[MIN_index];
            req[MIN_index]=1e9;

        }
        return difference;

}
/**********End Of SSTF Algorithm ***********/


/****** Function Of Bubble Sort ***********/
void bubbleSort(int arr[], int SZ)
{
   int i, j,temp;
   bool swapped; // if array is sorted
   for (i = 0; i < SZ-1; i++)
   {
     swapped = false;
     for (j = 0; j < SZ-i-1; j++)
     {
        if (arr[j] > arr[j+1])
        {
            temp=arr[j+1];
            arr[j+1]=arr[j];
            arr[j]=temp;
           swapped = true;
        }
     }
     if (swapped == false)
        break;
   }
}

/******* End of Bubble Sort ******/


/************ SCAN Algorithm ***********/
int SCAN(int init)
{
    int distanc=0,start_index,SI=0;
    bool Direction;
    cout<<" \nChoose Your Direction by Enter '1' for right And '0' for left "<<endl;
    cin>>Direction;
    int *req;
    req=new int[NumOF_P];
    for(int i=0;i<NumOF_P;i++)
    {
        req[i]=requests[i];
    }
    bubbleSort(req,NumOF_P);
    for(int i=0;i<NumOF_P;i++)
    {
        if (Direction==1&&req[i]>=init)
        {
            start_index=i;
            for(int j=i;j<NumOF_P;j++)
            {
                distanc+=abs(req[j]-init);
                init=req[j];
                SCAN_sequance[SI++]=req[j];
                 if(j==(NumOF_P-1))
                {
                    distanc+=abs(init-199);
                    init=199;
                }
            }
            start_index--;
            while(start_index>=0)
            {
                distanc+=abs(init-req[start_index]);
                init=req[start_index];
                SCAN_sequance[SI++]=req[start_index];
                start_index--;
            }
            break;
        }
        else if(Direction==0&&req[i]>=init)
        {
            start_index=i;
            for(int j=i-1;j>=0;j--)
            {
                distanc+=abs(init-req[j]);
                init=req[j];
                SCAN_sequance[SI++]=req[j];
                if(j==0)
                {
                    distanc+=abs(init-0);
                    init=0;
                }
            }
            while(start_index<NumOF_P)
            {
                distanc+=abs(init-req[start_index]);
                init=req[start_index];
                SCAN_sequance[SI++]=req[start_index];
                start_index++;
            }
            break;
        }
    }
    return distanc;
}
/***********End Of SCAN Algorithm ***********/


/********** C_SCAN Algorithm *********/

int C_SCAN(int init)
{
    int distance=0,start_index,SI=0;
    bool Direction;
    cout<<"\n Choose Your Direction by Enter '1' for right And '0' for left "<<endl;
    cin>>Direction;
    int *req;
    req=new int[NumOF_P];
    for(int i=0;i<NumOF_P;i++)
    {
        req[i]=requests[i];
    }

    bubbleSort(req,NumOF_P);

    for(int i=0;i<NumOF_P;i++)
    {
        if (Direction==1&&req[i]>=init)
        {
            start_index=i-1;
            for(int j=i;j<NumOF_P;j++)
            {
                distance+=abs(req[j]-init);
                init=req[j];
                CSCAN_sequance[SI++]=req[j];
                 if(j==(NumOF_P-1))
                {
                    distance+=abs(init-199);
                    init=0;
                }
            }
            int c=0;
            distance+=199;
            while(c<=start_index)
            {
                distance+=abs(init-req[c]);
                init=req[c];
                CSCAN_sequance[SI++]=req[c];
                c++;
            }
            break;
        }
        else if(Direction==0&&req[i]>=init)
        {
            start_index=i-1;
            for(int j=i-1;j>=0;j--)
            {
                distance+=abs(init-req[j]);
                init=req[j];
                CSCAN_sequance[SI++]=req[j];
                if(j==0)
                {
                    distance+=abs(init-0);
                    init=199;
                }
            }
            int c=(NumOF_P-1);
            distance+=199;
            while(c>start_index)
            {
                distance+=abs(init-req[c]);
                init=req[c];
                CSCAN_sequance[SI++]=req[c];
                c--;
            }
            break;
        }
    }
    return distance;
}

/********** End Of C_SCAN Algorithm********/


/********** C_LOOK Algorithm *********/

int C_LOOK(int init)
{
    int distance=0,start_index,SI=0;
    bool Direction;
    cout<<"\n Choose Your Direction by Enter '1' for right And '0' for left \n "<<endl;
    cin>>Direction;
    int *req;
    req=new int[NumOF_P];
    for(int i=0;i<NumOF_P;i++)
    {
        req[i]=requests[i];
    }

    bubbleSort(req,NumOF_P);

    for(int i=0;i<NumOF_P;i++)
    {
        if (Direction==1&&req[i]>=init)
        {
            start_index=i-1;
            for(int j=i;j<NumOF_P;j++)
            {
                distance+=abs(req[j]-init);
                init=req[j];
                CLOOK_sequance[SI++]=req[j];
            }
            int c=0;
            while(c<=start_index)
            {
                distance+=abs(init-req[c]);
                init=req[c];
                CLOOK_sequance[SI++]=req[c];
                c++;
            }
            break;
        }
        else if(Direction==0&&req[i]>=init)
        {
            start_index=i-1;
            for(int j=i-1;j>=0;j--)
            {
                distance+=abs(init-req[j]);
                init=req[j];
                CLOOK_sequance[SI++]=req[j];

            }
            int c=(NumOF_P-1);
            while(c>start_index)
            {
                distance+=abs(init-req[c]);
                init=req[c];
                CLOOK_sequance[SI++]=req[c];
                c--;
            }
            break;
        }
    }
    return distance;
}

/********** End Of C_LOOK Algorithm********/


/********* Start Of Optimized Algorithm **********/
int Optimized(int init)
{
    int *req,New_Num=NumOF_P+2,differance=0;
    req=new int[New_Num];
    OP_sequance=new int[New_Num];
    for(int i=0;i<New_Num;i++)
    {
        req[i]=requests[i];
    }
    req[New_Num-2]=0;
    req[New_Num-1]=init;
    bubbleSort(req,New_Num);
    init=req[0];
    for(int i=0;i<New_Num;i++)
    {
        differance+=abs(req[i]-init);
        init=req[i];
        OP_sequance[i]=req[i];
    }

    return differance;


}
/**********End of Optimized algorithm **********/
int main()
{

    int choice;
    cout<<"Enter Initial Head "<<endl;
    cin>>initial;
    cout<<"Enter Number of Requests "<<endl;
    cin>>NumOF_P;
    requests=new int[NumOF_P];
    cout<<"Enter The Requests "<<endl;
    for(int i=0;i<NumOF_P;i++)
        cin>>requests[i];
    while(true)
    {
        cout<<"  Choose an algorithm from these : "<<endl;
        cout<<" 1- First Come First Served  (FCFS) Scheduling.\n";
        cout<<" 2- Shortest Seek Time First (SSTF) Scheduling.\n";
        cout<<" 3- SCAN Scheduling.\n";
        cout<<" 4- Circular Scan (C-SCAN) Scheduling.\n";
        cout<<" 5- Circular LOOK  (C_LOOK) Scheduling.\n";
        cout<<" 6- Optimized Algorithm Scheduling.\n";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"The distance of FCFS is : "<<FCFS(initial)<<endl;
            break;
        case 2:
                sequence=new int[NumOF_P];
                cout<<"The distance of SSTF is : "<<SSTF(initial)<<endl;
                cout<<" And Sequance of SSTF is : ";
                for(int i=0;i<NumOF_P;i++)
                    cout<<" --> "<<sequence[i];
                break;
        case 3:
                SCAN_sequance=new int[NumOF_P];
                cout<<" The Distance of SCAN is :  "<<SCAN(initial)<<endl;
                cout<<" And Sequance of SCAN is : ";
                for(int i=0;i<NumOF_P;i++)
                    cout<<" --> "<<SCAN_sequance[i];
                break;
        case 4:
                CSCAN_sequance=new int[NumOF_P];
                cout<<" The Distance of C_SCAN is :  "<<C_SCAN(initial)<<endl;
                cout<<" And Sequance of C_SCAN is : ";
                for(int i=0;i<NumOF_P;i++)
                    cout<<" --> "<<CSCAN_sequance[i];
                break;
        case 5:
                CLOOK_sequance=new int[NumOF_P];
                cout<<" The Distance of C_LOOK is :  "<<C_LOOK(initial)<<endl;
                cout<<" And Sequance of C_LOOK is : ";
                for(int i=0;i<NumOF_P;i++)
                    cout<<" --> "<<CLOOK_sequance[i];
                break;
        case 6:
                cout<<"The distance of Optimized is : "<<Optimized(initial)<<endl;
                cout<<" And Sequance of Optimized is : ";
                for(int i=0;i<(NumOF_P+2);i++)
                    cout<<" --> "<<OP_sequance[i];
                break;
        default:
            cout<<"  ->( You Entered Invalid Choice ,Please Try again )<- "<<endl;
            break;

        }
        cout<<endl;

    }

    return 0;
}
