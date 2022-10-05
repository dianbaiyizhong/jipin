//main.c
#include <jni.h>
#include <Python.h>
#include <stdio.h>
 
#ifndef _Included_main
#define _Included_main
#ifdef __cplusplus
extern "C"
{
#endif
 
#if PY_MAJOR_VERSION < 3
#define MODINIT(name) init##name
#else
#define MODINIT(name) PyInit_##name
#endif
    PyMODINIT_FUNC MODINIT(Simple)(void);
    JNIEXPORT void JNICALL Java_com_lib_Simple_initModule(JNIEnv *env, jobject obj)
    {
        PyImport_AppendInittab("JavaTest", MODINIT(Simple));
        Py_Initialize();
 
        PyRun_SimpleString("import os");
        PyRun_SimpleString("__name__ = \"__main__\"");
        PyRun_SimpleString("import sys");
        PyRun_SimpleString("sys.path.append('./')");
 
        PyObject *m = PyInit_Simple();
        if (!PyModule_Check(m))
        {
            PyModuleDef *mdef = (PyModuleDef *)m;
            PyObject *modname = PyUnicode_FromString("__main__");
            m = NULL;
            if (modname)
            {
                m = PyModule_NewObject(modname);
                Py_DECREF(modname);
                if (m)
                    PyModule_ExecDef(m, mdef);
            }
        }
        PyEval_InitThreads();
    }
 
    JNIEXPORT void JNICALL Java_com_lib_Simple_uninitModule(JNIEnv *env, jobject obj)
    {
        Py_Finalize();
    }
 
    JNIEXPORT jstring JNICALL Java_com_lib_Simple_callPython(JNIEnv *env, jobject obj, jstring string)
    {
        const char *param = (char *)(*env)->GetStringUTFChars(env, string, NULL);
        static PyObject *s_pmodule = NULL;
        static PyObject *s_pfunc = NULL;
        if (!s_pmodule || !s_pfunc)
        {
            s_pmodule = PyImport_ImportModule("JavaTest");
            s_pfunc = PyObject_GetAttrString(s_pmodule, "JNI_API_callPython");
        }
        PyObject *pyRet = PyObject_CallFunction(s_pfunc, "s", param);
        (*env)->ReleaseStringUTFChars(env, string, param);
        if (pyRet)
        {
            jstring retJstring = (*env)->NewStringUTF(env, PyUnicode_AsUTF8(pyRet));
            Py_DECREF(pyRet);
            return retJstring;
        }
        else
        {
            PyErr_Print();
            return (*env)->NewStringUTF(env, "error");
        }
    }
#ifdef __cplusplus
}
#endif
#endif
 