#include "drawstack.h"

void drawStack::initialize(const char **name) {
    rgb=(unsigned char *)malloc(sizeof(unsigned char));

    initializePython(name);
    newFrame();
    printf("FILE: %s\n",*name);
}

void drawStack::regenTexture() {

      glPixelStorei(GL_UNPACK_ALIGNMENT,4);
      glPixelStorei(GL_PACK_ALIGNMENT, 4);
      glGenTextures(1,&filePictures[0]);//pictureIndex]); //may need change//&[index]
      glBindTexture(GL_TEXTURE_2D,filePictures[0]);//pictureIndex]);
      glTexImage2D((GLenum)GL_TEXTURE_2D, 0,GL_RGB , curPictureWidth, curPictureHeight, 0, GL_RGB ,(GLenum)GL_UNSIGNED_BYTE, (GLvoid*)rgb);
      //glTexEnvi( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_MODULATE );
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);//clamp
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);//GL_NEAREST
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    //GL_UNISNGED_BYTE
      glBindTexture(GL_TEXTURE_2D,0);

}
void drawStack::loadImage(int index) {
  
  //retrieve data from python module
  PyObject *args, *method, *data, *item, *dim;
  args=Py_BuildValue("(i)",index);
  method=PyObject_GetAttrString(object,"getRGBMap");
  data=PyEval_CallObject(method,args);
  //free up some of that precious, delicious memory
  
  Py_DECREF(method);
  //while we're at it, get the dimensions too
  int x,y;
  method=PyObject_GetAttrString(object,"getDimensions");
  dim=PyEval_CallObject(method,args);
  item=PySequence_GetItem(dim,0);
  if (!PyLong_Check(item)) {
    printf("invalid conversion of dimensionsx!");
    //raise(SIGSEGV);
  }
  x=PyLong_AsLong(item);
  Py_DECREF(item);
  item=PySequence_GetItem(dim,1);
  if (!PyLong_Check(item)) {
    printf("invalid conversion of dimensionsy!");
    //raise(SIGSEGV);
  }
  y=PyLong_AsLong(item);
  Py_DECREF(item);
  Py_DECREF(dim);
  printf("y %d\n",y);
  //extract values from list
  //unsigned char *rgb;
  int arrsize, i;

  arrsize=PyObject_Length(data);
  printf("neh\n");
  ///yeah yeah, there's a safer way to do this... we'll deal with it when the time comes
  rgb= (unsigned char *)realloc(rgb,sizeof(unsigned char)*arrsize);

  //evaluate and extract list
  for (i=0;i<arrsize;i++) {
    item=PySequence_GetItem(data,i);
    if (!PyLong_Check(item)) { //used to be PyInt
      free(rgb);
      printf("dne not int messed\n");
      //raise(SIGSEGV);
    }
    rgb[i] = PyLong_AsLong(item);//As Intfor  mac
    Py_DECREF(item);
  }
  //free up
  Py_DECREF(data);
  printf("%d %d %d %d %d %d %d %d\n",rgb[0],rgb[1],rgb[2],rgb[3],rgb[4],rgb[5],x,y);
  glPixelStorei(GL_UNPACK_ALIGNMENT,4);
  glPixelStorei(GL_PACK_ALIGNMENT, 4); 
  glGenTextures(1,&filePictures[0]);//index]); //may need change//&[index]
  glBindTexture(GL_TEXTURE_2D,filePictures[0]);//index]);
  glTexImage2D((GLenum)GL_TEXTURE_2D, 0,GL_RGB , x, y, 0, GL_RGB ,(GLenum)GL_UNSIGNED_BYTE, (GLvoid*)rgb);
  //glTexEnvi( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_MODULATE );
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);//clamp
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);//GL_NEAREST
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  
  glBindTexture(GL_TEXTURE_2D,0);

  //set width and height of picture
  curPictureWidth=x;
  curPictureHeight=y;
  

}
void drawStack::newFrame() {
  PyObject *args, *method;
  args=Py_BuildValue("(i,i)",100,100);
  method=PyObject_GetAttrString(object,"newImage");
  PyEval_CallObject(method,args);
  // filePicturessize=1; //arbitrary
  pictureIndex=0;
  filePictures=(GLuint*)malloc(sizeof(GLuint));
}
void drawStack::changeStack(int pos) {
  printf("s%d\n",filePicturessize);
  if (pictureIndex+pos>=0 && pictureIndex+pos<filePicturessize) {
    printf("wrok?\n");
     updateImage(object,pictureIndex,rgb,curPictureWidth,curPictureHeight,colorSize);
     //free(rgb);
     pictureIndex+=pos;
     loadImage(pictureIndex);
     paintGL();
  }
}
int drawStack::initializePython(const char **name) { //will need to change things
  tstate=Py_NewInterpreter();
  PyRun_SimpleString("print ('done and done')");
  PyRun_SimpleString("import site");

  PyRun_SimpleString("site.addsitedir('/Users/Peter/QCarder/pyfiles/')");
  PyRun_SimpleString("print('eyyy')");
  PyObject *module, *modClass, *args,*method,*ret ;
  module=PyImport_ImportModule("instance");
  //check loading
  if (module==NULL) {
    printf("Can't load module\n");
    return -1;
  }

  modClass= PyObject_GetAttrString(module, "instance");
  
  Py_DECREF(module);
  if (modClass==NULL) {
    Py_DECREF(modClass);
    printf("can't class instance\n");
    return -1;
  }
  printf("rightb4: %s\n",*name);
  char *nk=strdup(*name);
  printf("after: %s\n",nk);
  args=Py_BuildValue("s",nk);
  if (args==NULL) {
    Py_DECREF(args);
    printf("can't args instance\n");
    return -1;
  }
    printf("moo\n");
  object=PyEval_CallObject(modClass,args);

  if (object==NULL) {
    Py_DECREF(object);
    printf("can't object instance\n");
    return -1;
  }

  Py_DECREF(modClass);
  Py_DECREF(args);

  args=Py_BuildValue("");
  ret=PyObject_GetAttrString(object,"numImage");
  Py_DECREF(args);
  if (!PyLong_Check(ret)) {
     Py_DECREF(object);
    printf("nosize\n");
    return -1;
  }
  filePicturessize=PyLong_AsLong(ret);
  printf("size %d\n",filePicturessize);
  Py_DECREF(ret);
  //Py_Finalize();
  return 0;
}
void drawStack::paintGL()
    {
        // Draw the scene:
        /*QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
        f->glClear(GL_COLOR_BUFFER_BIT);*/

    }
void drawStack::initializeGL() {
    // Set up the rendering context, load shaders and other resources, etc.:
    //QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    initializeOpenGLFunctions();
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    //initializePython("eyy");
    //newFrame();
    loadImage(0);//temp
    //Py_Finalize();
    updateImage(object,0,rgb,300,300,1);
    saveStack(object);
    printf("SAVING\n");

}
void drawStack::resizeGL(int width, int height){

  // Compute aspect ratio of the new window
   if (height == 0) height = 1;                // To prevent divide by 0
   /*GLfloat aspect = (GLfloat)width / (GLfloat)height;
 
   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);
 
   // Set the aspect ratio of the clipping area to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();
   //gluOrtho2D(-16.0 , 16.0 , -16.0, 16.0);
    // Update projection matrix and other size related settings:
    /*m_projection.setToIdentity();
    m_projection.perspective(45.0f, w / float(h), 0.01f, 100.0f);*/

}

void drawStack::closeEvent(QCloseEvent *event) {
    Py_EndInterpreter(tstate);

}

drawStack::~drawStack()
{

}

