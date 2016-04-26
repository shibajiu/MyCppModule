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

#ifndef __qSlicerMyCppModuleFooBarWidget_h
#define __qSlicerMyCppModuleFooBarWidget_h

// Qt includes
#include "widget.h"
#include <QScrollArea>


// FooBar Widgets includes
#include "qSlicerMyCppModuleModuleWidgetsExport.h"

class qSlicerMyCppModuleFooBarWidgetPrivate;

/// \ingroup Slicer_QtModules_MyCppModule
class Q_SLICER_MODULE_MYCPPMODULE_WIDGETS_EXPORT qSlicerMyCppModuleFooBarWidget
  : public QWidget
{
  Q_OBJECT
public:
  typedef QWidget Superclass;
  qSlicerMyCppModuleFooBarWidget(QWidget *parent=0);
  virtual ~qSlicerMyCppModuleFooBarWidget();

protected slots:

private slots:
   // void on_pushButton_clicked();

protected:
  QScopedPointer<qSlicerMyCppModuleFooBarWidgetPrivate> d_ptr;

  void keyPressEvent(QKeyEvent * event);

private:
  Q_DECLARE_PRIVATE(qSlicerMyCppModuleFooBarWidget);
  Q_DISABLE_COPY(qSlicerMyCppModuleFooBarWidget);  
  GLWidget *glWidget;
  QFileDialog *objfileDialog;
  QString objfilepath;  

  void OpenObjFile();

};

#endif
