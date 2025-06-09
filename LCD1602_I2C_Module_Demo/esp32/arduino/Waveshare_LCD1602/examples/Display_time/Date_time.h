#ifndef __DATE_TIME_H__
#define __DATE_TIME_H__

#include <TimeLib.h>

typedef struct{
    uint16_t year;     // Year 
    uint8_t month;    // Month 
    uint8_t day;      // Day 
    uint8_t dotw;     // Day of the Week 
    uint8_t hour;     // Hour 
    uint8_t min;      // Minute 
    uint8_t sec;      // Second 
}date_time_t;

#endif