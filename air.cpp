#include <time.h>
#include "runway.h"
#include <queue>
#include <stdlib.h>

using namespace std;

int main()
{
	queue <int> landing, takeoff;
	int cur, next, land_time, takeoff_time, s_len;
	float land_rate, takeoff_rate;
	char answer[2];

	do
	{
	cout<<"\Enter simulation length: ";
	cin>>s_len;
	cout<<"\nEnter Landing Arrival Rate: ";
	cin >>land_rate;
	cout<<"\nEnter Takeoff Arrival Rate: ";
	cin >>takeoff_rate;
	cout<<"\nEnter landing time for an airplane: ";
	cin >> land_time;
	cout<<"\nEnter takeoff time for an airplane: ";
	cin >> takeoff_time;

 	runway mine(land_time, takeoff_time, land_rate, takeoff_rate);

	srand(time(NULL));

	for( cur = 1; cur < s_len; cur++)
	{
		if(mine.is_airplane_comming_for_landing())
		{
			cout<<"\nAn Airplane is comming for landing..."<<endl;
			landing.push(cur);
		}
		if(mine.is_airplane_comming_for_takeoff())
		{
			cout<<"\nAn airplane is comming for taking off..."<<endl;
			takeoff.push(cur);
		}


		if(!mine.is_runway_busy() && !landing.empty())
		{
			next = landing.front();
			cout<<endl<<cur<<" "<<next<<endl;
			landing.pop();
			mine.sum_landing_time(cur - next);
			mine.start_landing();
		}
		if(!mine.is_runway_busy() && landing.empty() && !takeoff.empty())
		{			
			next = takeoff.front();
			cout<<endl<<cur<<" "<<next<<endl;
			takeoff.pop();
			mine.sum_takeoff_time(cur - next);
			mine.start_takeoff();
		}
		

		mine.one_time_unit();
	}
	cout<<"\n\tREPORTS\n";
	cout<<"\nAirplanes were taken off: "<<mine.airplane_takeoff()<<endl;
	cout<<"\nAirplanes were Landed: "<<mine.airplane_landed()<<endl;
	cout<<"\nAverage waiting for landing: " << mine.average_wait_time_for_landing()<<endl;
	cout<<"\nAverage waiting for taking off: "<<mine.average_wait_time_for_takeoff()<<endl;
	cout<<"\nUnlanded airplanes: "<<endl;
	int cnt_landing = 0;
	while(!landing.empty())
	{
		cout<<landing.front()<<" ";
		cnt_landing ++;
		landing.pop();
	}
	cout<<endl<<cnt_landing<<" airplanes were denied for landing."<<endl<<endl;
	int cnt_takeoff = 0;

	while(!takeoff.empty())
	{
		cout<<takeoff.front()<<" ";
		cnt_takeoff ++;
		takeoff.pop();
	}
	cout<<endl<<cnt_takeoff<<" airplanes were denied for takeoff."<<endl;

	cout<<"\nDo it again y for yes: ";
	cin >> answer;
	cout<<endl<<endl;

	}while( tolower(answer[0]) == 'y');




 }
