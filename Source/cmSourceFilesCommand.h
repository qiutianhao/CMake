/*=========================================================================

  Program:   CMake - Cross-Platform Makefile Generator
  Module:    $RCSfile$
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) 2002 Kitware, Inc., Insight Consortium.  All rights reserved.
  See Copyright.txt or http://www.cmake.org/HTML/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef cmSourceFilesCommand_h
#define cmSourceFilesCommand_h

#include "cmCommand.h"

/** \class cmSourceFilesCommand
 * \brief Add source files to the build.
 *
 * cmSourceFilesCommand adds source files to the build. The source
 * files will be added to the current library (if defined by the
 * LIBRARY(library) command. Use this command to add source files not
 * dependent on other packages (use SOURCE_FILES_REQUIRED() to add
 * dependent source files).
 *
 * It allows sources to be added even if they are generated by a build 
 * process. This can be achieved usiong GENERATED keyword:
 * SOURCE_FILES( Project_SRCS
 *   Source1
 *   Source2
 *   ...
 *   GENERATED
 *   SourceThatDoesNotExist )
 *
 * \sa cmSourceFilesRequireCommand
 */
class cmSourceFilesCommand : public cmCommand
{
public:
  /**
   * This is a virtual constructor for the command.
   */
  virtual cmCommand* Clone() 
    {
    return new cmSourceFilesCommand;
    }

  /**
   * This is called when the command is first encountered in
   * the CMakeLists.txt file.
   */
  virtual bool InitialPass(std::vector<std::string> const& args);

  /**
   * The name of the command as specified in CMakeList.txt.
   */
  virtual const char* GetName() { return "SOURCE_FILES";}

  /**
   * Succinct documentation.
   */
  virtual const char* GetTerseDocumentation() 
    {
    return "Deprecated.  Use SET to list sources in a variable.";
    }

  /**
   * This determines if the method is deprecated or not
   */
  virtual bool IsDeprecated(int major, int minor);

  /**
   * More documentation.
   */
  virtual const char* GetFullDocumentation()
    {
    return
      "  SOURCE_FILES(variable file1 file2 ...\n"
      "               [ GENERATED generated_file1 ... ])\n"
      "Adds the given sources to the list in the given variable.  Sources "
      "listed after GENERATED will be given the GENERATED property.  See "
      "SET_SOURCE_FILES_PROPERTIES to add the GENERATED property to any "
      "source.";
    }
  
  cmTypeMacro(cmSourceFilesCommand, cmCommand);
};



#endif
