"""
    This program takes an input that includes the times and
    duration of a schedule and outputs the number of schedules
    that were able to execute without conflict.
"""

schedule_list = {}

for count in range( int( input() ) ):
    input_day, input_duration = ( int( input_data ) for input_data in input().split() )
    
    if input_day in schedule_list: # If the day has a previus entry
        if schedule_list[ input_day ] > input_duration: # But the duration is shorter than the one scheduled
            schedule_list[ input_day ] = input_duration
    else: # This day is free to schedule
        schedule_list.update( { input_day: input_duration } )

monitor_time = min( schedule_list.keys() )
schedule_count = 0

for key in sorted( schedule_list.keys() ): # Iterate though all pairs in schedule_list
    if key >= monitor_time: # If it will fit in the scheduled time
        monitor_time = key + schedule_list[ key ]
        schedule_count += 1
        
    elif monitor_time > key + schedule_list[ key ]: # If it over laps the time but will finish sooner
        monitor_time = key + schedule_list[ key ] # Rescheduling doesn't change the count

print( schedule_count )