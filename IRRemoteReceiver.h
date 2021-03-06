#ifndef _IRRemoteReceiver_H_
#define _IRRemoteReceiver_H_

#include <RTL_Stdlib.h>
#include <EventSource.h>
#include <IRremote.h>


class IRRemoteReceiver : public IRrecv, public EventSource
{
    DECLARE_CLASSNAME;
    
    public: static const EVENT_ID COMMAND_RECV_EVENT = (EventSourceID::IRSensor | EventCode::Command); 
    public: static const EVENT_ID COMMAND_REPT_EVENT = (EventSourceID::IRSensor | EventCode::CommandRepeat);  

    //****************************************************************************
    // Constructors
    //****************************************************************************
    public: IRRemoteReceiver(int pin=12, int ledPin=13)  : IRrecv(pin, ledPin) { };

    //****************************************************************************
    // Public methods
    //****************************************************************************
    public: void Begin();

    public: void Initialize() { Begin(); };

    public: void Poll();

    //****************************************************************************
    // Internal State & Behavior
    //****************************************************************************
    private: unsigned long _lastValue;
};

#endif

