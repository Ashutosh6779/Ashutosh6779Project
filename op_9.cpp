#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int ct,cp=1,prev_p,prev_arr_tm=-1,pro;

struct Students
{
	char std[5];
	int prior;
	int at;
	int bt;
	int wt;
	int tat;
	int prev_bt;
}

os[10];
	
int first_execution()							//program for first process execution
{	
	int fst_exe=100000;
	for(int i=1;i<=pro;i++)
	{
		if(fst_exe>os[i].at && os[i].prior!=0)
		{
			fst_exe=os[i].at;
			cp=i;
		}
		else if(fst_exe==os[i].at && os[i].prior!=0)
		{
			if(os[cp].prior<os[i].prior)
			{
				cp=i;
			}
			else if(os[cp].prior==os[i].prior)
			{
				if(os[i].bt<os[cp].bt)
				cp=i;
			}
		}
	}
	return fst_exe;
}



int main()
{
	int maxPriority=0,x,sum_of_wt,sum_of_tat;
	cout<<"Enter the number of students : ";
	cin>>pro;
	
	for(int i=1;i<=pro;i++)
	{
		cout<<"\nEnter the " <<i<< " student name: ";
		cin>>os[i].std;
		cout<<"\nEnter "<<i<<" arrival time: ";
		cin>>os[i].at;
		cout<<"\nEnter "<<i<< " burst time: ";
		cin>>os[i].bt;
		os[i].prior=rand()%10+1;
	}
	
	cout<<"\t\t"<<"Input given\n";
	cout<<"Student\tAT\tBT\tprior\n";
	
	for(int i=1;i<=pro;i++)
	{
		cout<<os[i].std<<"\t"<<os[i].at<<"\t"<<os[i].bt<<"\t"<<os[i].prior<<"\n"<<endl;
	}
	cout<<"\t\t"<<"Required Output"<<endl;
	ct=first_execution();
	cout<<"Student\tAT\tBT\tprior\tWT\tTAT\n";
	for(int i=1;i<=pro;i++)
	{
		os[i].prev_bt=os[i-1].bt;
		maxPriority=0;
		cout<<os[cp].std<<" executes"<<endl;
		os[cp].prior=0;
		ct=ct+os[cp].bt;
		os[cp].tat=ct-os[cp].at;
		prev_arr_tm=os[cp].at;
		os[cp].wt=os[cp].tat-os[cp].bt;
		
		{
			prev_p=cp;
			if((x=first_execution())>=prev_arr_tm && x>=ct )
			{
				ct=x;
			}
			else
			{
				cp=prev_p;
				if(i==pro-1)
				{
				}
			}
			for(int j=1;j<=pro;j++)
			{
				if(os[j].at>ct)
				{
					os[j].prior=-1;
					os[j].wt=0;
				}
				else if(os[j].prior!=0)
				{
					os[j].prior=rand()%10+1;;
					if(maxPriority<=os[j].prior && os[j].prior!=0)
					{
						if(maxPriority==os[j].prior)
						{
							if(os[j].at<os[cp].at)
							{
								cp=j;
							}
							else if(os[j].at==os[cp].at)
							{
								if(os[i].bt<os[cp].bt)
								{
									cp=j;
								}
							}
						}
						else
						{
							maxPriority=os[j].prior;
							cp=j;
						}
					}
					os[j].wt=ct-os[j].at;
				}
				cout<<"\n"<<os[j].std<<"\t"<<os[j].at<<"\t"<<os[j].bt<<"\t"<<os[j].prior<<"\t"<<os[j].wt<<"\t"<<os[j].tat<<endl;
			}
			
		}
	}
	sum_of_wt=0;sum_of_tat=0;
	for(int j=1;j<=pro;j++)
	{
		sum_of_wt=sum_of_wt+os[j].wt;
		sum_of_tat=sum_of_tat+os[j].tat;
	}
	cout<<"\nAverage TAT= "<<sum_of_tat/(double)pro;
	cout<<"\nAverage WT= "<<sum_of_wt/(double)pro;
	return 0;
}
