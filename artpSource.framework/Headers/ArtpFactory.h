
#ifndef ArtpFactory_H
#define ArtpFactory_H

#ifdef __cplusplus
extern "C" {
#endif
    // keep the header for have compatibility with 4.7.x verion
    // could remove later
    extern const char * ARTP_COMPONENT_NAME;
    typedef void* (*getArtpFactoryType)();
    void* getArtpFactory();

#ifdef __cplusplus
} // extern "C"
#endif

#endif //ArtpFactory_H
