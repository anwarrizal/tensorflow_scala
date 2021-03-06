/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class org_platanios_tensorflow_jni_CheckpointReader__ */

#ifndef _Included_org_platanios_tensorflow_jni_CheckpointReader__
#define _Included_org_platanios_tensorflow_jni_CheckpointReader__
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     org_platanios_tensorflow_jni_CheckpointReader__
 * Method:    newCheckpointReader
 * Signature: (Ljava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_org_platanios_tensorflow_jni_CheckpointReader_00024_newCheckpointReader
  (JNIEnv *, jobject, jstring);

/*
 * Class:     org_platanios_tensorflow_jni_CheckpointReader__
 * Method:    debugString
 * Signature: (J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_org_platanios_tensorflow_jni_CheckpointReader_00024_debugString
  (JNIEnv *, jobject, jlong);

/*
 * Class:     org_platanios_tensorflow_jni_CheckpointReader__
 * Method:    hasTensor
 * Signature: (JLjava/lang/String;)B
 */
JNIEXPORT jboolean JNICALL Java_org_platanios_tensorflow_jni_CheckpointReader_00024_hasTensor
  (JNIEnv *, jobject, jlong, jstring);

/*
 * Class:     org_platanios_tensorflow_jni_CheckpointReader__
 * Method:    getTensor
 * Signature: (JLjava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_org_platanios_tensorflow_jni_CheckpointReader_00024_getTensor
  (JNIEnv *, jobject, jlong, jstring);

/*
 * Class:     org_platanios_tensorflow_jni_CheckpointReader__
 * Method:    delete
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_org_platanios_tensorflow_jni_CheckpointReader_00024_delete
  (JNIEnv *, jobject, jlong);

#ifdef __cplusplus
}
#endif
#endif
