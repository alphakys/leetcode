////
//// Created by alpha on 23. 10. 2.
////
//#define PY_SSIZE_T_CLEAN
//#include <Python.h>
//
//static PyObject* SpamError;
//
////PyMODINIT_FUNC
////PyInit_spam(void)
////{
////    PyObject* m;
////    m = PyModule_Create(&spammodule);
////    if (m == NULL){
////        return NULL;
////    }
////
////    SpamError = PyErr_NewException("spam.error", NULL, NULL);
////    Py_XINCREF(SpamError);
////    if (PyModule_AddObject(m, "error", SpamError) < 0){
////        Py_XDECREF(SpamError);
////        Py_CLEAR(SpamError);
////        Py_DECREF(m);
////        return NULL;
////    }
////    return m;
////}
//
//static PyObject *
//spam_system(PyObject *self, PyObject *args) {
//    const char *command;
//    int sts;
//
//    if (!PyArg_ParseTuple(args, "s", &command))
//        return NULL;
//    sts = system(command);
//    if (sts < 0){
//        PyErr_SetString(SpamError, "System command failed");
//        return NULL;
//    }
//    return PyLong_FromLong(sts);
//
//}
//
//static PyMethodDef SpamMethods[] = {
//        // the name of the built-in function
//        "system"
//}
//;
//
//static PyMethodDef SpamMethods[] = {
//{
//        // the name of the built-in function
//        "system",
//        // The C function that implements it
//        spam_system,
//        // Combination of METH__XXX flags, which mostly describe
//        // the args expected by C func
//        //When using only METH_VARARGS, the function should expect the Python-level parameters to
//        // be passed in as a tuple acceptable for parsing via PyArg_ParseTuple();
//        // more information on this function is provided below.
//
//        //The METH_KEYWORDS bit may be set in the third field if keyword arguments should
//        // be passed to the function. In this case,
//        METH_VARARGS,
//        "Execute a shell command."
//    },
//    //ml_flags = 0 a value of 0 means that an obsolete(쓸모없는) variant of PyArg_ParseTuple()
//{NULL, NULL, 0, NULL}
//};
//
//static struct PyModuleDef spammodule = {
//    PyModuleDef_HEAD_INIT,
//    "spam", //name of module
//    "", // module documentation, may be NULL
//    -1, // size of per-interpreter state of the module, or -1 if the module keeps state in
//    // global variables
//    SpamMethods
//};
//
//PyMODINIT_FUNC
//PyInit_spam(void)
//{
//    return PyModule_Create(&spammodule);
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
