#include "widget.h"


GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{
    xRot = 0;
    yRot = 0;
    zRot = 0;

    faceColors[0] = Qt::red;
    faceColors[1] = Qt::green;
    faceColors[2] = Qt::blue;
    faceColors[3] = Qt::yellow;

    isObjOn=false;

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(alwaysRotate()));
    timer->start(70);
}

void GLWidget::initializeGL()
{
    glClearColor(0.0, 0.2, 0.3, 1.0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH);
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    if(isObjOn){
        drawObj();
    }
    else {
        drawTriangle();
    }
    glPopMatrix();
}

void GLWidget::resizeGL(int w, int h)
{
    int side = qMin(w, h);
    glViewport((width() - side) / 2, (height() - side) / 2, side, side);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.2, 1.2, -1.2, 1.2, 5.0, 60.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -40.0);
}

void GLWidget::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();
}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();

    if (event->buttons() & Qt::LeftButton) {
        (xRot + 4 * dx);
        setYRotation(yRot + 4 * dy);
    } else if (event->buttons() & Qt::RightButton) {
        (xRot + 4 * dy);
        setZRotation(zRot + 4 * dx);
    }

    lastPos = event->pos();
}

void GLWidget::wheelEvent(QWheelEvent *event)
{
    zTra+=event->delta()/120;
    updateGL();
}

//void GLWidget::keyPressEvent(QKeyEvent * event)
//{
//    switch (event->key()) {
//    case Qt::Key_L:{

//        break;
//    }
//    case Qt::Key_O:{
//        OpenObjFile();
//        break;
//    }
//    }
//}

void GLWidget::drawTriangle()
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
    glTranslatef(0.0, 0.0, -10.0+zTra);
    glRotatef(xRot, 1.0, 0.0, 0.0);
    glRotatef(yRot, 0.0, 1.0, 0.0);
    glRotatef(zRot, 0.0, 0.0, 1.0);

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

void GLWidget::drawObj()//draw obj
{
        glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -10.0+zTra);
    glRotatef(xRot, 1.0, 0.0, 0.0);
    glRotatef(yRot, 0.0, 1.0, 0.0);
    glRotatef(zRot, 0.0, 0.0, 1.0);
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

void GLWidget::normalizeAngle(int *angle)
{
    while (*angle < 0)
        angle += 360 * 16;
    while (*angle > 360 *16)
        angle -= 360 *16;
}

void GLWidget::setXRotation(int angle)
{
    normalizeAngle(&angle);
    if ( angle != xRot ) {
        xRot = angle;
//        emit xRotationChanged(angle);
        updateGL();
    }
}

void GLWidget::setYRotation(int angle)
{
    normalizeAngle(&angle);
    if ( angle != yRot ) {
        yRot = angle;
//        emit yRotationChanged(angle);
        updateGL();
    }
}

void GLWidget::setZRotation(int angle)
{
    normalizeAngle(&angle);
    if ( angle != zRot ) {
        zRot = angle;
//        emit zRotationChanged(angle);
        updateGL();
    }
}

void GLWidget::alwaysRotate()
{
    zRot += 2;
//    emit zRotationChanged(zRot);
    updateGL();
}

//void GLWidget::OpenObjFile()
//{
//    objfileDialog=new QFileDialog(this);
//    objfileDialog->setWindowTitle(tr("Open ObjFile"));
//    objfileDialog->setDirectory(".");
//    objfileDialog->setFilter(tr("Obj Files(*.obj)"));
//    if(objfileDialog->exec() == QDialog::Accepted) {
//        objfilepath = objfileDialog->selectedFiles()[0];
//    }
//}

void GLWidget::ImportObjFile(QString path)
{    
//    if(obj.Obj_Load(path,ObjFace)==1){
//        isObjOn=true;
//        timer->stop();
//    }
    ObjFace=obj.Obj_Load(path);
    isObjOn=true;
    timer->stop();
}
