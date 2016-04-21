#ifndef WIDGET_H
#define WIDGET_H

#include <Qt>
#include <QWidget>
#include <QtGui>
#include <QtOpenGL/QtOpenGL>
#include <QFileDialog>
#include "gl/GLU.h"
#include "math.h"

class GLWidget : public QGLWidget
{
    Q_OBJECT

public:
    explicit GLWidget(QWidget *parent = 0);

    int xRotation() const { return xRot; }
    int yRotation() const { return yRot; }
    int zRotation() const { return zRot; }

signals:
    void xRotationChanged(int angle);
    void yRotationChanged(int angle);
    void zRotationChanged(int angle);
    
public slots:
    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
//    void keyPressEvent(QKeyEvent * event);

private slots:
    void alwaysRotate();
    void drawTriangle();

private:
    void normalizeAngle(int *angle);
//    void OpenObjFile();

    int xRot;
    int yRot;
    int zRot;
//    QFileDialog *objfileDialog;
    QColor faceColors[4];
    QPoint lastPos;
    QString objfilepath;
    bool isObjOn;
};

#endif // WIDGET_H
