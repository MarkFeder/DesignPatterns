========================================================================
    CONSOLE APPLICATION : PrototypePattern Project Overview
========================================================================

AppWizard has created this PrototypePattern application for you.

This file contains a summary of what you will find in each of the files that
make up your PrototypePattern application.


PrototypePattern.vcxproj
    This is the main project file for VC++ projects generated using an Application Wizard.
    It contains information about the version of Visual C++ that generated the file, and
    information about the platforms, configurations, and project features selected with the
    Application Wizard.

PrototypePattern.vcxproj.filters
    This is the filters file for VC++ projects generated using an Application Wizard. 
    It contains information about the association between the files in your project 
    and the filters. This association is used in the IDE to show grouping of files with
    similar extensions under a specific node (for e.g. ".cpp" files are associated with the
    "Source Files" filter).

PrototypePattern.cpp
    This is the main application source file.

/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named PrototypePattern.pch and a precompiled types file named StdAfx.obj.

/////////////////////////////////////////////////////////////////////////////
Other notes:

AppWizard uses "TODO:" comments to indicate parts of the source code you
should add to or customize.

/////////////////////////////////////////////////////////////////////////////

####### Prototype Pattern #######

A prototype pattern is used in software development when the type of objects 
to create is determined by a prototypical instance, which is cloned to produce new objects. 
This pattern is used, for example, when the inherent cost of creating a new object in 
the standard way (e.g., using the new keyword) is prohibitively expensive for a given application.

####### Implementation #######

Declare an abstract base class that specifies a pure virtual clone() method. Any class that needs 
a "polymorphic constructor" capability derives itself from the abstract base class, and implements 
the clone() operation.

Here the client code first invokes the factory method. This factory method, depending on the 
parameter, finds out the concrete class. On this concrete class, the clone() method is called 
and the object is returned by the factory method.