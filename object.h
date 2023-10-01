//
// Created by alpha on 23. 9. 30.
//
#ifndef Py_OBJECT_H
#define Py_OBJECT_H
#ifdef __cplusplus
extern "C" {
#endif

    /* Ojbect and type object interface
     *
     * Ojbects are structures allocated on the heap. Special reules apply to the use of objects
     * to ensure they are properly garbage-collected. Ojbects are never allocated statically or on the stack;
     * they must be accessed through special macros and functions only. (Type objects are exceptions to the first rule;
     * the standard types are represented by statically initialized type objects, although work on type/class unification
     * for Python 2.2 madde it possible to have heap-allocated type objects too)
     *
     * An object has a 'reference count' that is increased or decreased when a pointer to the object is copied
     * or deleted; when the reference count reaches zero there are no references to the object left and it can be
     * removed from the heap.
     *
     * An object has a 'type' that determines what it represents and what kind of data it contains.
     * An object's type is fixed when it is created. Types themselves are represented as objects.
     * an object contains a pointer to the corresponding type object. the type itself has a type pointer
     * pointing to the object representing the type 'type', which contains a pointer to itself!
     *
     * Objects do not float around in memory; once allocated an object keeps the same size and address.
     * Objets that must hold variable-size data can contain pointers to variable-size parts of the object. Not all
     * objects of the same type have the same size; but the size cannot change after allocation. (These restrictions are
     * made so a reference to an object can be simply a pointer -- moving an object would require updating all the
     * pointers, and changing an object's size would require moving it if there was another object right next to it.)
     *
     * Objects are always accessed throught pointers of the type 'PyOjbec *'.
     * The type 'PyOjbec' is a structure that only contains the reference count and the type pointer.
     * The actual memory allocated for an object contains other data that can only be accessed after casting the pointer
     * to a pointer to a longer structure type. This longer type must start with the reference count and type fields;
     * the macro PyObject_HEAD should be used for this (to accomodate for future changes). The implementation of a
     * particular object type can cast the object pointer to the proper type and back.
    */

    // Py_DEBUG implies Py_REF_DEBUG.
    #if defined(Py_DEBUG) && !defined(Py_REF_DEBUG)
        # define Py_REF_DEBUG
    #endif

    // PyObject_HEAD defines the initial segment of ever PyObject.

    #define PyObject_HEAD PyObject ob_base;

    /*
     * Immortalization:
     *
     * The following indicates the immortalization strategy depending on the amount of available bits
     * in the reference count field. All strategies are backwards compatible but the specific reference count
     * value or immortalization check might change depending on the specializations for the underlying system.
     *
     * Proper deallocation of immortal instances requires distingushing between statically allocated immortal instances
     * vs those promited by the runtime to be cleanup during runtime finalization
     * The latter should be the only instances that require cleanup during runtime finalization.
     *
     */

    #if SIZEOF_VOID_P > 4
/* In 64+ bit systems, an object will be marked as immortal by setting all of the lower
     * 32 bits of the reference count field, which is equal to; 0xFFFFFFF
     *
     * Using the lower 32 bits makes the value backwards compatible by allowing
     * C-Extensions without the updated checks in Py_INCREF and Py_DECREF to safely increase and decrease
     * the objects reference count. The object wuold lose its immortality, but the execution would still be correct.
     *
     * Refercence count increases will use saturated arithmetic, taking advantage of having all the lower 32 bits
     * set, which will avoid the reference count to go beyond the refcount limit. Immortality check for reference count
     * decreases will be done by checking the bit sign flag in the lower 32 bits.
*/

    #define _Py_IMMORTAL_REFCNT UINT_MAX
    # else

    /*
    In 32 bit systems, an object will be marked as immortal by setting all of the lower 30 bits of the reference
    count field, which is equal to 0x3FFFFFFF

    Using the lower 30 bits makes the value backwards compatible by allowing C-Extensions without the updated checks
    in Py_INCREF and Py_DEREF to safely increase and decrease the objects reference count.
    The object would lose its immortality, but the execution would still be correct.

    Reference count increases and dereases will first go throught an immortality check by comparing
    the reference count field to the immortality reference count.
    */

    #define _Py_IMMORTAL_REFCNT (UINT_MAX >> 2)
    #endif

    // Make all internal uses of PyObject_HEAD_INIT immortal while preserving the C-API expedctation that
    // the refcnt will be se to 1.

#ifdef Py_BUILD_CORE
#define PyObject_HEAD_INIT(type) \
    { \
        {_Py_IMMORTAL_REFCNT},        \
        (type)\
    },
#else
#define PyObject_HEAD_INIT(type) \
{ \
    {                                 \
        {1},                      \
        (type)\
    }                                  \
},
#endif // Py_BUILD_CORE

#define PyVarObject_HEAD_INIT(type, size) \
    {                                         \
        PyObject_HEAD_INIT(type)          \
        (size)\
    },

    /* PyObject_VAR_HEAD defines the initial segment of all variable-size container objects.
     * These end with a declaration of an array with 1 element, but enough space is malloc'ed so that the array
     * actually has room for ob_size elements. Note that ob_size is an element count, not necessarily a byte count
     */

#define PyObject_VAR_HEAD PyVarObject ob_base;
#define Py_INVALID_SIZE (Py_ssize_t)-1

/* Nothing is actually declared to be a PyObject, but every pointer to a Python object can be cast to a PyObject*
 * This is inheritance built by hand. Similary every pointer to a variable-size Python object can, in addition,
 * be cast to PyVarObject *
 */

struct _object {
#if (defined(__GNUC__) || defined(__clang__)) \
        && !(defined __STDC_VERSION__ && __STDC_VERSION__ >= 201112L)
    // On C99 and older, anonymous union is a GCC and clang extension
    __extension__
#endif
#ifdef _MSC_VER
    // Ignore MSC warning C4201: "nonstandard extension used:
    // nameless struct/union"
    __pragma(warning(push))
    __pragma(warning(disable: 4201))
#endif
    union {
        Py_ssize_t ob_refcnt;
#if SIZEOF_VOID_P > 4
        PY_UINT32_T ob_refcnt_split[2];
#endif
    };
#ifdef _MSC_VER
    __pragma(warning(pop))
#endif

    PyTypeObject *ob_type;
};

// Cast argument to PyObject* type.
#define _PyObject_CAST(op) _Py_CAST(PyObject*, (op))

// not fixed size Python Object
typedef struct {
    PyObject ob_base;
    Py_ssize_t ob_size; // Number of items in variable part
} PyVarObject;


// Cast argument to PyVarObject* type.
#define _PyVarObject_CAST(op) _Py_CAST(PyVarObject*, (op))

// Test if the 'x' object is the 'y' object, the same as "x is y" in Python.
PyAPI_FUNC(int) Py_Is(PyObject *x, PyObject *y);
#define Py_Is(x, y) ((x) == (y))

static inline Py_ssize_t Py_REFCNT(PyObject *ob){
    return ob->ob_refcnt;
}

#if !defined(Py_LIMITED_API) || Py_LIMITED_API+0 < 0x030b0000
#  define Py_REFCNT(ob) Py_REFCNT(_PyObject_CAST(ob))
#endif

static inline PyTypeObject* Py_TYPE(PyObject* ob){
    return ob->ob_type;
}
#if !defined(Py_LIMITED_API) || Py_LIMITED_API+0 < 0x030b0000
#  define Py_TYPE(ob) Py_TYPE(_PyObject_CAST(ob))
#endif

PyAPI_DATA(PyTypeObject) PyLong_Type;
PyAPI_DATA(PyTypeObject) PyBool_Type;

// The Py_SET_SIZE() function must be used to set an object size.
static inline Py_ssize_t Py_SIZE(PyObject *ob) {
    assert(ob->ob_type != &PyLong_Type);
    assert(ob->ob_type != &PyBool_Type);
    PyVarObject *var_ob = _PyVarObject_CAST(ob);
    return var_ob->ob_size;
}

#if !defined(Py_LIMITED_API) || Py_LIMITED_API+0 < 0x030b0000
#  define Py_SIZE(ob) Py_SIZE(_PyObject_CAST(ob))
#endif

static inline Py_ALWAYS_INLINE int _Py_IsImmortal(PyObject *op)
{
#if SIZEOF_VOID_P > 4
    return _Py_CAST(PY_INT32_T, op->ob_refcnt) < 0;
#else
    return op->ob_refcnt == _Py_IMMORTAL_REFCNT;
#endif
}
#define _Py_IsImmortal(op) _Py_IsImmortal(_PyObject_CAST(op))

static inline int Py_IS_TYPE(PyObject *ob, PyTypeObject *type) {
    return Py_TYPE(ob) == type;
}
#if !defined(Py_LIMITED_API) || Py_LIMITED_API+0 < 0x030b0000
#  define Py_IS_TYPE(ob, type) Py_IS_TYPE(_PyObject_CAST(ob), (type))
#endif

static inline void Py_SET_REFCNT(PyObject *ob, Py_ssize_t refcnt) {
    /* This immortal check is for code that is unaware of immortal objects
     * The runetime tracks tese objects and we should avoid as much
     * as possible ahving extensions inadvertently chage the refcnt of an immortalized boject
     */
    if ( _Py_IsImmortal(ob)){
        return;
    }
    ob->ob_refcnt = refcnt;
}
#if !defined(Py_LIMITED_API) || Py_LIMITED_API+0 < 0x030b0000
#  define Py_SET_REFCNT(ob, refcnt) Py_SET_REFCNT(_PyObject_CAST(ob), (refcnt))
#endif

static inline void Py_SET_TYPE(PyObject *ob, PyTypeObject *type) {
    ob->ob_type = type;
}
#if !defined(Py_LIMITED_API) || Py_LIMITED_API+0 < 0x030b0000
#  define Py_SET_TYPE(ob, type) Py_SET_TYPE(_PyObject_CAST(ob), type)
#endif

static inline void Py_SET_SIZE(PyVarObject *ob, Py_ssize_t size) {
    assert(ob->ob_base.ob_type != &PyLong_Type);
    assert(ob->ob_base.ob_type != &PyBool_Type);
    ob->ob_size = size;
}
#if !defined(Py_LIMITED_API) || Py_LIMITED_API+0 < 0x030b0000
#  define Py_SET_SIZE(ob, size) Py_SET_SIZE(_PyVarObject_CAST(ob), (size))
#endif

/* Type objects contain a string containing the type name (to help somewhat in debugging),
 * the acllocation parameters (see PyObject_New() and PyObject_NewVar()),
 * and methods for accessing objects of the type. Methods are optional, a nil pointer meaning that particular kind of access is not available for this
 * type. The Py_DEREF() macro uses the tp_dealloc method without checking for a nil pointer; it should always be implemented except if the
 * implementation can gurantee that the reference count will never reach zero( for statically allocated typ objects)
 * the methods for certain type gruops are now contained in separate method blocks.
 *
 */

typedef PyObject * (*unaryfunc)(PyObject *);
typedef PyObject * (*binaryfunc)(PyObject *, PyObject *);
typedef PyObject * (*ternaryfunc)(PyObject *, PyObject *, PyObject *);
typedef int (*inquiry)(PyObject *);
typedef Py_ssize_t (*lenfunc)(PyObject *);
typedef PyObject *(*ssizeargfunc)(PyObject *, Py_ssize_t);
typedef PyObject *(*ssizessizeargfunc)(PyObject *, Py_ssize_t, Py_ssize_t);
typedef int(*ssizeobjargproc)(PyObject *, Py_ssize_t, PyObject *);
typedef int(*ssizessizeobjargproc)(PyObject *, Py_ssize_t, Py_ssize_t, PyObject *);
typedef int(*objobjargproc)(PyObject *, PyObject *, PyObject *);

typedef int (*objobjproc)(PyObject *, PyObject *);
typedef int (*visitproc)(PyObject *, void *);
typedef int (*traverseproc)(PyObject *, visitproc, void *);


typedef void (*freefunc)(void *);
typedef void (*destructor)(PyObject *);
typedef PyObject *(*getattrfunc)(PyObject *, char *);
typedef PyObject *(*getattrofunc)(PyObject *, PyObject *);
typedef int (*setattrfunc)(PyObject *, char *, PyObject *);
typedef int (*setattrofunc)(PyObject *, PyObject *, PyObject *);
typedef PyObject *(*reprfunc)(PyObject *);
typedef Py_hash_t (*hashfunc)(PyObject *);
typedef PyObject *(*richcmpfunc) (PyObject *, PyObject *, int);
typedef PyObject *(*getiterfunc) (PyObject *);
typedef PyObject *(*iternextfunc) (PyObject *);
typedef PyObject *(*descrgetfunc) (PyObject *, PyObject *, PyObject *);
typedef int (*descrsetfunc) (PyObject *, PyObject *, PyObject *);
typedef int (*initproc)(PyObject *, PyObject *, PyObject *);
typedef PyObject *(*newfunc)(PyTypeObject *, PyObject *, PyObject *);
typedef PyObject *(*allocfunc)(PyTypeObject *, Py_ssize_t);

#if !defined(Py_LIMITED_API) || Py_LIMITED_API+0 >= 0x030c0000 // 3.12
typedef PyObject *(*vectorcallfunc)(PyObject *callable, PyObject *const *args,
size_t nargsf, PyObject *kwnames);
#endif

typedef struct {
    int slot; // slot id, see below
    void* pfunc; // function pointer
} PyType_Slot;

typedef struct {
    const char* name;

};

















};