#pragma once

#include <string>
#include "../EzyMacro.h"

#define NUMBER_OF_COMMANDS 14

EZY_NAMESPACE_START_WITH_ONLY(constant)

enum EzyCommand {
    Error = 10,
    Handshake = 11,
    Ping = 12,
    Pong = 13,
    Disconnect = 14,
    Login = 20,
    LoginError = 21,
    AppAccess = 30,
    AppRequest = 31,
    AppExit = 33,
    AppAccessError = 34,
    PluginInfo = 40,
    PluginRequest = 41
};

static int sCommands[] = {
    Error,
    Handshake,
    Ping,
    Pong,
    Disconnect,
    Login,
    LoginError,
    AppAccess,
    AppRequest,
    AppExit,
    AppAccessError,
    PluginInfo,
    PluginRequest
};

std::string getCommandName(int command);

EZY_NAMESPACE_END_WITH
