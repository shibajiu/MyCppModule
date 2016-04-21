// Configured by cmake macro C:/s/Slicer-build/bin/code/MyExtension/MyCppModule/Widgets/CMakeLists.txt

#include <PythonQt.h>
#include <Python.h>

//-----------------------------------------------------------------------------
static PyMethodDef PyqSlicerMyCppModuleModuleWidgetsPythonQt_ClassMethods[] = {
{NULL, NULL, 0, NULL}};

//-----------------------------------------------------------------------------
extern "C" { void Q_DECL_EXPORT initqSlicerMyCppModuleModuleWidgetsPythonQt(); }

#ifdef __GNUC__
// Disable warnings related to Py_DECREF() macro
// See http://gcc.gnu.org/onlinedocs/gcc/Diagnostic-Pragmas.html
// Note: Ideally the incriminated functions and macros should be fixed upstream ...
#pragma GCC diagnostic ignored "-Wold-style-cast"
#endif

/* #undef HAS_DECORATOR */

namespace {
//-----------------------------------------------------------------------------
void copyAttributes(PyObject* orig_module, PyObject* dest_module)
{
  PyObject* keys = PyObject_Dir(orig_module);
  if (keys)
    {
    PyObject* key;
    PyObject* value;
    int nKeys = PyList_Size(keys);
    for (int i = 0; i < nKeys; ++i)
      {
      key = PyList_GetItem(keys, i);
      value = PyObject_GetAttr(orig_module, key);
      if (!value)
        {
        continue;
        }
      //printf("%s\n", PyString_AsString(key));
      if (!PyObject_HasAttr(dest_module, key))
        {
        PyObject_SetAttr(dest_module, key, value);
        }
      Py_DECREF((void*)value);
      }
    Py_DECREF(keys);
    }
}
} // end of anonymous namespace

//-----------------------------------------------------------------------------
void initqSlicerMyCppModuleModuleWidgetsPythonQt()
{
  static const char modulename[] = "qSlicerMyCppModuleModuleWidgetsPythonQt";
  PyObject *m;

  m = Py_InitModule((char*)modulename, PyqSlicerMyCppModuleModuleWidgetsPythonQt_ClassMethods);
  extern void PythonQt_init_osm_qSlicerMyCppModuleModuleWidgets(PyObject*);
  PythonQt_init_osm_qSlicerMyCppModuleModuleWidgets(m);

#ifdef HAS_DECORATOR
  extern void initqSlicerMyCppModuleModuleWidgetsPythonQtDecorators();
  initqSlicerMyCppModuleModuleWidgetsPythonQtDecorators();
#endif

  // Since invoking 'PythonQt_init_osm_qSlicerMyCppModuleModuleWidgets', will create
  // the module "PythonQt.qSlicerMyCppModuleModuleWidgets". Let's copy its content into the current module.
  PythonQtObjectPtr currentModule = PyImport_ImportModule((char*)"PythonQt.qSlicerMyCppModuleModuleWidgets");
  if(currentModule.isNull())
    {
    PyErr_SetString(PyExc_ImportError, (char*)"Failed to import PythonQt.qSlicerMyCppModuleModuleWidgets");
    return;
    }
  copyAttributes(currentModule, m);
}
