
#ifndef ArtpFactory_H
#define ArtpFactory_H

#ifdef __cplusplus
extern "C" {
#endif
    extern const char * ARTP_COMPONENT_NAME;

    typedef void* (*getArtpFactoryType)();
    void* getArtpFactory();

#ifdef __cplusplus
} // extern "C"
#endif

#endif //ArtpFactory_H
