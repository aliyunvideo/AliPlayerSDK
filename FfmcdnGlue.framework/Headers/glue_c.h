#if !defined(__ALI_FFMPEG_GLUE_H__)
#define __ALI_FFMPEG_GLUE_H__

/*
 * set_mcdn_func(...) is defined and exported in ffmcdn.c
 * In your app, call set_mcdn_func(...) to connect ffmpeg
 * with libglue
 *
 * #include "glue.h"
 * set_mcdn_func(get_mcdn_funcs());
 */

#ifndef ARTC_STATE_DEFINE
#define ARTC_STATE_DEFINE

#define ARTC_VIDEO_CACHE_SIZE  1
#define ARTC_AUDIO_CACHE_SIZE  2
#define ARTC_NET_DOWNLOADSPEED 3
#endif


#if defined(__cplusplus)
extern "C" {
#endif

struct ffmpeg_mcdn_funcs {
    int api_version; // validation. must be 2

    /* configure globaly, before open is called
     * do not change values during an instance is running
     */
    int (* preconfig)(const char *key, const char *val);

    /* open a stream specified by url
     * url:   stream url. artc stream supported for now
     * mode:  "r" for subscribe, "w" for publish
     * return value: handle to the stream. NULL if open failed
     */
    void *(* open)(const char *url, const char *mode);

    /* close the stream
     * handle: returned by open
     */
    void (* close)(void *handle);

    /* runtime control (e.g. get/set parameters)
     * negative return value for error
     */
    long long (* ioctl)(void *handle, const char *cmd, void *arg);

    /* read one frame
     * caller need free the returned frame
     * return value: 1 for one frame read into '*frame'; 0 for try
     *               later; -1 for EOF; or other negative value for
     *               fatal error
     */
    int (* read)(struct mcdn_worker_frame **frame, void *handle);

     /* write one frame. callee free the frame
     * return value: 1 for ok; 0 for try
     *               later; -1 for EOF; or other negative value for
     *               fatal error
      */
    int (* write)(struct mcdn_worker_frame **frame, void *handle);
};

const struct ffmpeg_mcdn_funcs *get_mcdn_funcs();

#if defined(__cplusplus)
}
#endif

#endif /* __ALI_FFMPEG_GLUE_H__ */
