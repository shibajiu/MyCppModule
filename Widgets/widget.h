#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtOpenGL/QtOpenGL>
#include <QtCore/qmath.h>
#include "gl/GLU.h"
#include "math.h"
#include "objload.h"

#ifndef Pi
#define Pi 3.1415926
#endif

namespace Ui {
class Widget;
}

class Widget : public QGLWidget
{
    Q_OBJECT

public:
    explicit Widget(QGLWidget *parent = 0);
    ~Widget();
    int xRotation() const { return xRot; }
    int yRotation() const { return yRot; }
    int zRotation() const { return zRot; }
    void ImportObjFile(QString path);//import obj file from path using ObjLoada
    bool isTest;

private:
    Ui::Widget *ui;

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);

private slots:
    void alwaysRotate();
    void drawTriangle();
    void drawObj();

private:
    int xRot;
    int yRot;
    int zRot;
    int Yaw;
    int Pitch;
    int Roll;
    int zTra;
    double AngToRad;
    ObjLoad obj;
    bool isObjOn;
    QList<ObjLoad::Face> ObjFace;

    QColor faceColors[4];
    QPoint lastPos;
    QTimer *timer;
};

#endif // WIDGET_H
