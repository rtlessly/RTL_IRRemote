#ifndef _IRRemoteReceiver_H_
#define _IRRemoteReceiver_H_

#include <Arduino.h>
#include <Debug.h>
#include <EventSource.h>
#include <IRremote2.h>


class IRRemoteReceiver : public IRrecv, public EventSource
{
    public: const EVENT_ID COMMAND_RECV_EVENT = (EventSourceID::IRSensor | EventCode::Command); 
    public: const EVENT_ID COMMAND_REPT_EVENT = (EventSourceID::IRSensor | EventCode::CommandRepeat);  

    //****************************************************************************
    // Constructors
    //****************************************************************************
    public: IRRemoteReceiver(int pin=12, int ledPin=13)  : IRrecv(pin, ledPin) { };

    //****************************************************************************
    // Public methods
    //****************************************************************************
    public: void Initialize();

    public: virtual void Poll();

    //****************************************************************************
    // Internal State & Behavior
    //****************************************************************************
    private: unsigned long _lastValue;
};


#define IR_NONE 0

#define IR_CH_MINUS 0xFFA25D
#define IR_CH 0xFF629D
#define IR_CH_PLUS 0xFFE21D

#define IR_PREV 0xFF22DD
#define IR_NEXT 0xFF02FD
#define IR_PLAY 0xFFC23D

#define IR_VOL_MINUS 0xFFE01F
#define IR_VOL_PLUS 0xFFA857
#define IR_VOL_EQ 0xFF906F

#define IR_0 0xFF6897
#define IR_100_PLUS 0xFF9867
#define IR_200_PLUS 0xFFB04F

#define IR_1 0xFF30CF
#define IR_2 0xFF18E7
#define IR_3 0xFF7A85

#define IR_4 0xFF10EF
#define IR_5 0xFF38C7
#define IR_6 0xFF5AA5

#define IR_7 0xFF42BD
#define IR_8 0xFF4AB5
#define IR_9 0xFF52AD

#define IR_REPEAT 0xFFFFFFFF

#endif

