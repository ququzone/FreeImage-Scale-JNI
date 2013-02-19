#include <jni.h>
#include "ImageScale.h"
#include "FreeImage.h"

JNIEXPORT jint JNICALL Java_ImageScale_imageScale
  (JNIEnv *env, jobject obj, jstring jsrc, jstring jdest, jint new_width) {
#ifdef FREEIMAGE_LIB
    FreeImage_Initialise();
#endif
    int result = 1;
    const char *src = (*env) -> GetStringUTFChars(env, jsrc, 0);
    const char *dest = (*env) -> GetStringUTFChars(env, jdest, 0);
    FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;

    fif = FreeImage_GetFileType(src, 0);
    if(fif == FIF_UNKNOWN) {
        fif = FreeImage_GetFIFFromFilename(src);
    }
    if((fif != FIF_UNKNOWN) && FreeImage_FIFSupportsReading(fif)) {
        FIBITMAP *dib = FreeImage_Load(fif, src, 0);
        int originalWidth = 0;
        int originalHeight = 0;
        float rate = 1.0;
        if(!dib)
            return 1;
        originalWidth = FreeImage_GetWidth(dib);
        originalHeight = FreeImage_GetHeight(dib);
        if(originalWidth > new_width) {
            rate = ((float) new_width) / originalWidth;
        }
        FIBITMAP *ndib = FreeImage_Rescale(dib, (int)(originalWidth * rate),
                (int)(originalHeight * rate), FILTER_BOX);
        if(ndib) {
            if(FreeImage_Save(fif, ndib, dest, 0))
                result = 0;
            FreeImage_Unload(ndib);
        }
        FreeImage_Unload(dib);
    }

#ifdef FREEIMAGE_LIB
    FreeImage_DeInitialise();
#endif
    return result;
}

int main(void) {
    return 0;
}
