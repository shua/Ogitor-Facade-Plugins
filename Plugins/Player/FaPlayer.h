///////////////////////////////////
//
//
//
///////////////////////////////////

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
   #ifdef PLUGIN_EXPORT
     #define PluginExport __declspec (dllexport)
   #else
     #define PluginExport __declspec (dllimport)
   #endif
#else
   #define PluginExport
#endif

using namespace Ogitors;

class PluginExport PlayerControllerEditor: public CBaseEditor 
{
    friend class PlayerControllerEditorFactory;
    
public:
    virtual void  createProperties(OgitorsPropertyValueMap &params);
    virtual TiXmlElement *exportDotScene(TiXmlElement *pParent);
    
protected:
    OgitorsProperty<bool> *mPlayerControlled;
    OgitorsProperty<Ogre::Vector3>     *mSpawnPosition;           //! The position where the player will appear.
    
    PlayerControllerEditor(CBaseEditorFactory *factory);
    virtual ~PlayerControllerEditor();
};

class PluginExport PlayerControllerEditorFactory: public CBaseEditorFactory {
public:
    PlayerControllerEditorFactory(OgitorsView *view = 0);
    virtual ~PlayerControllerEditorFactory() {};
    virtual CBaseEditor *CreateObject(CBaseEditor **parent, OgitorsPropertyValueMap &params);
    virtual void DestroyObject(CBaseEditor *object);
};

extern "C" bool PluginExport dllStartPlugin(void *identifier, Ogre::String& name);

extern "C" bool PluginExport dllGetPluginName(Ogre::String& name);

extern "C" bool PluginExport dllStopPlugin(void);
