#pragma once

#include <map>
#include "../EzyMacro.h"
#include "../event/EzyEvent.h"
#include "../event/EzyEventType.h"
#include "../constant/EzyCommand.h"
#include "EzyDataHandler.h"
#include "../entity/EzyArray.h"

EZY_NAMESPACE_START_WITH(handler)

class EzyDataHandlers {
protected:
    std::map<constant::EzyCommand, EzyDataHandler*> handlers;
public:
    EzyDataHandlers();
    ~EzyDataHandlers();
    void handle(entity::EzyArray* data);
    void addHandler(constant::EzyCommand cmd, EzyDataHandler* handler);
};

EZY_NAMESPACE_END_WITH