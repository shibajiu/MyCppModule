/*==============================================================================

  Program: 3D Slicer

  Portions (c) Copyright Brigham and Women's Hospital (BWH) All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

==============================================================================*/

// Qt includes
#include <QtPlugin>

// MyCppModule Logic includes
#include <vtkSlicerMyCppModuleLogic.h>

// MyCppModule includes
#include "qSlicerMyCppModuleModule.h"
#include "qSlicerMyCppModuleModuleWidget.h"

//-----------------------------------------------------------------------------
Q_EXPORT_PLUGIN2(qSlicerMyCppModuleModule, qSlicerMyCppModuleModule);

//-----------------------------------------------------------------------------
/// \ingroup Slicer_QtModules_ExtensionTemplate
class qSlicerMyCppModuleModulePrivate
{
public:
  qSlicerMyCppModuleModulePrivate();
};

//-----------------------------------------------------------------------------
// qSlicerMyCppModuleModulePrivate methods

//-----------------------------------------------------------------------------
qSlicerMyCppModuleModulePrivate::qSlicerMyCppModuleModulePrivate()
{
}

//-----------------------------------------------------------------------------
// qSlicerMyCppModuleModule methods

//-----------------------------------------------------------------------------
qSlicerMyCppModuleModule::qSlicerMyCppModuleModule(QObject* _parent)
  : Superclass(_parent)
  , d_ptr(new qSlicerMyCppModuleModulePrivate)
{
}

//-----------------------------------------------------------------------------
qSlicerMyCppModuleModule::~qSlicerMyCppModuleModule()
{
}

//-----------------------------------------------------------------------------
QString qSlicerMyCppModuleModule::helpText() const
{
  return "This is a loadable module that can be bundled in an extension";
}

//-----------------------------------------------------------------------------
QString qSlicerMyCppModuleModule::acknowledgementText() const
{
  return "This work was partially funded by NIH grant NXNNXXNNNNNN-NNXN";
}

//-----------------------------------------------------------------------------
QStringList qSlicerMyCppModuleModule::contributors() const
{
  QStringList moduleContributors;
  moduleContributors << QString("John Doe (AnyWare Corp.)");
  return moduleContributors;
}

//-----------------------------------------------------------------------------
QIcon qSlicerMyCppModuleModule::icon() const
{
  return QIcon(":/Icons/MyCppModule.png");
}

//-----------------------------------------------------------------------------
QStringList qSlicerMyCppModuleModule::categories() const
{
  return QStringList() << "Examples";
}

//-----------------------------------------------------------------------------
QStringList qSlicerMyCppModuleModule::dependencies() const
{
  return QStringList();
}

//-----------------------------------------------------------------------------
void qSlicerMyCppModuleModule::setup()
{
  this->Superclass::setup();
}

//-----------------------------------------------------------------------------
qSlicerAbstractModuleRepresentation* qSlicerMyCppModuleModule
::createWidgetRepresentation()
{
  return new qSlicerMyCppModuleModuleWidget;
}

//-----------------------------------------------------------------------------
vtkMRMLAbstractLogic* qSlicerMyCppModuleModule::createLogic()
{
  return vtkSlicerMyCppModuleLogic::New();
}
