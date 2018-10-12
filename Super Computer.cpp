#include <iostream>
#include <map>

/**This program takes an input that includes the times and
 * duration of a schedule and outputs the number of scheduels
 * that were able to execute without conflict.
 */
 
int main()
{
    std::map<int, int> schedule_list; // Conveniently, this will stay sorted by the first element of the pairs
    int input_count, schedule_count = 0, monitor_time;
    
    std::cin >> input_count; std::cin.ignore();

    for( size_t count = 0; count < input_count; ++count )
    {
        int input_day, input_duration;
        std::cin >> input_day >> input_duration; std::cin.ignore();
        
        // Try to add (input_day, input_duration) to the schedule,
        // If there is already a pair that matches input_day it will return false in the second return parameter
        if( !( schedule_list.emplace( input_day, input_duration ) ).second && schedule_list[ input_day ] > input_duration )
        { // If adding failed and the durration in the schedule is greater than the input_duration
            schedule_list[ input_day ] = input_duration; // Replace with the lower duration
        }
    }

    monitor_time = schedule_list.begin()->first; // Start time at the first of the list
    
    for( std::pair<int, int> key: schedule_list )
    { // Iterate though all pairs in schedule_list
        if( key.first >= monitor_time )
        { // If it will fit in the scheduled time
            monitor_time = key.first + key.second;
            ++schedule_count;
        }
        else if( monitor_time > key.first + key.second )
        { // If it over laps the time but will finish sooner
            monitor_time = key.first + key.second;
        } // Rescheduling doesn't change the count
    }

    std::cout << schedule_count << std::endl;
}