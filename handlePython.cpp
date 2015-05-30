#include <iostream>
#include "handlePython.h"

/*std::string convertPyString(PyObject *st,int len) {
    std::string ret;
    int i;
    for (i=0;i<len;i++) {
       ret+=st
    }
}*/

int updateImage(PyObject *object,int index, unsigned char *rgb,int x,int y,int colsize,char *descrip) {
  printf("wtf?\n");
  PyObject *func ,*args, *list, *item;
  list=PyTuple_New(x*y*colsize);
  int i;
  for (i=0;i<x*y*colsize;i++) {
    //error check
    item=PyLong_FromLong(rgb[i]);
    PyTuple_SetItem(list,i,item);
    //see http://edcjones.tripod.com/refcount.html
    //don't need to decref the individual items once transfered to tuple
    //Py_DECREF(item);
    }
  
  args=Py_BuildValue("(i,O,s)",index,list,descrip);
  Py_DECREF(list);
  func=PyObject_GetAttrString(object,"updateImage");
  PyEval_CallObject(func,args);

 Py_DECREF(args);
 Py_DECREF(func);
 
   

   //not decrefing item may be a leak... but It is the best option not to decref
   //Py_DECREF(item);
  
  
  
   // PyObject_Print(args,stdout,Py_PRINT_RAW);
    if (args==NULL) printf("yyyy?\n");
    //
  
  printf("way?\n");
  
  
  
  return 0;
}
char * getDesc(PyObject *object, int index){
    //build values for desc function
    PyObject *func, *args;
    args=Py_BuildValue("(i)",index);
    //call object, pray it works
    func=PyObject_GetAttrString(object,"getDescription");
    //make sure these error checks actually work
    char *retchar;
    if (func) {
        PyObject *ret=PyEval_CallObject(func,args);

        //func=PyObject_GetAttrString(object,"getDescLength");
        if (func) {
            retchar=PyUnicode_AsUTF8(ret);
            //PyObject *len= PyEval_CallObject(func,args);
            //int l=PyLong_AsLong(len);
            //return convertPyString(ret,l);
            Py_DECREF(ret);
        }
        else {retchar="";}


    }
    else {retchar="";}
    Py_DECREF(args);
    Py_DECREF(func);
    return retchar;
}

int saveStack(PyObject *object) {
  
  PyObject *func ,*args;
  args=Py_BuildValue("()");
  func=PyObject_GetAttrString(object,"saveStack");
  printf("??\n");
  PyEval_CallObject(func,args);
  Py_DECREF(args);
  Py_DECREF(func);
  return 0;
}
