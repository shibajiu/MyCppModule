#include "widget.h"


Widget::Widget(QGLWidget *parent) :
    QGLWidget(parent)
{
    xRot = 0;
        yRot = 0;
        zRot = 0;
        AngToRad=Pi/180;
        isObjOn=false;
        isTest=false;
        zTra=0;

        faceColors[0] = Qt::red;
        faceColors[1] = Qt::green;
        faceColors[2] = Qt::blue;
        faceColors[3] = Qt::yellow;

        timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(alwaysRotate()));
        timer->start(70);
//        obj.unitest();
        ImportObjFile("E:\\hit\\test\\testtriangle\\testtriangle\\2.obj");
}

Widget::~Widget()
{
}

void Widget::initializeGL()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
        glShadeModel(GL_SMOOTH);
        glEnable(GL_DEPTH_TEST);
}

static float radius = 50.5f;

void Widget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
//    gluLookAt(radius*qCos(AngToRad*xRot), yRot, radius*qSin(AngToRad*xRot), 0, 0, 0, 0, 1, 0);
    if(isObjOn){
        drawObj();
    }
    else {
        drawTriangle();
    }
    glFlush();
}

void Widget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.0f, (float)w / h, 1.0f, 1000.0f);
    glMatrixMode(GL_MODELVIEW);
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();
    yRot+=4 * dy;
    xRot+=4 * dx;
    if (yRot>30.0f)
        yRot=30.0f;
    else if (yRot<-30.0f)
        yRot=-30.0f;
    updateGL();

    lastPos = event->pos();
}

void Widget::wheelEvent(QWheelEvent *event)
{
    zTra+=event->delta()/120;
    radius+=event->delta()/120;
    updateGL();
}

void Widget::drawTriangle()
{
    static const GLfloat P1[3] = { 0.0, -1.0, +2.0 };
    static const GLfloat P2[3] = { +1.73205081, -1.0, -1.0 };
    static const GLfloat P3[3] = { -1.73205081, -1.0, -1.0 };
    static const GLfloat P4[3] = { 0.0, +2.0, 0.0 };

    static const GLfloat * const coords[4][3] = {
        { P1, P2, P3 }, { P1, P3, P4 }, { P1, P4, P2 }, { P2, P4, P3 }
    };

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -50.0+zTra);
//    if(isTest)
//    {
        glRotatef(xRot, 1.0, 0.0, 0.0);
        glRotatef(yRot, 0.0, 1.0, 0.0);
        glRotatef(zRot, 0.0, 0.0, 1.0);
//    }
//    else
//    {
//        glRotatef(Pitch,0,1,0);
//        glRotatef(Yaw,sin(Pitch*AngToRad),0,cos(Pitch*AngToRad));
//        glRotated(Roll,1,0,0);
//    }


    for (int i = 0; i != 4; ++i) {
        //glLoadName(i);
        glBegin(GL_TRIANGLES);
        qglColor(faceColors[i]);
        for (int j = 0; j < 3; ++j) {
            glVertex3f(coords[i][j][0], coords[i][j][1],
                       coords[i][j][2]);
        }
        glEnd();

    }
}

void Widget::drawObj()//draw obj
{
//    glLoadIdentity();
//    drawTriangle();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(radius*qCos(AngToRad*xRot), yRot, radius*qSin(AngToRad*xRot), 0, 0, 0, 0, 1, 0);

//    glTranslatef(0.0, 0.0, -50.0+zTra);
//    glRotatef(xRot, 1.0, 0.0, 0.0);
//    glRotatef(yRot, 0.0, qCos(yRot*AngToRad), -qSin(yRot*AngToRad));
//    glRotatef(xRot, 0.0,1.0,0.0);
//    glRotatef(zRot, 0.0, 0.0, 1.0);
    glBegin(GL_TRIANGLES);
qglColor(Qt::green);
    for(int i=0;i<ObjFace.length();i++){        
        glVertex3f(ObjFace[i].a.x,ObjFace[i].a.y,ObjFace[i].a.z);
        glVertex3f(ObjFace[i].b.x,ObjFace[i].b.y,ObjFace[i].b.z);
        glVertex3f(ObjFace[i].c.x,ObjFace[i].c.y,ObjFace[i].c.z);
    }
//    QMessageBox::information(NULL, "Title", ObjFace[ObjFace.length()-1].toQString(), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    glFlush();
    glEnd();
}

void Widget::alwaysRotate()
{
    zRot += 2;
    updateGL();
}

void Widget::ImportObjFile(QString path)
{
    if(obj.Obj_Load(path,&ObjFace)==1){
        isObjOn=true;
        timer->stop();
    }
//    ObjFace=obj.Obj_Load(path);
//    isObjOn=true;
//    timer->stop();
}
