#include "airrunway.h"
#include <assert.h>
#include <cstdlib>

using namespace std;

runway::runway()//Class Constructor
        {
                landing_arrivel_rate =0;
                takeoff_arrivel_rate =0;
                land_time =0;
                takeoff_time =0;
                takeoff_counter = 0;
                landing_counter = 0;
                sum_for_landing = 0;
                sum_for_takeoff = 0;
                land_time_left = 0;
                takeoff_time_left = 0;

        }//Constructor values have been initialized to zero! To clean up values and set them. 

        bool runway::is_airplane_comming_for_landing()
        {
                return (float)rand()/RAND_MAX < landing_arrivel_rate;//Function evaluates if plane is coming for landing by checking if random possiblility is less 
		//than landing the landing arrival rate
        }
        bool runway::is_airplane_comming_for_takeoff()
        {
                return (float)rand()/RAND_MAX < takeoff_arrivel_rate;//Checks for random takeoff possibility!
        }
        bool runway::is_landing()
        {
                return land_time_left > 0;//If an airplane is landing, then there will be no time left in it's landing queue. 
        }
        bool runway::is_takeoff()
        {
                return takeoff_time_left > 0;//Returns true if landing time is not @ zero. 
        }


	 void runway::one_time_unit()
        {
                if(is_landing())
                        land_time_left--;
                if(is_takeoff())
                        takeoff_time_left--; //time unit used to determine time remaining for landing and taking off of planes!
        }

        void runway::start_landing()
        {
                assert(!is_runway_busy());
                land_time_left = land_time; //This function begins the landing of airplane if runway is not busy. 
                cout<<"Landing...\n";
        }
        void runway::start_takeoff()
        {
                assert(!is_runway_busy());
                takeoff_time_left = takeoff_time;//If runway is not busy airplane takeoff time is equated to takeoff time left presuming airplanes ready for takeoff!!
                cout<<"Taking Off...\n";
        }


        bool runway::is_runway_busy()
        {
                if(land_time_left > 0 || takeoff_time_left > 0)
                        return true;//If there is landing or take off time left, yes, true runway is very busy.
                else
                        return  false;//If their are no planes landing or taking off during segment of simulation then it's false runway's not that busy!
        }


        void runway::sum_landing_time(int value)
        {
                landing_counter++;
                sum_for_landing += value;//Increments to store landing time left.
        }
        void runway::sum_takeoff_time(int value)
        {

               takeoff_counter++;
                sum_for_takeoff += value;//Increments taking off time. 
        }

        float runway::average_wait_time_for_landing()
        {
                if(landing_counter > 0)
                return (sum_for_landing / landing_counter);//Gives a general landing wait time.
        }
        float runway::average_wait_time_for_takeoff()
        {
                if(takeoff_counter > 0)
                return (sum_for_takeoff / takeoff_counter);//Gives a general taking off time. 
        }

        int runway::airplane_landed()
        {
                return landing_counter;//Will tell if an airplane has landed by the value of it's counter variable. 
        }
        int runway::airplane_takeoff()
        {
                return takeoff_counter;//Will tell if an airplane has landed by the the vaule of take_off counter variable. 
        }

	void runway::start()//Start Function, will interact with the user taking the user input for the simulation values and simulate the 
			   //arrival, and departure of airplanes on one runway. 
	{        queue <int> landing, takeoff;
 
		char answer[2];

        do
        {
        cout<<"\Enter simulation length: ";
        cin>>s_len;
        cout<<"\nEnter Landing Arrival Rate: ";
        cin >> landing_arrivel_rate;
        cout<<"\nEnter Takeoff Arrival Rate: ";
        cin >>takeoff_arrivel_rate;
        cout<<"\nEnter landing time for an airplane: ";
        cin >> land_time;
        cout<<"\nEnter takeoff time for an airplane: ";
        cin >> takeoff_time;

       // runway mine(land_time, takeoff_time, land_rate, takeoff_rate);

        srand(time(NULL));//Declaration of random time function 

        for( cur = 1; cur < s_len; cur++)//Loop to simulate airplanes using class functions. 
        {
                if(is_airplane_comming_for_landing())
                {
                        cout<<"\nAn Airplane is comming for landing..."<<endl;
                        landing.push(cur);
                }
                if(is_airplane_comming_for_takeoff())

{
                        cout<<"\nAn airplane is comming for taking off..."<<endl;
                        takeoff.push(cur);
                }


                if(!is_runway_busy() && !landing.empty())
                {
			next = landing.front();
                        cout<<endl<<cur<<" "<<next<<endl;
                        landing.pop();//Queue removal of landing item stored in queue. 
                        sum_landing_time(cur - next);
                        start_landing();
                }
                if(!is_runway_busy() && landing.empty() && !takeoff.empty())
                {
                        next = takeoff.front();
                        cout<<endl<<cur<<" "<<next<<endl;
                        takeoff.pop();//Queue removal of takeoff item stored. 
                        sum_takeoff_time(cur - next);
                        start_takeoff();
                }


                one_time_unit();
        }
        cout<<"\n\tREPORTS\n";
        cout<<"\nAirplanes were taken off: "<<airplane_takeoff()<<endl;
        cout<<"\nAirplanes were Landed: "<<airplane_landed()<<endl;
        cout<<"\nAverage waiting for landing: " << average_wait_time_for_landing()<<endl;
        cout<<"\nAverage waiting for taking off: "<<average_wait_time_for_takeoff()<<endl;
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

        }while( tolower(answer[0]) == 'y');//Takes user's answer for repeating program simulation!!
}

			


	
