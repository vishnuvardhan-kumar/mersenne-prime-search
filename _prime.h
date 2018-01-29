#include <Python.h>

/*
Basic implementation of a PyObject in C
Placeholder for an n-bit integer sieve type in Python3.x

struct PrimeSieveObject {
	HEAD_INIT *PrimeSieve;
	int ExitCode;
}


Idea for implementation of arbitrary bit integers in C

struct NbitInteger {
	unsigned long long pointDisarray;
	unsigned long long *Storage;
	// Pointer to (n) cascading unsigned ints
}

Vishnuvardhan K. 29/1/18

*/

typedef struct {
	PyObject_HEAD
	/* Type-specific fields go here. */
} PrimeSieveObject;

static PyTypeObject PrimeSieveObject = {
	PyObject_HEAD_INIT(NULL)
	0,				/* ob_size        */
	"primetype.Sieve",		/* tp_name        */
	sizeof(PrimeSieveObject),	/* tp_basicsize   */
	0,				/* tp_itemsize    */
	0,				/* tp_dealloc     */
	0,				/* tp_print       */
	0,				/* tp_getattr     */
	0,				/* tp_setattr     */
	0,				/* tp_compare     */
	0,				/* tp_repr        */
	0,				/* tp_as_number   */
	0,				/* tp_as_sequence */
	0,				/* tp_as_mapping  */
	0,				/* tp_hash        */
	0,				/* tp_call        */
	0,				/* tp_str         */
	0,				/* tp_getattro    */
	0,				/* tp_setattro    */
	0,				/* tp_as_buffer   */
	Py_TPFLAGS_DEFAULT,		/* tp_flags       */
	">%20DOC%20<",			/* tp_doc         */
};

PyMODINIT_FUNC
initprimetype(void) 
{
	PyObject* m;

	PrimeSieveObject.tp_new = PyType_GenericNew;
	if (PyType_Ready(&PrimeSieveObject) < 0)
		return;

	m = Py_InitModule3("primetype", NULL,
			   "Extension module that creates an prime sieve type.");
	if (m == NULL)
		return;

	Py_INCREF(&PrimeSieveObject);
	PyModule_AddObject(m, "Prime", (PyObject *)&PrimeSieveObject);
}
