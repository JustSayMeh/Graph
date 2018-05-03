#include "application_Graph.h"
#include "Graph.h"
#include <string.h>
#include <stdio.h>
int process(Graph *, int **);
JNIEXPORT jintArray JNICALL Java_application_Graph_calculate(JNIEnv *env, jobject obj, jobjectArray ver, 
    jintArray ind)
{
    jintArray arr;
    int indl = (*env)->GetArrayLength(env, ind);
    Graph *gp = new_graph(indl);
    jint *indexes = (*env)->GetIntArrayElements(env, ind, NULL), *th;
    for (int i = 0; i < indl; i++)
    {
        arr = (jintArray) (*env)->GetObjectArrayElement(env, ver, i);
		th = (*env)->GetIntArrayElements(env, arr, NULL); 
        gp->verticles[i].ribs_c = indexes[i];
        memcpy(gp->verticles[i].ribs, th, indexes[i] * 4);
    }
    int *ret = NULL;
    int rs = process(gp,  &ret);
    if (rs == 1)
        indl = 0;
    jintArray out_ints = (*env)->NewIntArray(env, indl);
    (*env)->SetIntArrayRegion(env, out_ints, 0, indl, ret);
    return out_ints;
}