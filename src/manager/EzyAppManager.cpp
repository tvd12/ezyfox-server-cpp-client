#include "EzyAppManager.h"
#include "../util/EzyMaps.h"
#include "../entity/EzyApp.h"
#include "../logger/EzyLogger.h"

EZY_NAMESPACE_START_WITH(manager)

EzyAppManager::EzyAppManager() {
}

EzyAppManager::~EzyAppManager() {
    clear();
}

void EzyAppManager::addApp(entity::EzyApp* app) {
    mAppList.push_back(app);
    mAppByIds[app->getId()] = app;
    mAppByNames[app->getName()] = app;
}

entity::EzyApp* EzyAppManager::getApp() {
    auto app = (entity::EzyApp*)nullptr;
    if(mAppList.size() > 0)
        app = mAppList[0];
    if(!app)
        logger::log("has no app in zone");
    return app;
}

entity::EzyApp* EzyAppManager::getAppById(int appId) {
    return mAppByIds[appId];
}

entity::EzyApp* EzyAppManager::getAppByName(std::string appName) {
    return mAppByNames[appName];
}

std::vector<entity::EzyApp*> EzyAppManager::getApps() {
    auto answer = util::EzyMaps::getValues<int, entity::EzyApp>(mAppByIds);
    return answer;
}

void EzyAppManager::clear() {
    EZY_SAFE_DELETE_VECTOR(mAppList, entity::EzyApp)
    mAppList.clear();
    mAppByIds.clear();
    mAppByNames.clear();
}

EZY_NAMESPACE_END_WITH
