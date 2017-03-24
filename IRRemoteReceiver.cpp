#define DEBUG 0

#include "IRRemoteReceiver.h"


static DebugHelper Debug("IRRemoteReceiver");


//int IRRemoteReceiver::COMMAND_RECV_EVENT = EventSource::GenerateEventID(); 
//int IRRemoteReceiver::COMMAND_REPT_EVENT = EventSource::GenerateEventID(); 


void IRRemoteReceiver::Initialize()
{
    Debug.Log("Initialize");
    enableIRIn();
}


void IRRemoteReceiver::Poll()
{
    decode_results results;
  
    // check to see if the receiver has received a command
    if (decode(&results))
    {
        int eventID = COMMAND_REPT_EVENT;
    
        if (results.value != IR_REPEAT)
        {
          eventID = COMMAND_RECV_EVENT;
          _lastValue = results.value;      
        }
        
        Event event(eventID, _lastValue);
        
        // Queue an IR Remote event
        DispatchEvent(&event);
        
        // tell the library we're ready to listen for another command
        resume();
    }
}

