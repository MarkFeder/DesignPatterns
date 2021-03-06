========================================================================
    CONSOLE APPLICATION : DesignPatterns Project Overview
========================================================================

AppWizard has created this DesignPatterns application for you.

This file contains a summary of what you will find in each of the files that
make up your DesignPatterns application.


DesignPatterns.vcxproj
    This is the main project file for VC++ projects generated using an Application Wizard.
    It contains information about the version of Visual C++ that generated the file, and
    information about the platforms, configurations, and project features selected with the
    Application Wizard.

DesignPatterns.vcxproj.filters
    This is the filters file for VC++ projects generated using an Application Wizard. 
    It contains information about the association between the files in your project 
    and the filters. This association is used in the IDE to show grouping of files with
    similar extensions under a specific node (for e.g. ".cpp" files are associated with the
    "Source Files" filter).

DesignPatterns.cpp
    This is the main application source file.

/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named DesignPatterns.pch and a precompiled types file named StdAfx.obj.

/////////////////////////////////////////////////////////////////////////////
Other notes:

AppWizard uses "TODO:" comments to indicate parts of the source code you
should add to or customize.

/////////////////////////////////////////////////////////////////////////////

####### Builder Pattern #######
The Builder Creational Pattern is used to separate the construction of a complex object from
its representation so that the same construction process can create different objects representations.


####### Problem #######
We want to construct a complex object, however we do not want to have a complex constructor
member or one that would need many arguments.


####### Solution #######
Define an intermediate object whose member functions define the desired object part by part
before the object is available to the client.Builder Pattern lets us defer the construction
of the object until all the options for creation have been specified.