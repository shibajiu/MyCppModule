/*=auto=========================================================================

 Portions (c) Copyright 2005 Brigham and Women's Hospital (BWH) 
 All Rights Reserved.

 See COPYRIGHT.txt
 or http://www.slicer.org/copyright/copyright.txt for details.

 Program:   3D Slicer

=========================================================================auto=*/


// .NAME __qSlicerMyCppModuleModuleWidgetsExport - manage Windows system differences
// .SECTION Description
// The __qSlicerMyCppModuleModuleWidgetsExport captures some system differences between Unix
// and Windows operating systems. 

#ifndef __qSlicerMyCppModuleModuleWidgetsExport_h
#define __qSlicerMyCppModuleModuleWidgetsExport_h

#if defined(WIN32) && !defined(qSlicerMyCppModuleModuleWidgets_STATIC)
 #if defined(qSlicerMyCppModuleModuleWidgets_EXPORTS)
  #define Q_SLICER_MODULE_MYCPPMODULE_WIDGETS_EXPORT __declspec( dllexport )
 #else
  #define Q_SLICER_MODULE_MYCPPMODULE_WIDGETS_EXPORT __declspec( dllimport )
 #endif
#else
 #define Q_SLICER_MODULE_MYCPPMODULE_WIDGETS_EXPORT
#endif

#endif
