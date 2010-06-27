  
/*
###############################################################################
## PROJECT:                     L o g
###############################################################################
## FILE:                logtest.cpp
## SYNOPSIS:            Test for the Log module
###############################################################################
## SYSTEM:              COMPILER:              STATE:
## Win98, NT4.0         MS VisualC++ 5.x         ?
## Win 2K, XP           MS VisualC++ 6.0         +
## Win 2K, XP           GCC 3.2    (cygwin)      +
## Win98                GCC 2.95.1 (cygwin)      ?
## NT4.0/2k             GCC 2.95.1 (cygwin)      ?
## Solaris 2.6          GCC 2.95.1               ?
## Linux SuSE 6.3       GCC 2.92.x               ?
###############################################################################
## VERSION: DATE:       AUTHOR: CHANGES:
## 0.1      08-Jan-2003 CLu     logtest.cpp implemented, project built
###############################################################################
## 
## DESCRIPTION:  
## Simple testing program for the Log module. 
## Just shows how the Log-function could be used. LogTest itself is not
## needed to use the Log-functions.
##
## HOWTO USE:
## compile:   on win32/MS-VisualC open log.dsw
##            on unixes/cygwin: edit makelog.sh, then execute
## start:     klick or execute the generated program LogTest(.exe)
## then klick a few buttons and watch what happens.
##
## CONTACT:
##  if you've got problems or want to comment 
##  on this little thing you  may write to:           CLu@plixx.de
##  Suggestions, bug-reports or patches are welcome.
##
## CREDITS:
##  Bill Spitzak et al, for the great FLTK 
##    
###################################################################################
## COPYRIGHT:  
## Copyright 2000-2003 by Christian Lunau and others.
##
## This sourcecode is free software; you can redistribute it and/or
## modify it under the terms of the GNU Library General Public
## License as published by the Free Software Foundation; either
## version 2 of the License, or (at your option) any later version.
##
## This sourcecode is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
## Library General Public License for more details.
##
## You should have received a copy of the GNU Library General Public
## License along with this library; if not, write to the Free Software
## Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
## USA.
##
## Please report all bugs and problems to "butterflycollector@plixx.de".
##
###################################################################################
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>

#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Light_Button.H>
#include <FL/Fl_Repeat_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl.H>

#include <log.hpp>


// set Warning-level of MS-VisualC++ for this file to 4:
#if WIN32 && _MSC_VER
#pragma warning(push,4)
#endif

#if PLX_MSWIN32
    #define PATH_DELIMITER  "\\"
#elif PLX_UNIX
    #define PATH_DELIMITER  "/"
#else
    #define PATH_DELIMITER  "unknown"
#endif

//###################################################################
//Prototypes of the callbacks:
void cb_activate_log(void);
void cb_deactivate_log(void);
void cb_show_log(void);
void cb_hide_log(void);
void cb_redirect_stdio_log(void);
void cb_direct_stdio_log(void);

void cb_output_using_log(void);
void cb_output_using_stdio(void);
void cb_output_using_iostreams(void);
void cb_output_mixed_log(void);

void cb_quit(void);

//###################################################################
void cb_quit(void) 
{
while (Fl::first_window()) Fl::first_window()->hide();
}

//###################################################################
void cb_activate_log(void)
{
LogActivate();
}

//###################################################################
void cb_deactivate_log(void)
{
LogDeActivate();
}

//###################################################################
void cb_show_log(void)
{
LogShow();
}

//###################################################################
void cb_hide_log(void)
{
LogHide();
}

//###################################################################
void cb_redirect_stdio_log(void)
{
LogRedirectStdio();
}

//###################################################################
void cb_direct_stdio_log(void)
{
LogDirectStdio();
}


//###################################################################
void cb_output_using_log(void)
{
int i =1;
LogDebug((      "This is debug output: %d.",i++));
LogInfo((       "This is info output: %d.",i++));
LogWarn((       "This is a warning: %d.",i++));
LogError((      "This is error output: %d.",i++));
LogTimerStart(( "Timer started: %d.",i++));
LogTimerStop((  "Timer stopped: %d.",i++));
}


//###################################################################
void cb_output_using_stdio(void)
{
printf("printf: This is printf\n");
fprintf(stdout,"fprintf(stdout) goes here.\n");
fprintf(stderr,"fprintf(stderr) goes here.\n");
//puts       
//fputs      
//putchar    
//putc       
//fputc      
//vprintf    
//vfprintf   
}


//###################################################################
void cb_output_using_iostreams(void)
{
cout << "cout: streamed through cout" << endl;
cerr << "cerr: streamed through cerr" << endl;
//Log::log_hdl->my_cinfo <<"cinfo" << endl;
}

//###################################################################
void cb_output_mixed(void)
{
LogInfo(( "####### output via Log-Functions:"));
LogInfo(( "This is a LogInfo."));
LogWarn(( "This is a LogWarn."));
LogError(("This is a LogError."));
errno = 2; // fake errno
LogWarn(( "A warning between two Errors..."));
LogError(("This is a LogError, with errno set to 2."));
errno = 0; // fake errno repair
LogInfo(( "This is a LogInfo, after a LogError."));
LogInfo(( "Tabs, formatted output: \t1\t2\t3" ));

//currently doesn't work well in Fl_Browser, better break those lines up:
//LogInfo(( "These are multiple lines, formatted output: \nLine1\nLine2\nLine3\n."));

LogInfo(( "####### output via C-stdio:"));
FILE *fh;
char fname[128];
strcpy(fname,"testdata");
strcat(fname,PATH_DELIMITER);
strcat(fname,"testfile.txt");
fh = fopen(fname,"w");
printf("printf: Howdy, guess where i come from...");
fprintf(fh,"fprintf(fh): igo to file...");
fprintf(stdout,"fprintf(stdout) goes here, and");
fprintf(stderr,"fprintf(stderr) takes this way...");
fclose(fh);

LogInfo(( "####### output via C++ streaming"));

cout << "Streaming starts with an S..." << endl;
cout << "cout: This is streamed through cout" << endl;
cerr << "cerr: This is streamed through cerr" << endl;
cout << "Streamed Tabs: \t1\t2\t3" << endl;
cout << "These are multiple lines, streamed output:" << endl << "Line1" << endl << "Line2" << endl << "Line3" << endl;
cout << "Next output is a null-string, then a line will be appended: " << endl;
cout << "";
cout << "this one got appended." << endl;
cout << "Next line gets a single EOF" << endl;
cout << EOF << endl;
int    integer = 42;
float  flo     = (float) 3.14;
long double doubl   = 0.0000002434;
cout << "Some Numbers: int= " << integer << " float= " << flo << " double= " << doubl << "." << endl;

LogInfo(( "####### mixed output:"));

cout <<   "This is streamed 1";
cout << " and this one got appended." << endl;
LogInfo(( "This is LogInfo  1"));
printf("Tihs is a printf-output 1.5");
cout <<   "This is streamed 2" << endl;
LogInfo(( "This is LogInfo  2"));
cout <<   "This is streamed 3" << endl;
LogInfo(( "This is LogInfo  3"));

LogInfo(( "######## end of output."));
}

//###################################################################
int main(int argc, char *argv[ ], char *envp[ ]) 
{
argc = argc; // just to get rid of some warnings.
argv = argv; //
envp = envp; //

LogInit();
if (!LogIsInitialised())
   {
   fprintf(stderr,"Cannot initialise Log!");
   return -1;
   }
LogInfo(("OK, Log is initialised"));

// create windows/widgets of test-application:
Fl_Window win(280, 280, 212, 196, "Log-Test");

Fl_Box *obj;
obj = new Fl_Box(FL_FRAME_BOX,      4,   4, 100, 22,"Log:");
obj->color(FL_GRAY+2); obj->labelsize(14); obj->labelfont(FL_BOLD);
obj->tooltip("test");
Fl_Button activate_log_button (     4,  28, 100, 22, "activate"    );
Fl_Button deactivate_log_button(    4,  52, 100, 22, "deactivate"  );
Fl_Button show_log_button(          4,  76, 100, 22, "show"        );
Fl_Button hide_log_button(          4, 100, 100, 22, "hide"        );
Fl_Button redirect_stdio_log_button(4, 124, 100, 22, "redir. stdio");
Fl_Button   direct_stdio_log_button(4, 148, 100, 22, "don't redir" );

obj = new Fl_Box(FL_FRAME_BOX,    108,   4, 100, 22,"Output:");
obj->color(FL_GRAY+2); obj->labelsize(14); obj->labelfont(FL_BOLD);
Fl_Repeat_Button output_using_log_button(      108,  28, 100, 22, "log"         );
Fl_Repeat_Button output_using_stdio_button(    108,  52, 100, 22, "stdio"       );
Fl_Repeat_Button output_using_iostreams_button(108,  76, 100, 22, "iostreams"   );
Fl_Repeat_Button output_mixed_button(          108, 100, 100, 22, "mixed"       );

// add callbacks to the widgets:
          activate_log_button.callback((Fl_Callback*)cb_activate_log  );
        deactivate_log_button.callback((Fl_Callback*)cb_deactivate_log);
              show_log_button.callback((Fl_Callback*)cb_show_log      );
              hide_log_button.callback((Fl_Callback*)cb_hide_log      );
    redirect_stdio_log_button.callback((Fl_Callback*)cb_redirect_stdio_log );
      direct_stdio_log_button.callback((Fl_Callback*)cb_direct_stdio_log   );

      output_using_log_button.callback((Fl_Callback*)cb_output_using_log      );
    output_using_stdio_button.callback((Fl_Callback*)cb_output_using_stdio    );
output_using_iostreams_button.callback((Fl_Callback*)cb_output_using_iostreams);
          output_mixed_button.callback((Fl_Callback*)cb_output_mixed          );

                          win.callback((Fl_Callback*)cb_quit);


win.show();
Fl::run();

return 0;
}


//reset changed Warning-Level: 
#if WIN32 && _MSC_VER
#pragma warning(pop)
#endif
