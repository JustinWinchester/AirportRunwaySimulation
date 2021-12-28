#ifndef RUN_WAY_H_
#define RUN_WAY_H_

#include <iostream>
#include<queue>
/* This is the header file that will contain the class "runway" for an airport simulation program and it's vital operation functions, 
	The class contains public and private parts for data encapsulation the private section contains different variable types for 
	calculation of data used in public functions that will provide the user of the program methods for obtaining simulated information. 
	This will include functions such as: Is an airport runway busy, can an airplane take off, can an airplane land, and various other scenario 
	options for the program to function properly, this help in object oriented design acting as the lead file for the .cpp implementations, and
	the main driver program!!!!Program function information reference to Dr. Zhao
  Programmer: Justin Winchester
  Professor : Dr. Chao Zhao 
  Course    : Data Structures
  Program   : Airport runway simulator
  Date      : April 6, 2020!      */
class runway
{
        public:
        runway();//constructor
        bool is_airplane_comming_for_landing();//
        bool is_airplane_comming_for_takeoff();
        bool is_landing();
        bool is_takeoff();
        void one_time_unit();
        bool is_runway_busy();
        void start_takeoff();
        void start_landing();
        void sum_landing_time(int);
        void sum_takeoff_time(int);
        int airplane_landed();
        int airplane_takeoff();
        float average_wait_time_for_landing();
        float average_wait_time_for_takeoff();
	void start(); 
	 
        int cur, next, s_len;
      //  float land_rate, takeoff_rate;

        private:
        float landing_arrivel_rate;//how often to come
        float takeoff_arrivel_rate;//how often to come
        int sum_for_landing;//store total time for landing
        int sum_for_takeoff;//store total time for takeoff
        int land_time;//store time used for landing
        int takeoff_time;//store time used for taking off
        int land_time_left;//store time left for landing
        int takeoff_time_left;//store time left for takeoff
        int takeoff_counter;//store the number of tookeoff
        int landing_counter;//store the number of landed
};
//#include "airrunway.cpp"
#endif

