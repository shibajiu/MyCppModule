/*==============================================================================

  Program: 3D Slicer

  Copyright (c) Kitware Inc.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  This file was originally developed by Jean-Christophe Fillion-Robin, Kitware Inc.
  and was partially funded by NIH grant 3P41RR013218-12S1

==============================================================================*/

// FooBar Widgets includes
#include "qSlicerMyCppModuleFooBarWidget.h"
#include "ui_qSlicerMyCppModuleFooBarWidget.h"

//-----------------------------------------------------------------------------
/// \ingroup Slicer_QtModules_MyCppModule
class qSlicerMyCppModuleFooBarWidgetPrivate
  : public Ui_qSlicerMyCppModuleFooBarWidget
{
  Q_DECLARE_PUBLIC(qSlicerMyCppModuleFooBarWidget);
protected:
  qSlicerMyCppModuleFooBarWidget* const q_ptr;

public:
  qSlicerMyCppModuleFooBarWidgetPrivate(
    qSlicerMyCppModuleFooBarWidget& object);
  virtual void setupUi(qSlicerMyCppModuleFooBarWidget*);
};

// --------------------------------------------------------------------------
qSlicerMyCppModuleFooBarWidgetPrivate
::qSlicerMyCppModuleFooBarWidgetPrivate(
  qSlicerMyCppModuleFooBarWidget& object)
  : q_ptr(&object)
{
}

// --------------------------------------------------------------------------
void qSlicerMyCppModuleFooBarWidgetPrivate
::setupUi(qSlicerMyCppModuleFooBarWidget* widget)
{
  this->Ui_qSlicerMyCppModuleFooBarWidget::setupUi(widget);
}

//-----------------------------------------------------------------------------
// qSlicerMyCppModuleFooBarWidget methods

//-----------------------------------------------------------------------------
qSlicerMyCppModuleFooBarWidget
::qSlicerMyCppModuleFooBarWidget(QWidget* parentWidget)
  : Superclass( parentWidget )
  , d_ptr( new qSlicerMyCppModuleFooBarWidgetPrivate(*this) )
{
  Q_D(qSlicerMyCppModuleFooBarWidget);
  d->setupUi(this);
//  d->pushButton->setText("Open ObjFile");
  glWidget = new Widget;  
  d->scrollArea->setWidget(glWidget);

}

//-----------------------------------------------------------------------------
qSlicerMyCppModuleFooBarWidget
::~qSlicerMyCppModuleFooBarWidget()
{

}

void qSlicerMyCppModuleFooBarWidget
::keyPressEvent(QKeyEvent * event)
{
    switch (event->key()) {
    case Qt::Key_L:{

        break;
    }
    case Qt::Key_O:{
        OpenObjFile();
        break;
    }
    }
}

void qSlicerMyCppModuleFooBarWidget
::OpenObjFile()
{
    objfileDialog=new QFileDialog(this);
    objfileDialog->setWindowTitle(tr("Open ObjFile"));
    objfileDialog->setDirectory(".");
    objfileDialog->setFilter(tr("Obj Files(*.obj)"));
    if(objfileDialog->exec() == QDialog::Accepted) {
        objfilepath = objfileDialog->selectedFiles()[0];
        glWidget->ImportObjFile(objfilepath);
    }
}

//void qSlicerMyCppModuleFooBarWidget
//::on_pushButton_clicked()
//{
//    objfileDialog=new QFileDialog(this);
//    objfileDialog->setWindowTitle(tr("Open ObjFile"));
//    objfileDialog->setDirectory(".");
//    objfileDialog->setFilter(tr("Obj Files(*.obj)"));
//    if(objfileDialog->exec() == QDialog::Accepted) {
//        objfilepath = objfileDialog->selectedFiles()[0];
//    }
//}
