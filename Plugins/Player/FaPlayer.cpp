
#include "Ogitors.h"
#include "FaPlayer.h"

using namespace Ogre;

PlayerControllerEditor::PlayerControllerEditor(CBaseEditorFactory *factory) : CBaseEditor(factory) {
    mName->init("PlayerController"); 
    mUsesGizmos = false;
    mUsesHelper = false;
}

PlayerControllerEditor::~PlayerControllerEditor() {}

void PlayerControllerEditor::createProperties(OgitorsPropertyValueMap &params) {
    PROPERTY_PTR(mPlayerControlled, "mPlayerControlled", bool, false, 0, 0);
    PROPERTY_PTR(mSpawnPosition, "mSpawnPosition", Ogre::Vector3, Ogre::Vector3::ZERO, 0, 0);
    mProperties.initValueMap(params);
}

TiXmlElement *PlayerControllerEditor::exportDotScene(TiXmlElement *pParent) {
    TiXmlElement *player_controller = pParent->InsertEndChild(TiXmlElement("player_controller"))->ToElement();
    player_controller->SetAttribute("mPlayerControlled", Ogre::StringConverter::toString(mPlayerControlled->get()).c_str());    // light position
    TiXmlElement *pLightPosition = player_controller->InsertEndChild(TiXmlElement("position"))->ToElement();
    pLightPosition->SetAttribute("x", Ogre::StringConverter::toString(mSpawnPosition->get().x).c_str());
    pLightPosition->SetAttribute("y", Ogre::StringConverter::toString(mSpawnPosition->get().y).c_str());
    pLightPosition->SetAttribute("z", Ogre::StringConverter::toString(mSpawnPosition->get().z).c_str());

    return player_controller;
}

PlayerControllerEditorFactory::PlayerControllerEditorFactory(OgitorsView *view) : CBaseEditorFactory(view) {
    mTypeName = "Player Controller Object";
    mEditorType = ETYPE_MOVABLE;
    mAddToObjectList = true;
    mRequirePlacement = true;
    mIcon = "Icons/entity.svg";
    mCapabilities = CAN_CLONE | CAN_DELETE | CAN_DRAG | CAN_UNDO;
    
    AddPropertyDefinition("mPlayerControlled", "Player Controlled", "Will this node be controlled by the Player?", PROP_BOOL);
    AddPropertyDefinition("mSpawnPosition", "Spawn Position", "The position where the Player will appear.", PROP_VECTOR3);
}

CBaseEditor *PlayerControllerEditorFactory::CreateObject(CBaseEditor **parent, OgitorsPropertyValueMap &params) {
    PlayerControllerEditor *object = OGRE_NEW PlayerControllerEditor(this);
  
    OgitorsPropertyValueMap::iterator ni;
    
    if((ni = params.find("init")) != params.end()) {
        OgitorsPropertyValue value = EMPTY_PROPERTY_VALUE;
        value.val = Ogre::Any(CreateUniqueID("PlayerController"));
        params["name"] = value;
        params.erase(ni);
    }
    
    object->createProperties(params);
    object->mParentEditor->init(*parent);
    mInstanceCount++;
    
    return object;
}

void PlayerControllerEditorFactory::DestroyObject(CBaseEditor *object) {
    mInstanceCount--;
}

bool dllStartPlugin(void *identifier, Ogre::String& name) {
    name = "Player Controller Plugin";
    OgitorsRoot::getSingletonPtr()->RegisterEditorFactory(identifier, OGRE_NEW PlayerControllerEditorFactory());
    return true;
}

bool dllGetPluginName(Ogre::String& name) {
    name = "Player Controller Plugin";
    return true;
}

bool dllStopPlugin(void) {
    return true;
}
