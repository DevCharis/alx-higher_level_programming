#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <stdio.h>
#include "103-python.h"

/**
 * print_python_bytes - Prints information about a Python bytes object.
 * @p: A pointer to the Python bytes object.
 *
 * If p is not a valid PyBytesObject, prints an error message.
 * Prints the size, string representation, and the first up to 10 byt
 */
void print_python_bytes(PyObject *p)
{
Py_ssize_t size, i;
const char *str;
if (!PyBytes_Check(p))
{
printf("[ERROR] Invalid Bytes Object\n");
return;
}
size = PyBytes_Size(p);
str = PyBytes_AsString(p);
printf("[.] bytes object info\n");
printf("  size: %ld\n", size);
printf("  trying string: %s\n", str);
if (size >= 10)
size = 10;
printf("  first %ld bytes: ", size);
for (i = 0; i < size; i++)
{
printf("%02x", (unsigned char) str[i]);
if (i + 1 < size)
printf(" ");
}
printf("\n");
}

/**
 * print_python_list - Prints information about a Python list object.
 * @p: A pointer to the Python list object.
 *If p is not a valid PyListObject, prints an error message.
 * Prints the size, allocated space, and each element's type.
 * If an element is a bytes object, calls prin its details.
 */
void print_python_list(PyObject *p)
{
Py_ssize_t size, allocated, i;
if (!PyList_Check(p))
{
printf("[ERROR] Invalid List Object\n");
return;
}
size = PyList_Size(p);
allocated = ((PyListObject *)p)->allocated;
printf("[*] Python list info\n");
printf("[*] Size of the Python List = %ld\n", size);
printf("[*] Allocated = %ld\n", allocated);
for (i = 0; i < size; i++)
{
PyObject *item = PyList_GetItem(p, i);
printf("Element %ld: %s\n", i, Py_TYPE(item)->tp_name);
if (PyBytes_Check(item))

print_python_bytes(item);

}
}
