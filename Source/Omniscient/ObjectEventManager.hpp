#pragma once
#include <vector>
#include "ODefines.hpp"



namespace OEvent
{
  // Handles connecting and disconnecting of events based on their IDs.
  // This service is provided for objects only, and is not something that 
  // is provided for global functions that are part of the event system.
  class ObjectEventManager
  {
  public:
    // Destructor
    ~ObjectEventManager();

    // Member Functions
    void Connect();
  
  private:
    // Variables
    std::vector<O_ID> connections_;
  };
}
