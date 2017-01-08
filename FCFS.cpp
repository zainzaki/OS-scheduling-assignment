#include<iostream.h>

class process
{
	float burst_time,wait_time;
	class process *next,*ptr;
	int max;
	public:
	void create();
	void fcfs();
}*front=NULL,*rear=NULL;

void process::create()
{
	cout<<"ENTER THE MAXIMUM NUMBER OF PROCESSES THAT CAN BE IN THE QUEUE ==> ";
	cin>>max;
	class process *new_process;
	for(int i=1;i<=max;i++)
	{
		new_process=new process;
		cout<<"ENTER THE BURST TIME OF THE PROCESS "<<i<<" ==> ";
		cin>>new_process->burst_time;
		if(front==NULL)
		{
			front=new_process;
			ptr=front;
		}
		else
		rear->next=new_process;
		rear=new_process;
	}
}

void process::fcfs()
{
	float avg_waiting_time,total_waiting_time;
	cout<<"PROCESS\tBURST TIME"<<endl;
	for(int i=1;i<=max;i++)
	{
		cout<<"P "<<i<<"\t"<<(ptr->burst_time)<<endl;
		ptr=ptr->next;
	}
	ptr=front;
	ptr->wait_time=0;
	total_waiting_time=0;
	for(i=2;i<=max;i++)
	{
		total_waiting_time=total_waiting_time+(ptr->burst_time);
		ptr=ptr->next;
		ptr->wait_time=total_waiting_time;
	}
	ptr=front;
	total_waiting_time=0;
	for(i=1;i<max;i++)
	{
		ptr=ptr->next;
		total_waiting_time=total_waiting_time+(ptr->wait_time);
	}
	avg_waiting_time=total_waiting_time/max;
	cout<<"AVERAGE WAITING TIME IS ==> "<<avg_waiting_time;
}

void main()
{
	process p;
	p.create();
	p.fcfs();
}