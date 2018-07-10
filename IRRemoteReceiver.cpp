#define DEBUG 0

#include<Arduino.h>
#include <RTL_Debug.h>

#include "IRRemoteReceiver.h"


DEFINE_CLASSNAME(IRRemoteReceiver);


void IRRemoteReceiver::Begin()
{
    TRACE(Logger(_classname_, this)  << F(":Begin, pin=") << (int)irparams.recvpin << endl);
    enableIRIn();
}


void IRRemoteReceiver::Poll()
{
    TRACE(Logger(_classname_, this) << F(":Poll") << endl); 
    decode_results results;

    // check to see if the receiver has received a command
    if (decode(&results))
    {
        TRACE(Logger(_classname_, this) << F(":Poll, decoded=") << _HEX(results.value)  << endl);

        int eventID = COMMAND_REPT_EVENT;

        if (results.value != IR_REPEAT)
        {
          eventID = COMMAND_RECV_EVENT;
          _lastValue = results.value;
        }

        // Queue an IR Remote event
        if (!results.overflow) QueueEvent(eventID, _lastValue);

        // tell the library we're ready to listen for another command
        resume();
    }
}

