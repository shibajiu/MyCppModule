#ifndef WIDGET_H
#define WIDGET_H

#include <Qt>
#include <QWidget>
#include <QtGui>
#include <QtOpenGL/QtOpenGL>
#include <QFileDialog>
#include "gl/GLU.h"
#include "math.h"
#include "objload.h"


class GLWidget : public QGLWidget
{
    Q_OBJECT

public:
    explicit GLWidget(QWidget *parent = 0);

    int xRotation() const { return xRot; }
    int yRotation() const { return yRot; }
    int zRotation() const { return zRot; }

    void ImportObjFile(QString path);//import obj file from path using ObjLoad
    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);

//signals:
//    void xRotationChanged(int angle);
//    void yRotationChanged(int angle);
//    void zRotationChanged(int angle);
    
//public slots:
//    void setXRotation(int angle);
//    void setYRotation(int angle);
//    void setZRotation(int angle);

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
	void wheelEvent(QWheelEvent *event);
//    void keyPressEvent(QKeyEvent * event);

private slots:
    void alwaysRotate();    

private:
    void normalizeAngle(int *angle);
    void drawTriangle();
    void drawObj();
//    void OpenObjFile();

    int xRot;
    int yRot;
    int zRot;
	int zTra;
//    QFileDialog *objfileDialog;
    QColor faceColors[4];
    QPoint lastPos;
    ObjLoad obj;
//    QString objfilepath;
    bool isObjOn;
    QList<ObjLoad::Face> ObjFace;
    QTimer *timer;
};

#endif // WIDGET_H
