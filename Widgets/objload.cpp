#include "objload.h"


int ObjLoad::Obj_Load(QString ObjPath, QList<Face> *obj)
{
    init();
    obj->clear();
    QStringList temp;    

    QFile ObjFile(ObjPath);
    if(!ObjFile.open(QIODevice::ReadOnly|QIODevice::Text))
        return 0;
    QTextStream ObjStream(&ObjFile);
    QString ObjLine;
    while (!ObjStream.atEnd()) {//get vertices,faces,normals
        ObjLine=ObjStream.readLine();
        temp=ObjLine.split(" ");
        if(temp[0]=="v") {
            vertextemp.set(temp);
            Vertices.append(vertextemp);
            MaxPoint.findMaxAbs(vertextemp);
            MinPoint.findMinAbs(vertextemp);
        }
        else if (temp[0]=="f") {
            faceindextemp.set(temp);
            Indexs.append(faceindextemp);
        }
        else if (temp[0]=="n") {
            normaltemp.set(temp);
            Normals.append(normaltemp);
        }
    }
    ObjFile.close();//close file

    int len=Indexs.length();
    for(int i=0;i<len;++i){
        facetemp.set(Vertices,Indexs[i]);
        obj->append(facetemp);
    }

    return 1;
}

QList<ObjLoad::Face> ObjLoad::Obj_Load(QString ObjPath)
{
    init();
    QList<Face> obj;
    QStringList temp;

    QFile ObjFile(ObjPath);
    if(!ObjFile.open(QIODevice::ReadOnly|QIODevice::Text))
        return obj;
    QTextStream ObjStream(&ObjFile);
    QString ObjLine;
    while (!ObjStream.atEnd()) {//get vertices,faces,normals
        ObjLine=ObjStream.readLine();
        temp=ObjLine.split(" ");
        if(temp[0]=="v") {
            vertextemp.set(temp);
            Vertices.append(vertextemp);
            MaxPoint.findMaxAbs(vertextemp);
            MinPoint.findMinAbs(vertextemp);
        }
        else if (temp[0]=="f") {
            faceindextemp.set(temp);
            Indexs.append(faceindextemp);
        }
        else if (temp[0]=="n") {
            normaltemp.set(temp);
            Normals.append(normaltemp);
        }
    }
    ObjFile.close();//close file

    int len=Indexs.length();
    for(int i=0;i<len;++i){
        facetemp.set(Vertices,Indexs[i]);
        obj.append(facetemp);
    }

    return obj;
}

void ObjLoad::init()
{
    Indexs.clear();
    Vertices.clear();
    Faces.clear();

    MaxPoint.init();
    MinPoint.init();
}

QList<float> ObjLoad::Kalman(QList<int> prior, QList<int> z, QList<float> p, QList<float> Q, QList<float> R){
    QList<float> Kg , xpost;
    for (int i = 0; i < prior.length(); ++i)
    {
        p[i] = p[i] + Q[i];
        Kg[i] = p[i] / (p[i] + R[i]);
        xpost[i] = prior[i] + Kg[i] * (z[i] - prior[i]);
        p[i] = (1 - Kg[i]) * p[i];
    }
    return xpost;
}
void ObjLoad::unitest()
{
    int temp=0;
    isgetobj("E:\\hit\\test\\testtriangle\\testtriangle\\2.obj",temp);
QMessageBox::information(NULL, "unitest", QString::number(temp), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
}

void ObjLoad::isgetobj(QString ObjPath,int &objlength)
{
    init();
    QStringList temp;

    QFile ObjFile(ObjPath);
    if(!ObjFile.open(QIODevice::ReadOnly|QIODevice::Text))
        return;
    QTextStream ObjStream(&ObjFile);
    QString ObjLine;
    while (!ObjStream.atEnd()) {//get vertices,faces,normals
        ObjLine=ObjStream.readLine();
        temp=ObjLine.split(" ");
        if(temp[0]=="v") {
            vertextemp.set(temp);
            Vertices.append(vertextemp);
        }
        else if (temp[0]=="f") {
            faceindextemp.set(temp);
            Indexs.append(faceindextemp);
        }
        else if (temp[0]=="n") {
            normaltemp.set(temp);
            Normals.append(normaltemp);
        }
    }
    ObjFile.close();//close file

    objlength=Indexs.length();
//    for(int i=0;i<len;++i){
//        facetemp.set(Vertices,Indexs[i]);
//        obj.append(facetemp);
//    }
}

