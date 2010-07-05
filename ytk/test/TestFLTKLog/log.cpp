
/*
###############################################################################
## PROJECT:                     L o g
###############################################################################
## FILE:                 Log.cpp
## DESCRIPTION:          Log-Window main code
###############################################################################
## SYSTEM:               COMPILER:              STATE:
## MS-Win 2K, XP         MS VisualC++ 6.0         +
## MS-Win 2K, XP         GCC 3.2.1  (cygwin)      +
## Win98, NT4.0          MS VisualC++ 6.0         ?
## Win98                 GCC 2.95.1 (cygwin)      ?
## Solaris 2.6           GCC 2.95.1               ?
## Linux SuSE 6.3        GCC 2.92.x               ?
## FreeBSD 4.x           GCC 2.92.x               - ! (maybe it works with IOSTREAM_OLDSTYLE)
## FreeBSD 4.x           GCC 3.x                  ?
###############################################################################
## VERSION: DATE:       AUTHOR: CHANGES:
## 0.1      11-Mar-2000 CLu     creation, extraction from cpDBG 3.63
## 0.2      13-Mar-2000 CLu     integration of StatusBox
## 0.3      22-Mar-2000 CLu     integration of streambuf
## 0.4      03-Apr-2000 CLu     redirecting ready, added some docu
## 0.5      29-Sep-2000 CLu     begin adding support for ClassworkX
##                              merge with DagLog and cpLog
## 0.51     01-Mar-2002 CLu     begin extraction for standalone logging
## 0.6      08-Jan-2003 CLu     LogTest.cpp implemented, own project built
## 0.7      09-Jan-2003 CLu     active-state button added. ClassworkX-Support
##                              will not be continued from now on. 
## 0.8      13-Jan-2003 CLu     Grumble. Had to disable redirection of streaming 
##                              under gcc because VC++ used deprecated iostream
##                              through strstream.
## 0.9      21-Jan-2003 CLu     redirecting iostreams now works with STL complient
#                               iostream as well.
## 0.91     31-Jan-2003 CLu     some code-cleanups
###############################################################################
##
## DESCRIPTION:  
##  simple logging window as a replacement for console-logging
##
##  I guess it's ok now. Simple enough to use it is...
##  But wait, there are some small things which look strange. 
##  First, the Log-class is not a real singleton. It has the limitations
##  of a singleton without its advantages. WHAT? OK-OK, calm down, 
##  there's reason behind this.
##
##  Note that there is a difference in the behaviour of th Log whether it is 
##  compiled in debug or in release mode: 
##  if DEBUG:   - log-window is open pon startup
##              - every output (Info,Warn,Error,Timer) is printed in the log-window
##  if RELEASE: - log-window is closed by default
##              - only Error-Output is printed, 
##              - the DEBUG, INFO and TIMER-Calls are completely preprocessed away!
##  both modes: Error-output always is printed, regardles if the log-window
##              is hidden or deactivated or both! 
##              Error-Output automatically opens the log-Window.
##    
## HOWTO USE:
##    Simply #include the header file "Log.hpp" in any source code
##    you want use it from.
##
##    LogInit()
##    LogInit(x_pos, y_pos, width, height, window_title, background_color, redir_stdio)
##       Instantiates exactly one class instance, subsequent calls are 
##       ignored. The parameters define the Log-window.
##       In RELEASE-Mode, the Log-Window will not be opened/shown upon initialisation, 
##       call LogShow() to make it visible.
##       If the last parameter, redirect_stdio, is set to true, then cout and 
##       cerr outputs get redirected to the Log-window. That means, any stream to 
##       cout or cerr will go to the Log, as well as standard printf's and fprintf's to stdio or
##       stderr. cin and stdin are not redirected. If problems with this occur, you 
##       may try to undefine LOG_REDIRECTS_STDIO in Log.hpp. Or drop me a note, i'll 
##       see if i can fix it then.
##
##    Some MACROS are defined for convienience:
## 
##    LogDebug(args)
##    LogInfo(args)
##    LogWarn(args)
##    LogError(args)
##       These macros accept a printf parameter-list as argument. 
##       They mainly differ in the color fo the text output to the list.
##       LogError additionally prints the Origin of the call (file, line,...).
##       To call these macros one have to use double-parenthesis:
##       LogInfo(("This is printet in Info-Color: %d",FL_BLACK));
##       This is neccesary 'cause macros normaly don't take variable
##       parameter lists (and for some extras).
##
##    LogTimerStart()
##    LogTimerStop(args)
##       This pair of macros together allow a very simple time-checking.
##       They are used similiar to a stop-watch, currently only one timer
##       is supported. Timing is based on the clock()-function, which
##       gives the time used by the calling process in clock-ticks,
##       so the resolution is not very fine, but at least sub-second.
##
##    LogIsVisible()
##    LogShow()
##    LogHide()
##       These show/hide the Log-window and determin if it is visible. 
##       If the window is only hidden, but not deactivated, the output
##       continues in the background.
##
##    LogIsActive()
##    LogActivate()
##    LogDeActivate()
##       These activate/deactivate the Log-window and determin if it 
##       is active. If the window is deactivated, no output will be 
##       written.
##
##    LogIsActive()
##    LogActivate()
##    LogDeActivate()
##       These activate/deactivate the Log-window and determin if it 
##       is active. If the window is deactivated, no output will be 
##       written.
##
##    LogDeInit()
##       Closes/destroys the Log window. This has to be called expicitly,
##       otherwise the destructor of the Log-class _never_ gets executed!
##
## RECOMMENDATION:
##    I think it is best to close your FLTK-program by adding:
##       while (Fl::first_window()) Fl::first_window()->hide();
##    to the cb_quit-callback of your main-window.
##
## NOTE:
##    The Log-class' implementation resembles somewhat that of a 
##    singleton, which means the constructor is protected and there is a
##    single static instance. All Log-functions handle the same instance, 
##    all output goes to the same window. You can only get to the object 
##    using the Log::log_hdl-pointer, which references the single instance.
##
##    So, the advantages of this kind of construction are: there is no need
##    of a pointer handling by the calling program, just call initialisation
##    and make sure the deinitialisation is called, then the use of the
##    output functions is very straight forward. Even the callbacks are set
##    in the constructor. Thats all. Plain and simple, isn't it? ;-)
##    
##    I consider this to be a convenient substitute for 
##    terminal/consol window-outputs.
##
## TODO:
##    - more testing (different compilers, OS's (does log still work on linux?)
##    - the output is coded for the 1.07 Version of Fl_Browser, which has 
##      no real support for character streaming (needed is an append to line
##      functionality). I didn't want to change Fl_Browser, so i 'simulated' 
##      the stream-appending behaviour, what is not nice.
##      In fact, it is realy ugly and inefficient.
##    - the active-state-button is a bit of a misuse of an Fl_Light_Button,
##      it would be better to use (implement?) a more flexible 2-state-button
##    - maybe i extend the LogTimer-Function to use different timers
##    - maybe a log-to-file option (file-tee) would be nice? hm...
##
## CONTACT:
##   if you've got problems or want to comment on this little thing you 
##   could write to:         CLu@plixx.de
##   Suggestions, bug-reports or patches are welcome.
##
## CREDITS:
##    This code is partially based on and definitly inspired by:
##    - the StatusBox code by Craig P. Earls
##        Thanks, Craig, i've learned quite a bit by trying to 
##        understand what you'd coded ;-)
##    - the streambuf/GUI-Window code by Dietmar Kuehl 
##        pretty neat stuff. Dietmar's web page:
##        www.informatik.uni-konstanz.de/~kuehl/newich.html
##        contains valuable information regarding C++ programming.
##        Danke auch an Dietmar.
##
##    This code differs in some ways from the StatusBox-Code:
##    - the Log class is not 'self-instantiating'
##    - it is compilable with VisualC++
##    - the error and warning-functions are not disabled in release-mode
##    - additional functionality: LogInit(), Show(), Hide(), IsVisible(), 
##      IsActive(), Activate(), DeActivate(), LogTimerXY(), stdio-redirection
##    - output-functions are checking errno
##    - Log requires the use of ugly double-parenthesis'. If you can't stand 
##      this, this is not for you. The Log-Functions are not nice to call
##      without these ether.
##    - redirecting of stdio
##    
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

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ INCLUDES: ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#define NEVER_REDIRECT_MYSELF 1

#include "log.hpp"

// set Warning-level of MS-VisualC++ for this file to 4:
#if WIN32 && _MSC_VER
#pragma warning(push,4)
#endif


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ DEFINES: ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* see NEVER_REDIRECT_MYSELF above, otherwise: */
/* none */

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ MACROS: ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* none */

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ TYPE DEFINITIONS: ~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* none */

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ EXPORTED VARS: ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* none */

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ GLOBAL VARS: ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
bool log_initialised  = false;

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~ STATIC CLASS VARS: ~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
Log *Log::log_hdl     = 0;              // self-reference of singleton 
int  Log::one_loop    = false;          // dummy-loop counter for the macros

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ LOCAL PROTOTYPES: ~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* none */

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~ EXPORTED PROTOTYPES: ~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* none */


/*
###############################################################################
## FUNCTION:   Show
## TYPE:       static memeber function, callback
## ----------------------------------------------------------------------------
## PARAMETER:  -
## RETURNS:    - 
## ----------------------------------------------------------------------------
## DESCRIPTION:
## prepares closing of Log-window
## ----------------------------------------------------------------------------
## VERSION:  DATE:       AUTHOR: CHANGES:
## 1.0       24-Mar-2000 CLu     creation
###############################################################################
*/
void Log::Show(void)
{
log_hdl->visible = true;    // shows the log-window

#if FLTK
  log_hdl->show(); 
#elif CLASSWORKX
  ShowWindow(log_hdl->getHandle(),1);
#endif
} // End of: Log::Show()

/*
###############################################################################
## FUNCTION:   Hide
## TYPE:       static memeber function, callback
## ----------------------------------------------------------------------------
## PARAMETER:  -
## RETURNS:    - 
## ----------------------------------------------------------------------------
## DESCRIPTION:
## prepares closing of Log-window
## ----------------------------------------------------------------------------
## VERSION:  DATE:       AUTHOR: CHANGES:
## 1.0       24-Mar-2000 CLu     creation
###############################################################################
*/
void Log::Hide(void)      
{
log_hdl->visible = false;    // hides the log-window

#if FLTK
  log_hdl->hide(); 
#elif CLASSWORKX
  ShowWindow(log_hdl->getHandle(),0);
#endif
} // End of: Log::Hide()


/*
###############################################################################
## FUNCTION:   RedirectStdio
## TYPE:       static memeber function
## ----------------------------------------------------------------------------
## PARAMETER:  -
## RETURNS:    - 
## ----------------------------------------------------------------------------
## DESCRIPTION:
## activates redirection of stdio, 
## classic (printf,...) and C++-streams (cout,...)
## ----------------------------------------------------------------------------
## VERSION:  DATE:       AUTHOR: CHANGES:
## 1.0       31-Jan-2003 CLu     creation
###############################################################################
*/
void Log::RedirectStdio(void)      
{
redirect_stdio = true;

#if IOSTREAM_OLDSTYLE
cout  =  log_hdl->my_cout;
cerr  =  log_hdl->my_cerr;
#elif IOSTREAM_STL
// redirect cout/cerr by setting the buffers:   
cout.rdbuf(log_hdl->my_cout->rdbuf());
cerr.rdbuf(log_hdl->my_cerr->rdbuf());
#endif // IOSTREAM_x
}

/*
###############################################################################
## FUNCTION:   RedirectStdio
## TYPE:       static memeber function
## ----------------------------------------------------------------------------
## PARAMETER:  -
## RETURNS:    - 
## ----------------------------------------------------------------------------
## DESCRIPTION:
## deactivates redirection of stdio, 
## classic (printf,...) and C++-streams (cout,...)
## ----------------------------------------------------------------------------
## VERSION:  DATE:       AUTHOR: CHANGES:
## 1.0       31-Jan-2003 CLu     creation
###############################################################################
*/
void Log::DirectStdio(void)      
{ 
redirect_stdio = false; 

#if IOSTREAM_OLDSTYLE
cout = log_hdl->cout_backup;      // hmmm, this does not work well...
cerr = log_hdl->cerr_backup;
#elif IOSTREAM_STL
// restore standard output-streams:
cout.rdbuf(log_hdl->cout_backup);
cerr.rdbuf(log_hdl->cerr_backup);
#endif // IOSTREAM_x

}


/*
###############################################################################
## FUNCTION:   cb_quit
## TYPE:       static memeber function, callback
## ----------------------------------------------------------------------------
## PARAMETER:  -
## RETURNS:    - 
## ----------------------------------------------------------------------------
## DESCRIPTION:
## prepares closing of Log-window
## ----------------------------------------------------------------------------
## VERSION:  DATE:       AUTHOR: CHANGES:
## 1.0       24-Mar-2000 CLu     creation
###############################################################################
*/
void Log::cb_quit(void) 
{
#if FLTK
  log_hdl->log_out_stream_widget->clear();
#elif CLASSWORKX
  log_hdl->log_out_stream_widget->deleteAllEntries();
#endif

log_hdl->DeActivate();
log_hdl->Hide();
} // End of: cb_quit()


/*
###############################################################################
## FUNCTION:   cb_clear
## TYPE:       static memeber function, callback
## ----------------------------------------------------------------------------
## PARAMETER:  -
## RETURNS:    - 
## ----------------------------------------------------------------------------
## DESCRIPTION:
## Clears the Log-windows log_out_stream_widget
## ----------------------------------------------------------------------------
## VERSION:  DATE:       AUTHOR: CHANGES:
## 1.0       24-Mar-2000 CLu     creation
###############################################################################
*/
void Log::cb_clear(void) 
{
#if FLTK
  log_hdl->log_out_stream_widget->clear();
#elif CLASSWORKX
  log_hdl->log_out_stream_widget->deleteAllEntries();
#endif
} // End of: cb_clear()


// with ClassworkX, the clear_button_cl is needed 
// to tie the 'onClick'-event to the GUI-Object
#if CLASSWORKX
bool clear_button_cl::onClicked(void)
{
Log::cb_clear();
return true;
}
#endif // !CLASSWORKX



/*
###############################################################################
## FUNCTION:   cb_hide
## TYPE:       static memeber function, callback
## ----------------------------------------------------------------------------
## PARAMETER:  -
## RETURNS:    - 
## ----------------------------------------------------------------------------
## DESCRIPTION:
## Hides the Log-window
## ----------------------------------------------------------------------------
## VERSION:  DATE:       AUTHOR: CHANGES:
## 1.0       24-Mar-2000 CLu     creation
###############################################################################
*/
void Log::cb_hide(void) 
{
log_hdl->Hide();
} // End of: cb_hide()

// with ClassworkX, the hide_button_cl is needed 
// to tie the 'onClick'-event to the GUI-Object
#if CLASSWORKX
bool hide_button_cl::onClicked(void)
{
Log::cb_hide();
return true;
}
#endif // CLASSWORKX



/*
###############################################################################
## FUNCTION:   cb_active
## TYPE:       static memeber function, callback
## ----------------------------------------------------------------------------
## PARAMETER:  -
## RETURNS:    - 
## ----------------------------------------------------------------------------
## DESCRIPTION:
## toggles the activity-state of the logging
## ----------------------------------------------------------------------------
## VERSION:  DATE:       AUTHOR: CHANGES:
## 1.0       09-Jan-2003 CLu     creation
###############################################################################
*/
void Log::cb_active(void) 
{

if (LogIsActive())  log_hdl->DeActivate();
else                log_hdl->Activate();

} // End of: cb_active()


/*
###############################################################################
## FUNCTION:   SaveState_MC
## TYPE:       exported, MACRO-covered
## ----------------------------------------------------------------------------
## PARAMETER:  parm_log_level -  logging level, kind of next output
##             param_errno    -  system's errno
##             param_file     -  __FILE__
##             param_line     -  __LINE__
##             param_date     -  __DATE__
##             param_time     -  __TIME__
## RETURNS:    -
## ----------------------------------------------------------------------------
## DESCRIPTION:
## saves the current state of the function bevore printing
## ----------------------------------------------------------------------------
## VERSION:  DATE:       AUTHOR: CHANGES:
## 1.0       21-Mar-2000 CLu     taken from cpErrSetGlobals V. 1.1 
###############################################################################
*/
void Log::SaveState_MC( const int param_log_level, const int param_errno, const char *param_file, const long param_line, const char *param_date, const char *param_time )
{
log_level = param_log_level;
log_errno = param_errno;
log_file  = param_file;
log_line  = param_line;
log_date  = param_date;
log_time  = param_time;
} // End of: SaveState_MC


/*
###############################################################################
## FUNCTION:   LogPrintf_MC
## TYPE:       exported, Macro-Covered
## ---------------------------------------------------------------------------
## PARAMETER:  format, ...  - formatstring and variable parameters like printf
## RETURNS:    -
## ---------------------------------------------------------------------------
## DESCRIPTION:
## This funtions sole purpose is to replace the plain printf-calls in newly
## added 'old-style' source-code.
## ---------------------------------------------------------------------------
## VERSION:  DATE:       AUTHOR: CHANGES:
## 0.1       11-Mar-2000 CLu     creation
###############################################################################
*/
int Log::LogPrintf_MC( const char *format, ...) 
{
va_list arg_ptr;                                  /* variable parameterlist */
int ret = 0;

if (format == 0) return 0;

va_start(arg_ptr,format);

if (redirect_stdio)
   {
   ret = Log::log_hdl->LogVPrintf(format,arg_ptr);
   }
else
   {
   vprintf(format,arg_ptr);
   if (log_level != LOG_UNSET) printf("\n");  // ouch, not nice...

   }
va_end(arg_ptr);

return ret;
}

/*
###############################################################################
## FUNCTION:   LogFPrintf_MC
## TYPE:       exported, Macro-Covered
## ---------------------------------------------------------------------------
## PARAMETER:  file_ptr     - pointer to the file, to which the output goes
##             format, ...  - formatstring and variable parameters like printf
## RETURNS:    -
## ---------------------------------------------------------------------------
## DESCRIPTION:
## Prints a formatted text to the Log-Window 
## ---------------------------------------------------------------------------
## VERSION:  DATE:         AUTHOR:   CHANGES:
## 0.1       11-Mar-2000   CLu    creation
###############################################################################
*/
#if (PLX_MSWIN32 && PLX_MSVCPP)
    int  Log::LogFPrintf_MC( struct _iobuf *file_ptr, const char *format, ...)
#else
    int  Log::LogFPrintf_MC( FILE *file_ptr, const char *format, ...)
#endif

{
va_list arg_ptr;                          /* Variable Parameterliste      */
int ret = 0;

if (file_ptr == 0) return 0;  // oops... 
if (format == 0) return 0;

va_start(arg_ptr,format);

if (  redirect_stdio 
      && (   (file_ptr == stderr) 
          || (file_ptr == stdout) ) )
   {
   ret = Log::log_hdl->LogVPrintf(format,arg_ptr);
   }
else
   {
   ret = vfprintf(file_ptr,format,arg_ptr);
   }

va_end(arg_ptr);

return ret;
}

/*
###############################################################################
## FUNCTION:   LogVPrintf_MC
## TYPE:       exported, Macro-Covered
## ---------------------------------------------------------------------------
## PARAMETER:  format, ...  - formatstring and variable parameters like printf
## RETURNS:    -
## ---------------------------------------------------------------------------
## DESCRIPTION:
## Prints a formatted Text to the Log-Window 
## Cause the Log-Functions cover standard-formatted output (via xyzPrintf) and
## streaming output (cout <<), there is a problem in detecting where the next
## output has to be printed (next/same line). In order to overcome this, the 
## following scheme is used:
##  - printf output starts a new line, if the last line isn't empty
##  - printf-output creates a new, empty line after its own line(s)
##  - streaming output is appended to the content of the last line
##  - streaming output only generates new lines, when /n's are encountered
## ---------------------------------------------------------------------------
## TODO:
## - FLTK: formatting of new-lines, output to multiple lines
## - CLASSWORKX: formatting of tabs
## ---------------------------------------------------------------------------
## VERSION:  DATE:         AUTHOR:   CHANGES:
## 0.1       11-Mar-2000   CLu    creation
###############################################################################
*/
int Log::LogVPrintf( const char *format, va_list arg_ptr) 
{
//#define PRINT_BUF_SZ 1024
//static char print_buf[PRINT_BUF_SZ];
int ret  = 0;
int fpos = 0;
int lastline = 0;

if (this == (Log*)0) return -1;
if (!initialised) return 0;
if (    !active 
    && (log_level != LOG_ERROR)
   ) return 0; // if log_level is ERROR ignore deactivation!

print_buf[0] = '\0';

#if FLTK
  lastline = log_out_stream_widget->size();      
  const char *line_content = log_out_stream_widget->text(lastline);
  if (line_content != 0)                      // Line does exist
     {
     if (strlen(line_content) == 0)           // Line is empty
        {
        log_out_stream_widget->remove(lastline);               // delete empty line
        }
     }
#elif CLASSWORKX
  lastline = log_out_stream_widget->getCount()-1;              // getCount()-1 is the correct last line-index!
  if (log_out_stream_widget->getTextLength(lastline) == 0)     // Line is empty
     {
     log_out_stream_widget->deleteString(lastline);            // delete empty line
     }
#endif

#if FLTK
switch (log_level)
       {
       default:
       case LOG_INFO:  sprintf(print_buf, "@s@b@B%d@C%d@.", log_bg_color, FL_BLACK);
                       break;
       case LOG_WARN:  sprintf(print_buf, "@s@b@B%d@C%d@.", log_bg_color, FL_BLUE );
                       break;
       case LOG_DEBUG: sprintf(print_buf, "@s@b@B%d@C%d@.", log_bg_color, FL_BLACK);
                       break;
       case LOG_ERROR: sprintf(print_buf, "@s@b@B%d@C%d@.", log_bg_color, FL_RED);   this->Show();
                       break;
       case LOG_TSTART:sprintf(print_buf, "@s@b@B%d@C%d@.", log_bg_color, FL_DARK_GREEN);
                       break;break;
       case LOG_TSTOP: clock_t duration = (timer_stop-timer_start);
                       sprintf(print_buf, "@s@b@B%d@C%d@.Timed %.2f sec, %ld Ticks: ", log_bg_color, FL_DARK_GREEN, ((double)duration/CLOCKS_PER_SEC),(long)duration);
                       break;
       }
#elif CLASSWORKX
  //No way to set text color and font on a by-line/by-character basis
#endif

log_level = LOG_UNSET;      // clear Log-level before next output

fpos = strlen(print_buf);

#if PLX_MSC || PLX_MSVCPP
ret = _vsnprintf(print_buf+fpos,PRINT_BUF_SZ-fpos-2,format,arg_ptr);  
if (ret == -1)  /* Ausgabestring zu lang */
   {
   print_buf[PRINT_BUF_SZ-2] = '\0';
   }
#else /* !MSC && !MSVCPP */
if (strlen(format) > print_buf_sz-2)
   {
   log_out_stream_widget->add("LOG-ERROR: Formatstring too large, no formatting done:");
   log_out_stream_widget->add(print_buf);      /* nur der Formatstring wird ausgegeben */
   return -1;
   }
else
   {
   ret = vsprintf(print_buf+fpos,format,arg_ptr);  
   if (ret > (int) print_buf_sz-fpos-2)  /* durchgefuehrte Ausgabe war zu lang */
      {
      print_buf[print_buf_sz-2] = '\0';
      log_out_stream_widget->add("LOG-ERROR: Formatstring too large, code/data are probably damaged!!!\n");
      }
   }
#endif  /* !MSC && !MSVCPP */

// The main output:
#if FLTK
  log_out_stream_widget->add(print_buf);
#elif CLASSWORKX
  log_out_stream_widget->addString(print_buf);
#endif

// additional output in case LOG_ERROR or ernno ist set:
if ( (log_errno != 0) || (log_level == LOG_ERROR) )
   {

#if FLTK
   sprintf(print_buf, "@s@b@s@B%d@C%d@.ERROR bevor %s [%ld], of %s, %s:", log_bg_color, FL_RED, log_file, log_line, log_date, log_time);
   log_out_stream_widget->add(print_buf); 
#elif CLASSWORKX
   sprintf(print_buf, "ERROR bevor %s [%ld], of %s, %s:", log_file, log_line, log_date, log_time);
   log_out_stream_widget->addString(print_buf); 
#endif

   if (log_errno != 0) 
      {
#if FLTK
      sprintf(print_buf, "@s@b@s@B%d@C%d@.errno = %3d: %s.", log_bg_color, FL_RED, log_errno, strerror(log_errno));
      log_out_stream_widget->add(print_buf);  
#elif CLASSWORKX
      sprintf(print_buf, "errno = %3d: %s.", log_errno, strerror(log_errno));
      log_out_stream_widget->addString(print_buf);
#endif
      errno = 0;      
      }
   }

#if FLTK
  log_out_stream_widget->add("");                                // add a new line for the next writes, in case the next are streamed!
  log_out_stream_widget->bottomline(log_out_stream_widget->size());               // follow output, newest output stays visible
#elif CLASSWORKX
  log_out_stream_widget->addString("");                           // add a new line for the next writes, in case the next are streamed!
  log_out_stream_widget->setCurrentSelection(log_out_stream_widget->getCount()-1); // follow output, newest output stays visible
  log_out_stream_widget->setCurrentSelection((size_t)-1);         // 'hide' selection
#endif

return 0;
} // End of: LogPrintf_MC


/*
###############################################################################
## FUNCTION:   PutSn
## TYPE:       class Member of LogOutStreamWidget
## ---------------------------------------------------------------------------
## PARAMETER:  str  -  string to print
##             len  -  length of string
## RETURNS:    -
## ---------------------------------------------------------------------------
## DESCRIPTION:
## Puts unformatted Text to the Log-Window 
## Cause the Log-Functions cover standard-formatted output (via xyzPrintf) and
## streaming output (cout <<), there is a problem in detecting where the next
## output has to be printed (next/same line). In order to overcome this, the 
## following scheme is used:
##  - printf output starts a new line, if the las line isn't empty
##  - Printf-output creates a new, empty line after its own line(s)
##  - streaming output is appended to the content of the last line
##  - streaming output only generates new lines, when /n's are encountered
## ---------------------------------------------------------------------------
## VERSION:  DATE:         AUTHOR:   CHANGES:
## 0.1       11-Mar-2000   CLu       creation
## 0.2       08-Jan-2003   CLu       output only when log is active
###############################################################################
*/
void LogOutStreamWidget::PutSn(const char *str, int len)
{
static char PutSn_stream_buf[1024];
bool        contains_newline = false;
size_t      lastline = 0L;
int         oldstring_end = 0;

if (!LogIsActive())  return;

PutSn_stream_buf[0] = '\0';  // 'clear' string buffer

if (str == 0) return;
if (len == 0) return;



#if FLTK
  lastline = size();      
  const char *line_content = text(lastline);
  if (line_content != 0)              // Line contains text    
     {
     strcpy(PutSn_stream_buf,line_content);
     oldstring_end = strlen(PutSn_stream_buf);
     }
#elif CLASSWORKX
  long text_len = 0;
  lastline = getCount()-1;            // getCount()-1 is the correct line-index!
  text_len = getTextLength(lastline);
  if (text_len != -1)                 // Line contains text
     {
     strcpy(PutSn_stream_buf,getText(lastline).c_str());
     oldstring_end = strlen(PutSn_stream_buf);
     }
#endif

strncat(PutSn_stream_buf, str, len);

char *substringstart = PutSn_stream_buf; 
int   substringlen   = 0;
char *substringend   = PutSn_stream_buf+oldstring_end;   // search only new part for newlines
int   fullstringlen  =                0+oldstring_end;

while ( (*substringend != '\0') && (fullstringlen < oldstring_end+len) )
      {
      if (*substringend == '\n') 
         {
         *substringend = '\0';            // damages string

#if FLTK
         text(lastline,substringstart);   // add to current line
         add("");                         // and add a new line for the next writes!
         bottomline(lastline);            // follow output, newest output stays visible
#elif CLASSWORKX
         deleteString(lastline);
         addString(substringstart);
         addString("");
#endif

         substringstart = substringend;   // start new substring
         substringlen=0; 
         contains_newline = true;
         }
      substringend++; substringlen++; fullstringlen++;
      }



if (!contains_newline)                 // this should be the normal case
   {
#if FLTK
//   Log::log_hdl->LogPrintf_MC("%s",substringstart);
   text(lastline,substringstart);
   bottomline(lastline);               // follow output, newest output stays visible
#elif CLASSWORKX
   deleteString(lastline);
   addString(substringstart);
   setCurrentSelection(getCount()-1);  // follow output, newest output stays visible
   setCurrentSelection((size_t)-1);    // 'hide' selection
#endif
   }

return;
}

/*
###############################################################################
## FUNCTION:   PutC
## TYPE:       class member of LogOutStreamWidget
## ---------------------------------------------------------------------------
## PARAMETER:  chr - the character to print
## RETURNS:    -
## ---------------------------------------------------------------------------
## DESCRIPTION:
## Cause the Log-Functions cover standard-formatted output (via xyzPrintf) and
## streaming output (cout <<), there is a problem in detecting where the next
## output has to be printed (next/same line). In order to overcome this, the 
## following scheme is used:
##  - printf output starts a new line, if the las line isn't empty
##  - Printf-output creates a new, empty line after its own line(s)
##  - streaming output is appended to the content of the last line
##  - streaming output only generates new lines, when /n's are encountered
## ---------------------------------------------------------------------------
## VERSION:  DATE:         AUTHOR:   CHANGES:
## 0.1       11-Mar-2000   CLu    creation
###############################################################################
*/
void LogOutStreamWidget::PutC( int chr)
{
static char PutC_stream_buf[1024];
char app[2];
       
PutC_stream_buf[0] = '\0';  // 'clear' string buffer

app[0] = (char) chr;
app[1] = 0;


#if FLTK
  int lastline = size();
  const char *line_content =  text(lastline);
#elif CLASSWORKX
  int lastline = getCount()-1;
  const char *line_content =  getText(lastline).c_str();
#endif

if (line_content != 0)
   {
   strcpy(PutC_stream_buf,line_content);  
   }

strcat(PutC_stream_buf, app);

#if FLTK
   text(lastline,PutC_stream_buf);      
   bottomline(lastline);            // follow output, newest output stays visible
#elif CLASSWORKX
   deleteString(lastline);
   addString(PutC_stream_buf);
   setCurrentSelection(getCount()-1);  // follow output, newest output stays visible
   setCurrentSelection((size_t)-1);    // 'hide' selection
#endif

return;
}


/*
###############################################################################
## FUNCTION:   Init
## TYPE:       Initilaisierungsfunktion, Macro-Covered -> LogInit
## ---------------------------------------------------------------------------
## PARAMETER:  x, y     - Screen-Coordinates of upper left corner of LogWindow
##             w, h     - width and height of LogWindow
##             title    - window-title
##             bg_color - background color
## RETURNS:    pointer to Log-Instance
## ---------------------------------------------------------------------------
## DESCRIPTION:
## just calls the constructor of Log. Function is needed to get the pointer
## to the singleton-log-instance, which is neccesary for the macros!!
## ---------------------------------------------------------------------------
## VERSION:  DATE:       AUTHOR: CHANGES:
## 0.1       23-Mar-2000 CLu     creation
###############################################################################
*/
Log *Log::Init(int x, int y, int w, int h, const char *title, char bg_color, bool redirect_stdio_par)
{
int ret = 0;

if (log_hdl == 0)
   {
   log_hdl = new Log(x, y, w, h, title, bg_color);
   }

if (log_hdl == 0)
   {
   log_initialised = false;
   return 0;
   }

log_initialised = true;

log_hdl->redirect_stdio = redirect_stdio_par;

if ( log_hdl->redirect_stdio )
   {

#if IOSTREAM_OLDSTYLE

   // save output buffer of the standard cout/cerr streams:
   log_hdl->cout_backup = cout;
   log_hdl->cerr_backup = cerr;

   // create stream-to-widget connectors:   
   log_hdl->my_cout = new OutputWidgetStream(LOG_INFO,  log_hdl->log_out_stream_widget, log_hdl->log_stream_buf, OWSTREAM_BUFF_SIZE);  
   log_hdl->my_cerr = new OutputWidgetStream(LOG_ERROR, log_hdl->log_out_stream_widget, log_hdl->log_stream_buf, OWSTREAM_BUFF_SIZE);  

   // redirect cout/cerr by assigning the streams:   
   cout  =  log_hdl->my_cout;
   cerr  =  log_hdl->my_cerr;

#elif IOSTREAM_STL

   // save output buffer of the standard cout/cerr streams:
   log_hdl->cout_backup = cout.rdbuf();
   log_hdl->cerr_backup = cerr.rdbuf();

   // create stream-to-widget connectors:   
   log_hdl->my_cout  = new OutputWidgetStream( LOG_INFO, log_hdl->log_out_stream_widget, log_hdl->log_stream_buf,OWSTREAM_BUFF_SIZE); 
   log_hdl->my_cerr  = new OutputWidgetStream( LOG_ERROR, log_hdl->log_out_stream_widget, log_hdl->log_stream_buf,OWSTREAM_BUFF_SIZE); 
   
   // redirect cout/cerr by setting the buffers:   
    cout.rdbuf(log_hdl->my_cout->rdbuf());
    cerr.rdbuf(log_hdl->my_cerr->rdbuf());

#endif //IOSTREAM_x
   }


/*####### EXIT-Initialisierung: #######*/
ret = atexit(log_hdl->DeInit);
if (ret != 0)
   {
   fprintf(stderr,"Error: atexit(log_hdl->DeInit) failed, returns :%d",ret);
   }

#ifdef L_DEBUG
log_hdl->Activate();
log_hdl->Show();
#endif // L_DEBUG 

return log_hdl;
} // End of: Init()

/*******************************
*
* Added by Yewberry
*
*
********************************/
Log *Log::Init(Log *log, bool redirect_stdio_par)
{
int ret = 0;

if (log_hdl != 0){
	Log::DeInit();
}
if (log_hdl == 0)
   {
   log_hdl = log;
   }

if (log_hdl == 0)
   {
   log_initialised = false;
   return 0;
   }

log_initialised = true;

log_hdl->redirect_stdio = redirect_stdio_par;

if ( log_hdl->redirect_stdio )
   {

#if IOSTREAM_OLDSTYLE

   // save output buffer of the standard cout/cerr streams:
   log_hdl->cout_backup = cout;
   log_hdl->cerr_backup = cerr;

   // create stream-to-widget connectors:   
   log_hdl->my_cout = new OutputWidgetStream(LOG_INFO,  log_hdl->log_out_stream_widget, log_hdl->log_stream_buf, OWSTREAM_BUFF_SIZE);  
   log_hdl->my_cerr = new OutputWidgetStream(LOG_ERROR, log_hdl->log_out_stream_widget, log_hdl->log_stream_buf, OWSTREAM_BUFF_SIZE);  

   // redirect cout/cerr by assigning the streams:   
   cout  =  log_hdl->my_cout;
   cerr  =  log_hdl->my_cerr;

#elif IOSTREAM_STL

   // save output buffer of the standard cout/cerr streams:
   log_hdl->cout_backup = cout.rdbuf();
   log_hdl->cerr_backup = cerr.rdbuf();

   // create stream-to-widget connectors:   
   log_hdl->my_cout  = new OutputWidgetStream( LOG_INFO, log_hdl->log_out_stream_widget, log_hdl->log_stream_buf,OWSTREAM_BUFF_SIZE); 
   log_hdl->my_cerr  = new OutputWidgetStream( LOG_ERROR, log_hdl->log_out_stream_widget, log_hdl->log_stream_buf,OWSTREAM_BUFF_SIZE); 
   
   // redirect cout/cerr by setting the buffers:   
    cout.rdbuf(log_hdl->my_cout->rdbuf());
    cerr.rdbuf(log_hdl->my_cerr->rdbuf());

#endif //IOSTREAM_x
   }


/*####### EXIT-Initialisierung: #######*/
ret = atexit(log_hdl->DeInit);
if (ret != 0)
   {
   fprintf(stderr,"Error: atexit(log_hdl->DeInit) failed, returns :%d",ret);
   }

#ifdef L_DEBUG
log_hdl->Activate();
log_hdl->Show();
#endif // L_DEBUG 

return log_hdl;
} // End of: Init(Log *log)

/*
###############################################################################
## FUNCTION:   Init
## TYPE:       Initilaisierungsfunktion, Macro-Covered -> LogInit
## ---------------------------------------------------------------------------
## PARAMETER:  -
## RETURNS:    Log-handle
## ---------------------------------------------------------------------------
## DESCRIPTION:
## just calls Log->Init with default parameters 
## ---------------------------------------------------------------------------
## VERSION:  DATE:       AUTHOR: CHANGES:
## 0.1       22-Jan-2003 CLu     creation
###############################################################################
*/
Log *Log::Init()
{
int scr_height      = Fl::h(); 
int scr_width       = Fl::w();
int log_xpos        = (scr_width / 2)-2;
int log_ypos        = (scr_height/ 2)-2;  
int log_width       = (scr_width / 2)-2;
int log_height      = (scr_height/ 2)-2;

return(Init(log_xpos,log_ypos,log_width,log_height,"Log",FL_GRAY,true));
} // End of: Init(void)

/*
###############################################################################
## FUNCTION:   LogDeInit
## TYPE:       DeInitilaising function
## ---------------------------------------------------------------------------
## PARAMETER:  -
## RETURNS:    successcode
## ---------------------------------------------------------------------------
## DESCRIPTION:
## This function just deletes the one and only Log- instance. 
## This kludge is neccessary because the Log-class is self-contained, 
## but neither self-instantiating nor self-destructing. 
## (Maybe there are better ways to do this...)
## ---------------------------------------------------------------------------
## VERSION:  DATE:         AUTHOR:   CHANGES:
## 1.0       23-Mar-2000   CLu    creation
###############################################################################
*/
void Log::DeInit( void )
{

if (log_hdl != 0)
   {
   if ( log_hdl->redirect_stdio )
      {
      // restore standard output-streams:
#if IOSTREAM_OLDSTYLE
	  cout = log_hdl->cout_backup;
	  cerr = log_hdl->cerr_backup;
#elif IOSTREAM_STL
	  cout.rdbuf(log_hdl->cout_backup);
	  cerr.rdbuf(log_hdl->cerr_backup);
#endif //IOSTREAM_x
      }

   delete log_hdl;
   log_hdl = 0;
   }

log_initialised = false;

} // End of: DeInit()



/*
###############################################################################
## FUNCTION:   Log
## TYPE:       constructor
## ---------------------------------------------------------------------------
## PARAMETER:  x, y     - Screen-Coordinates of upper left corner of LogWindow
##             w, h     - width and height of LogWindow
##             title    - window-title
##             bg_color - background color
## RETURNS:    Succes-Code
## ---------------------------------------------------------------------------
## DESCRIPTION:
## Initialisiert die fuer das Modul benötigten Daten, Windows, ...
## Don't forget: you can't call static class functions from within the 
## contructor!
## ---------------------------------------------------------------------------
## VERSION:  DATE:       AUTHOR: CHANGES:
## 0.1       28-Jan-2000 CLu     creation
## 0.2       07-Oct-2002 CLu     visible = false
###############################################################################
*/
#if FLTK
Log::Log(int x_par=0, int y_par=0, int w_par=400, int h_par=200, const char *title="Log", char bg_color=FL_GRAY)
    :Fl_Window(x_par, y_par, w_par, h_par, title)
#elif CLASSWORKX
Log::Log(int x_par=0, int y_par=0, int w_par=400, int h_par=200, const char *title="Log", char bg_color=0)
    :CXIDSWindow()
#endif
{
print_buf_sz   = (size_t) 1024;           /* size of allocated buffer */
print_buf      = new char[print_buf_sz];  /* for sprintf-conversions  */

log_level    = 0;                /* logging level                  */
log_errno    = 0;                /* errno-number                   */
log_file     = (char*) NULL;     /* source-module-name             */
log_line     = -1L;              /* Line in source-file            */
log_date     = (char*) NULL;     /* file compile date              */
log_time     = (char*) NULL;     /* file compile time              */

timer_start = (clock_t) 0;
timer_stop  = (clock_t) 0;

#if FLTK
  callback( (Fl_Callback *) cb_quit );

  log_out_stream_widget = new LogOutStreamWidget(2, 2, w_par-2, h_par-26);
  log_out_stream_widget->color(bg_color);
  log_out_stream_widget->textfont(FL_COURIER);
  //log_out_stream_widget->textsize(10);

#if L_DEBUG
  const char* label_append = "  (DEBUG-Mode)";
#else
  const char* label_append = "  (RELEASE-Mode)";
#endif // L_DEBUG
  int label_len = strlen(this->label())+strlen(label_append)+2;
  label_buf = (char*) malloc(label_len);
  strcpy(label_buf,this->label());
  strcat(label_buf,label_append);
  this->label(label_buf);

  Fl_Group::current()->resizable(log_out_stream_widget);
     
  clear_button  = new Fl_Button(2,           h_par-22, w_par/3-2, 20, "clear");
  hide_button   = new Fl_Button(2+w_par/3,   h_par-22, w_par/3-2, 20, "hide");
  active_button = new Fl_Light_Button(2+2*w_par/3, h_par-22, w_par/3-2, 20, "active");
 
    hide_button->callback((Fl_Callback*) cb_hide);
   clear_button->callback((Fl_Callback*) cb_clear);
  active_button->callback((Fl_Callback*) cb_active);
  active_button->selection_color(FL_GREEN);
  active_button->set();

  end();

#elif CLASSWORKX

/*
pWindow = new CXIDSWindow(pDAGApp);
*/
setTitle(title);
/*
setParent(pDAGApp->DAGGerWindow);       // Applications Main-Window is parent
setAutoDeleteOnClosed(true);
*/

log_out_stream_widget = new LogOutStreamWidget(x_par,y_par,w_par,h_par);
log_out_stream_widget->setFlex(CXIDSObject::Vertical | CXIDSObject::Horizontal);
log_out_stream_widget->setStyle(CXIDSListbox::Single);
log_out_stream_widget->setFont(CXIDSApplication::Fixed);

clear_button = new clear_button_cl;
clear_button->setText("Clear");
clear_button->setHeight(10, CXIDSApplication::DialogUnit);
clear_button->setFlex(CXIDSObject::Horizontal);

hide_button  = new hide_button_cl;
hide_button->setText("Hide");
hide_button->setHeight(10, CXIDSApplication::DialogUnit);
hide_button->setFlex(CXIDSObject::Horizontal);
hide_button->setDefaultButton(true);

h_panel1 = new CXIDSPanel;
h_panel1->setDirection(CXIDSPanel::Horizontal);
h_panel1->setFlex(CXIDSObject::Horizontal);
h_panel1->setAutoSpace(true);
h_panel1->add(clear_button);
h_panel1->add(hide_button);

v_panel1 = new CXIDSPanel;
v_panel1->setDirection(CXIDSPanel::Vertical);
v_panel1->setFlex(CXIDSObject::Vertical | CXIDSObject::Horizontal);
v_panel1->add(log_out_stream_widget);
v_panel1->add(h_panel1);

setContent(v_panel1);
restorePlacement();
open(true);                    // Open Log window

#endif // !(FLTK || CLASSWORKX)


log_bg_color  = bg_color; /* Background color of log window */
initialised   = true;
active        = true;
visible       = false;

return;
} // End of: Log-Constructor


/*
###############################################################################
## FUNCTION:   ~Log
## TYPE:       destructor, deinitialising function
## ---------------------------------------------------------------------------
## PARAMETER:  --
## RETURNS:    --
## ---------------------------------------------------------------------------
## DESCRIPTION:
## Deinitialisiert die von der zugehoerigen Init-Funktion initialisierten 
## Daten, schliest Windows, gibt angeforderten Speicher frei, ...
## ---------------------------------------------------------------------------
## VERSION:  DATE:       AUTHOR: CHANGES:
## 0.1       28-Jan-2000 CLu     creation
###############################################################################
*/
Log::~Log(void)
{

initialised = false;

if (print_buf != (char*) 0)
   {
   delete print_buf;
   print_buf = (char*) 0;
   }

if (label_buf != (char*) 0)
   {
   free(label_buf);
   label_buf = (char*) 0;
   }

return;
} // End of: Log-Destructor



/*
###############################################################################
## FUNCTION:   LogOutStreamWidget
## TYPE:       constructor
## ---------------------------------------------------------------------------
## PARAMETER:  x,y  - coordinates of window
##             w,h  - width and height of window
## RETURNS:    --
## ---------------------------------------------------------------------------
## DESCRIPTION:
## creates the Log-window
## ---------------------------------------------------------------------------
## VERSION:  DATE:       AUTHOR: CHANGES:
## 0.1       28-Jan-2000 CLu     creation
###############################################################################
*/

#if FLTK
LogOutStreamWidget::LogOutStreamWidget(int x_par, int y_par, int w_par, int h_par)
                   :Fl_Browser( x_par, y_par, w_par, h_par)
#elif CLASSWORKX
LogOutStreamWidget::LogOutStreamWidget(int x_par, int y_par, int w_par, int h_par)
                   :CXIDSListbox()
#endif
{
#if CLASSWORKX
#pragma warning(push)
#pragma warning(disable:4100)
x_par=x_par;  // warnings away...
y_par=y_par;  // warnings away...
setWidth( w_par, CXIDSApplication::Pixel);
setHeight(h_par, CXIDSApplication::Pixel);
#pragma warning(pop)
#endif // CLASSWORKX
}



/*
###############################################################################
## FUNCTION:   WidgetStreamBuf
## TYPE:       constructor
## ---------------------------------------------------------------------------
## PARAMETER:  LogOutStreamWidget - the widget to output to
##             buffer
##             buffer_size
## RETURNS:    --
## ---------------------------------------------------------------------------
## DESCRIPTION:
## Initialize the 'wid' member which identifies into which Widget the
## output has to go
## If buffering is desired, use the given buffer
## Setup the buffer pointers from streambuf
## The function 'streambuf::setp()' is used to setup the pointers of the put area
## while 'streambuf::setg()' is used for the pointers of the get area. Since
## the current implementation of WidgetStreamBuf can't be used for input from a Widget
## (I don't know exactly what is desired when trying to 'read' from a Widget)
## the pointers of the get area are initialized to be 0.
## ---------------------------------------------------------------------------
## VERSION:  DATE:       AUTHOR: CHANGES:
## 1.1       28-Jan-2000 CLu     conversion for FLTK/CLASSWORKX
## 1.2       28-Jan-2003 CLu     adaption for IOSTREAM_STL
###############################################################################
*/

#if IOSTREAM_OLDSTYLE
WidgetStreamBuf::WidgetStreamBuf(LogOutStreamWidget *widget, char* buffer, int buffer_size)
                :streambuf()
#elif IOSTREAM_STL
WidgetStreamBuf::WidgetStreamBuf(LogOutStreamWidget *widget, char* buffer, int buffer_size)
                :basic_streambuf<char>()
#endif // IOSTREAM_x
{
wid = widget;

if (buffer_size)
   {
   setp(buffer, buffer+buffer_size);
   }
else
   {
   setp(0, 0);
   }

setg(0, 0, 0);

}


/*
###############################################################################
## FUNCTION:   WidgetStreamBuf
## TYPE:       destructor
## ---------------------------------------------------------------------------
## PARAMETER:  --
## RETURNS:    --
## ---------------------------------------------------------------------------
## DESCRIPTION:
## The destructor of WidgetStreamBuf simply makes sure that every output is
## really send to the widget. This is done by calling 'sync()'.
## ---------------------------------------------------------------------------
## VERSION:  DATE:       AUTHOR: CHANGES:
## 1.1       28-Jan-2000 CLu     conversion for FLTK/CLASSWORKX
###############################################################################
*/
WidgetStreamBuf::~WidgetStreamBuf()
{
sync();
//delete[] pbase();
}


/*
###############################################################################
## FUNCTION:   overflow
## TYPE:       member function of class WidgetStreamBuf
## ---------------------------------------------------------------------------
## PARAMETER:  c - the char which caused the overflow
## RETURNS:    0
## ---------------------------------------------------------------------------
## DESCRIPTION:
## Whenever the put area of a streambuf is full, 'overflow()' is called.
## The argument to 'overflow()' is the character which didn't fit into the
## put area or EOF, if there is no such character. 'overflow()' is simply
## implemented by calling 'put_buffer()' which writes the current contents
## of the put area to the widget and then putting the single missing
## character. The argument to overflow is put into the put area if
## the WidgetStreamBuf is operating buffered: 'streambuf::sputc()' puts a
## single character into the put area. Otherwise the character is directly
## put into the Widget with 'put_char()'. To check whether the output
## is buffered or unbuffered, the length of the put area is used:
## 'streambuf::pbase()' points to the start of the put area and
## 'streambuf::epptr()' points to the end of the put area.
## ---------------------------------------------------------------------------
## VERSION:  DATE:       AUTHOR: CHANGES:
## 1.1       28-Jan-2000 CLu     conversion for FLTK/CLASSWORKX
###############################################################################
*/

int WidgetStreamBuf::overflow(int c)
{
put_buffer();
        
if (c != EOF)
   {
   if (pbase() == epptr()) 
      {  
      put_char(c);         // buffered Output to widget
      }
   else
      { 
      sputc((char)c);      // unbuffered Output
      }
   }

return 0;
}

/*
###############################################################################
## FUNCTION:   underflow
## TYPE:       member function of class WidgetStreamBuf
## ---------------------------------------------------------------------------
## PARAMETER:  --
## RETURNS:    0
## ---------------------------------------------------------------------------
## DESCRIPTION:
## is required, but useful only for stream-input, which is not supported by Log
## ---------------------------------------------------------------------------
## VERSION:  DATE:       AUTHOR: CHANGES:
## 1.1       28-Jan-2000 CLu     conversion for FLTK/CLASSWORKX
###############################################################################
*/
int WidgetStreamBuf::underflow(void)
{
return 0;
}

/*
###############################################################################
## FUNCTION:   sync
## TYPE:       member function of class WidgetStreamBuf
## ---------------------------------------------------------------------------
## PARAMETER:  --
## RETURNS:    0
## ---------------------------------------------------------------------------
## DESCRIPTION:
## To bring the internal representation of a streambuf into synchronization
## with its external representation (remember that a streambuf represents
## a sequence of characters), the function 'sync()' is called. Since
## only writing to a WidgetStreamBuf is supported this means that the internal
## buffer has to be put into the widget. This is done by calling 'put_buffer()'.
## ---------------------------------------------------------------------------
## VERSION:  DATE:       AUTHOR: CHANGES:
## 1.1       28-Jan-2000 CLu     conversion for FLTK/CLASSWORKX
###############################################################################
*/
int WidgetStreamBuf::sync()
{
put_buffer();
return 0;
}


/*
###############################################################################
## FUNCTION:   put_char
## TYPE:       member function of class WidgetStreamBuf
## ---------------------------------------------------------------------------
## PARAMETER:  --
## RETURNS:    --
## ---------------------------------------------------------------------------
## DESCRIPTION:
## 'put_char()' appends its argument (a single character) to a widget.
## ---------------------------------------------------------------------------
## VERSION:  DATE:       AUTHOR: CHANGES:
## 1.1       28-Jan-2000 CLu     conversion for FLTK/CLASSWORKX
###############################################################################
*/
void WidgetStreamBuf::put_char(int chr)
{
wid->PutC(chr);
return;
}

/*
###############################################################################
## FUNCTION:   sputn
## TYPE:       member function of class WidgetStreamBuf
## ---------------------------------------------------------------------------
## PARAMETER:  buffer - text to output
##             len    - length of text
## RETURNS:    0
## ---------------------------------------------------------------------------
## DESCRIPTION:
## 'sputn()' appends its argument (n characters in buffer) to a widget.
## ---------------------------------------------------------------------------
## VERSION:  DATE:       AUTHOR: CHANGES:
## 1.1       28-Jan-2000 CLu     conversion for FLTK/CLASSWORKX
###############################################################################
*/
int WidgetStreamBuf::sputn( const char* buffer, int len)
{
wid->PutSn(buffer,len);  
return 0;
}

/*
###############################################################################
## FUNCTION:   put_buffer
## TYPE:       member function of class WidgetStreamBuf
## ---------------------------------------------------------------------------
## PARAMETER:  --
## RETURNS:    --
## ---------------------------------------------------------------------------
## DESCRIPTION:
## 'put_buffer()' appends the WidgetStreamBuf's buffer to the text Widget. This
## is done by first retrieving a string from the put area (the character
## sequence in the put area is not necessarily 0 terminated), then appending
## this string to the widget and finally resetting the pointers to the put
## area.
## The number of characters currently found in the put area is is calculated
## as the difference between the next put position (returned by
## 'streambuf::pptr()') and the beginning of the put area ('streambuf::pbase()').
## The details how to append the string to the Widget's text are obvious.
## To reset the pointers into the put area (mainly the pointer to the put positin)
## the values returned by 'pbase()' and 'epptr()' are used.
## ---------------------------------------------------------------------------
## VERSION:  DATE:       AUTHOR: CHANGES:
## 1.1       28-Jan-2000 CLu     conversion for FLTK/CLASSWORKX
###############################################################################
*/
void WidgetStreamBuf::put_buffer()
{

if (pbase() != pptr())
   {
   int   len = (pptr() - pbase());
   char *buffer = new char[len + 1];
        
   strncpy(buffer, pbase(), len);
   buffer[len] = 0;

   wid->PutSn(buffer,len);      
        
   setp(pbase(), epptr());
   delete [] buffer;
   }
}

/*
###############################################################################
## FUNCTION:   OutputWidgetStream
## TYPE:       constructor
## ---------------------------------------------------------------------------
## PARAMETER:  log_level_par        - logging-level
##             LogOutStreamWidget   - widget for output
##             buffer               - output-buffer
##             buffer_size          - size of buffer
## RETURNS:    --
## ---------------------------------------------------------------------------
## DESCRIPTION:
## ties widget and streambuffer together fo output
## ---------------------------------------------------------------------------
## VERSION:  DATE:       AUTHOR: CHANGES:
## 1.1       28-Jan-2000 CLu     conversion for FLTK/CLASSWORKX
## 1.2       28-Jan-2003 CLu     added version vor  IOSTREAM_STL
###############################################################################
*/
#if IOSTREAM_OLDSTYLE

OutputWidgetStream::OutputWidgetStream(int log_level_par, LogOutStreamWidget *output_widget_ptr, char* buffer, int buffer_size)
                   :ostream( new WidgetStreamBuf(output_widget_ptr, buffer, buffer_size)),
		            WidgetStreamBuf(output_widget_ptr, buffer, buffer_size) 
{
log_level = log_level_par;
}

#elif IOSTREAM_STL

#if WIN32 && _MSC_VER
#pragma warning(push)
#pragma warning(disable:4355) // warning C4355: 'this': wird in Initialisierungslisten fuer Basisklasse verwendet
#endif
OutputWidgetStream::OutputWidgetStream(int log_level_par, LogOutStreamWidget* output_widget_ptr, char* buffer, int buffer_size)
                   :basic_ostream<char>(this),
		            WidgetStreamBuf(output_widget_ptr, buffer, buffer_size)
{
log_level = log_level_par;
}
#if WIN32 && _MSC_VER
#pragma warning(pop)
#endif

#endif  // IOSTREAM_x


//reset changed Warning-Level: 
#if WIN32 && _MSC_VER
#pragma warning(pop)
#endif
