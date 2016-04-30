#ifndef OBJLOAD_H
#define OBJLOAD_H

#include <QtCore/qglobal.h>
#include <QIODevice>
#include <QFile>
#include <QTextStream>
#include <QVector>
#include <QList>
#include <QStringList>
#include <QMessageBox>

class ObjLoad
{

public:

    struct Vertex{//vertex
        float x;
        float y;
        float z;
        void set(QStringList sl){
			this->x=sl[1].toFloat();
            this->y=sl[2].toFloat();
            this->z=sl[3].toFloat();
        }
    };

    struct FaceIndex{//face index
        public:
        int a;
        int b;
        int c;
        void set(QStringList sl){
            this->a=sl[1].toInt();
            this->b=sl[2].toInt();
            this->c=sl[3].toInt();
        }
    };

    struct Normal{//normal
        float x;
        float y;
        float z;
        void set(QStringList sl){
            this->x=sl[1].toFloat();
            this->y=sl[2].toFloat();
            this->z=sl[3].toFloat();
        }        
    };

    struct Face{
        Vertex a;
        Vertex b;
        Vertex c;
        void set(QList<Vertex> ver,FaceIndex ind){
            this->a=ver[ind.a-1];
            this->b=ver[ind.b-1];
            this->c=ver[ind.c-1];
        }
        QString toQString(){
            QString temp="a.x:"+QString::number(this->a.x)+"\ta.y:"+QString::number(this->a.y)+"\ta.z:"+QString::number(this->a.z)+"\n"
                    +"b.x:"+QString::number(this->b.x)+"\tb.y:"+QString::number(this->b.y)+"\tb.z:"+QString::number(this->b.z)+"\n"
                    +"c.x:"+QString::number(this->c.x)+"\tc.y:"+QString::number(this->c.y)+"\tc.z:"+QString::number(this->c.z);
            return temp;
        }
    };

public:
    int Obj_Load(QString ObjPath, QList<Face> obj);
    QList<Face> Obj_Load(QString ObjPath);
    QList<float> Kalman(QList<int> prior, QList<int> z, QList<float> p, QList<float> Q, QList<float> R);
    void unitest();//for test

private:
    void init();
    void isgetobj(QString ObjPath, int &objlength);

private:
    QList<Vertex> Vertices;
    QList<FaceIndex> Indexs;
    QList<Normal> Normals;
    QList<Face> Faces;
    Face facetemp;
    Normal normaltemp;
    FaceIndex faceindextemp;
    Vertex vertextemp;

};

#endif // OBJLOAD_H
