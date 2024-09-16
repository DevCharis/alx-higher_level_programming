#include <Python.h>
#include <object.h>
#include <listobject.h>

/**
 * print_python_list_info - Prints basic info about Python lists
 * @p: A PyObject list
 *
 * This function prints the size of the list, the allocated memory,
 * and the type of each element in the list.
 */
void print_python_list_info(PyObject *p)
{
Py_ssize_t size = PyList_Size(p);
Py_ssize_t allocated = ((PyListObject *)p)->allocated;
Py_ssize_t i;

printf("[*] Size of the Python List = %zd\n", size);
printf("[*] Allocated = %zd\n", allocated);

for (i = 0; i < size; i++)
{
PyObject *item = PyList_GetItem(p, i);
printf("Element %zd: %s\n", i, Py_TYPE(item)->tp_name);
}
}
