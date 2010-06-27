
#ifndef LOG_HPP
#define LOG_HPP

/*
###############################################################################
## PROJECT:                        Several
###############################################################################
## HEADER:        Log.hpp
###############################################################################
## DESCRIPTION:   Log-Window
###############################################################################
## COPYRIGHT:  
##    This program is free software; you can redistribute it and/or modify
##    it under the terms of the GNU General Public License as published by
##    the Free Software Foundation; either version 2 of the License, or
##    (at your option) any later version.
##
##    This program is distributed in the hope that it will be useful,
##    but WITHOUT ANY WARRANTY; without even the implied warranty of
##    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
##    GNU General Public License for more details.
##
##    You should have received a copy of the GNU General Public License
##    along with this program; if not, write to the Free Software
##    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
## ---------------------------------------------------------------------------
## VERSION: DATE:       AUTHOR: CHANGES:
## 0.1      23-Mar-2000 CLu     creation
## 0.5      29-Sep-2000 CLu     begin adding support for ClassworkX,
##                              merge with DagLog and cpLog
## 0.9      29-Jan-2003 CLu     differentiation between IOSTREAM_OLDSTYLE and
##                              IOSTREAM_STL
###############################################################################
*/

#if !(FLTK || CLASSWORKX)
#error Currently, either FLTK or CLASSWORKX is required to use the module 'log'!
#endif

#if WIN32 && _MSC_VER
//#define IOSTREAM_OLDSTYLE 1
#define IOSTREAM_STL 1
#elif PLX_GCC
#define IOSTREAM_STL 1
#endif

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ SUB-INCLUDES: ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

#if   IOSTREAM_OLDSTYLE
#include <iostream.h>
#elif IOSTREAM_STL
#include <iostream>
using namespace std;
#endif //IOSTREAM

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <time.h>


#if FLTK

#include <FL/Fl.H>
#include <FL/Fl_Browser.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Light_Button.H>
#include <FL/Fl_Window.H>

#elif CLASSWORKX
#include <windows.h>               // Windows
#include <cx/portable.h>
#include <cx/sysinfo/profile.hpp>
#include <cx/debout/debout.hpp>
#include <cx/util/stdutil.hpp>
#include <cx/ids/about.hpp>
#include <cx/ids/app.hpp>
#include <cx/ids/array.hpp>
#include <cx/ids/brow.hpp>
#include <cx/ids/button.hpp>
#include <cx/ids/dlggrp.hpp>
#include <cx/ids/checkbox.hpp>
#include <cx/ids/combobox.hpp>
#include <cx/ids/edit.hpp>
#include <cx/ids/label.hpp>
#include <cx/ids/listbox.hpp>
#include <cx/ids/list.hpp>
#include <cx/ids/loader.hpp>
#include <cx/ids/menu.hpp>
#include <cx/ids/panel.hpp>
#include <cx/ids/radio.hpp>
#include <cx/ids/space.hpp>
#include <cx/ids/status.hpp>
#include <cx/ids/stddlg.hpp>
#include <cx/ids/tab.hpp>
#include <cx/ids/text.hpp>
#include <cx/ids/tree.hpp>
#include <cx/mds/message.hpp>
#include <cx/ids/window.hpp>
#include <cx/eds/event.hpp>
#include <cx/heap/heapstat.hpp>
#include <cx/heap/heapfacd.hpp>
#endif // CLASSWORKX


// set Warning-level of MS-VisualC++ for this file to 4:
#if WIN32 && _MSC_VER
#pragma warning(push,4)
#endif


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ DEFINES: ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
// Size of the Buffer for streaming output in Bytes
#define OWSTREAM_BUFF_SIZE 1024

#define LOG_UNSET         0
#define LOG_INFO          1
#define LOG_WARN          2
#define LOG_ERROR         3
#define LOG_DEBUG         4
#define LOG_TSTART        5
#define LOG_TSTOP         6

#if defined _DEBUG || DEBUG || CP_DBG
#define L_DEBUG 1
#endif

/* 
i did not find any statisfying/convinient (_dup()) way to redirect standard-C stdio,
so the 'trick' used here is to put a layer ontop the standard-calls and
change the output-path there. You may #undefine LOG_REDIRECTS_STDIO here,
then printf and fprintf won't get touched:
*/
#define LOG_REDIRECTS_STDIO 1

#if LOG_REDIRECTS_STDIO && !NEVER_REDIRECT_MYSELF
#define printf        Log::log_hdl->LogPrintf_MC
#define fprintf       Log::log_hdl->LogFPrintf_MC
#define vprintf       Log::log_hdl->LogVPrintf_MC
#define vfprintf      Log::log_hdl->LogVFPrintf_MC
#define puts          Log::log_hdl->LogPuts_MC
#define fputs         Log::log_hdl->LogFPuts_MC
#define putchar       Log::log_hdl->LogPutchar_MC
#define putc          Log::log_hdl->LogPutc_MC
#define fputc         Log::log_hdl->LogFPutc_MC
#endif // LOG_REDIRECTS_STDIO


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ MACROS: ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#if L_DEBUG
// these function-calls are only available/active/existent, if the application is compiled in DEBUG-Mode:
#define LogInfo(args)    do { \
                            Log::log_hdl->SaveState_MC( LOG_INFO, errno, __FILE__, __LINE__, __DATE__, __TIME__ ); \
                            Log::log_hdl->LogPrintf_MC  args ; \
                            } while( Log::one_loop )

#define LogDebug(args)   do { \
                            Log::log_hdl->SaveState_MC( LOG_DEBUG, errno, __FILE__, __LINE__, __DATE__, __TIME__ ); \
                            Log::log_hdl->LogPrintf_MC  args ; \
                            } while( Log::one_loop )

#define LogTimerStart(args) do { \
                            Log::log_hdl->SaveState_MC( LOG_TSTART, errno, __FILE__, __LINE__, __DATE__, __TIME__ ); \
                            Log::log_hdl->LogPrintf_MC  args ; \
                            Log::log_hdl->timer_start = clock();\
                            } while( Log::one_loop )

#define LogTimerStop(args) do { \
                            Log::log_hdl->timer_stop = clock();\
                            Log::log_hdl->SaveState_MC( LOG_TSTOP, errno, __FILE__, __LINE__, __DATE__, __TIME__ ); \
                            Log::log_hdl->LogPrintf_MC  args ; \
                            } while( Log::one_loop )

#else  // !L_DEBUG
// These are disabled and left out when in not in DEBUG-mode:
#define LogInfo(args)
#define LogDebug(args)
#define LogTimerStart(args)
#define LogTimerStop(args)

#endif  // !L_DEBUG

// these Functions are always available, independend of the setting of DEBUG-Mode:
#define LogInit                 Log::Init
#define LogDeInit()             Log::DeInit()

#define LogIsVisible()          Log::log_hdl->IsVisible()
#define LogShow()               Log::log_hdl->Show()
#define LogHide()               Log::log_hdl->Hide()

#define LogIsActive()           Log::log_hdl->IsActive()
#define LogActivate()           Log::log_hdl->Activate()
#define LogDeActivate()         Log::log_hdl->DeActivate()

#define LogIsRedirectingStdio() Log::log_hdl->IsRedirectingStdio()
#define LogRedirectStdio()      Log::log_hdl->RedirectStdio()
#define LogDirectStdio()        Log::log_hdl->DirectStdio()


#define LogIsInitialised()     log_initialised

#define LogWarn(args)   do { \
                           Log::log_hdl->SaveState_MC( LOG_WARN, errno, __FILE__, __LINE__, __DATE__, __TIME__ ); \
                           Log::log_hdl->LogPrintf_MC  args ; \
                           } while( Log::one_loop )

#define LogError(args)  do { \
                           Log::log_hdl->SaveState_MC( LOG_ERROR, errno, __FILE__, __LINE__, __DATE__, __TIME__ ); \
                           Log::log_hdl->LogPrintf_MC  args ; \
                           } while( Log::one_loop )


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ TYPE DEFINITIONS: ~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* none */

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ EXPORTED VARS: ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
extern bool log_initialised;


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~ EXPORTED FUNCTIONS: ~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* none */

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ EXPORTED CLASSES: ~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/*
###############################################################################
## CLASS:   LogOutStreamWidget
## ---------------------------------------------------------------------------
## DESCRIPTION:
## derived from Fl_Browser/CXIDSListbox, Log adds some streaming cappabilities
## output-end of the widget-stream
## ---------------------------------------------------------------------------
## VERSION: DATE:        AUTHOR:   CHANGES:
## 0.1      03-Apr-2000  CLu    creation
###############################################################################
*/
#if FLTK
  class LogOutStreamWidget : public Fl_Browser 
#elif CLASSWORKX
  class LogOutStreamWidget : public CXIDSListbox
#endif // !(FLTK || CLASSWORKX)
{
public:
    void PutC( int chr);
    void PutSn(const char *str, int n);

    // assignement operator and copy-constructor, 
	// just to get rid of a warning in MSVC++:
    LogOutStreamWidget & operator=(const LogOutStreamWidget &);
    LogOutStreamWidget(const LogOutStreamWidget &);

    LogOutStreamWidget(int x,int y,int w,int h);
};

/*
###############################################################################
## CLASS:   WidgetStreamBuf
## ---------------------------------------------------------------------------
## DESCRIPTION:
## derived from streambuf, needed to tie the iostream to the widget
## ---------------------------------------------------------------------------
## VERSION: DATE:       AUTHOR: CHANGES:
## 0.1      03-Apr-2000 CLu     creation
###############################################################################
*/

class WidgetStreamBuf
:public streambuf
{
private:
  LogOutStreamWidget *wid;
  void	put_buffer(void);
  void	put_char(int);

protected:
   int	overflow(int);
   int	underflow(void);
   int	sync(void);

   int  sputn( const char* buf,  int strsize);

public:
            WidgetStreamBuf(LogOutStreamWidget* widget = 0, char* buffer = 0, int buffer_size = 0);
   virtual ~WidgetStreamBuf();
};




/*
###############################################################################
## CLASS:   OutputWidgetStream
## ---------------------------------------------------------------------------
## DESCRIPTION:
## derived from ostream, output-to-widget stream
## ---------------------------------------------------------------------------
## VERSION: DATE:        AUTHOR:   CHANGES:
## 0.1      03-Apr-2000  CLu    creation
###############################################################################
*/
class OutputWidgetStream
:public ostream ,public WidgetStreamBuf
{
private:
	  int log_level;

public:
      OutputWidgetStream(int log_level, LogOutStreamWidget* output_widget_ptr, char* buffer, int buffer_size = 0);
};


/*
############ Classworkx-Buttons: ####################################
*/
#if CLASSWORKX
class   clear_button_cl 
:public CXIDSButton
{
public: 
  clear_button_cl() : CXIDSButton() {};
  virtual bool onClicked();
};

class   hide_button_cl : public CXIDSButton
{
public: 
  hide_button_cl() : CXIDSButton() {};
  virtual bool onClicked();
};
#endif // !CLASSWORKX


/*
###############################################################################
## CLASS:   Log
## ---------------------------------------------------------------------------
## DESCRIPTION:
## derived from Fl_Window
## ---------------------------------------------------------------------------
## VERSION: DATE:        AUTHOR:   CHANGES:
## 0.1      03-Apr-2000  CLu    creation
###############################################################################
*/
#if FLTK
  class Log : public Fl_Window 
#elif CLASSWORKX
  class Log : public CXIDSWindow
#endif // !(FLTK || CLASSWORKX)
{
private:
    bool initialised;              /* Logging-initialised-flag       */
    bool active;                   /* Logging-Activated-flag         */
    bool visible;                  /* Log window visible-flag        */
    bool redirect_stdio;           /* redirect stdio, cout&cerr?     */

    char  *print_buf;              /* buffer for sprintf-convertings */
    size_t print_buf_sz;           /* size of allocated buffer       */

#if IOSTREAM_OLDSTYLE
    ostream_withassign   cout_backup;   /* backups Pointer to original cout-buffer */
    ostream_withassign   cerr_backup;   /* backups Pointer to original cerr-buffer */
    OutputWidgetStream*  my_cout;       /* the new stream-to-widget for cout       */
    OutputWidgetStream*  my_cerr;       /* the new stream-to-widget for cerr       */
#elif IOSTREAM_STL
    streambuf*           cout_backup;   /* backups Pointer to original cout-buffer */
    streambuf*           cerr_backup;   /* backups Pointer to original cerr-buffer */
    OutputWidgetStream*  my_cout;       /* the new stream-to-widget for cout       */
    OutputWidgetStream*  my_cerr;       /* the new stream-to-widget for cerr       */
#endif  // IOSTREAM_STL

          char *label_buf;         /* buffer for the label/window-title */

          int   log_level;         /* akt. logging level             */
          int   log_errno;         /* akt. errno-nummer              */
    const char *log_file;          /* akt. source-module-name        */
          long  log_line;          /* akt. Line in source-module     */
    const char *log_date;          /* file compile date              */
    const char *log_time;          /* file compile time              */
    
          int   log_bg_color;      /* Background color of log window */

// Widgets:
    LogOutStreamWidget *log_out_stream_widget;

#if FLTK

    Fl_Button    *clear_button;
    Fl_Button    *hide_button;
    Fl_Button    *active_button;

#elif CLASSWORKX

    clear_button_cl *clear_button;
    hide_button_cl  *hide_button;
    CXIDSPanel      *v_panel1;
    CXIDSPanel      *h_panel1;

#endif // !(FLTK || CLASSWORKX)


public:
    static Log *log_hdl;           // Handle to get singleton-instance
    static int  one_loop;          // Counter for one dummy-loop 

    clock_t timer_start;
    clock_t timer_stop;

    char log_stream_buf[OWSTREAM_BUFF_SIZE];
    
// static callback-functions:
    static void cb_quit(   void );
    static void cb_clear(  void );
    static void cb_hide(   void );
    static void cb_active( void );

    bool IsActive(void)  {return(active);}  // tells wether the log window is active or not
    void Activate()      {active = true;  active_button->label("active");   active_button->selection_color(FL_GREEN);  active_button->set(); }  
    void DeActivate()    {active = false; active_button->label("inactive"); active_button->selection_color(FL_RED);    active_button->set(); } 

    bool IsVisible(void) {return log_hdl->visible;}  // tells wether the log window is visible or not
    void Show(void);
    void Hide(void);
    
    bool IsRedirectingStdio(void) { return redirect_stdio;}
    void RedirectStdio(void);
    void DirectStdio(void);

    void SaveState_MC( const int akt_log_level, const int akt_errno, const char *akt_file, const long akt_line, const char *akt_date, const char *akt_time );

    int  LogPrintf_MC( const char *format, ...);
    int  LogVPrintf(   const char *format, va_list arg_ptr);

#if (PLX_MSWIN32 && PLX_VISUALC)
    int  LogFPrintf_MC( struct _iobuf *file_ptr, const char *format, ...);
#else
    int  LogFPrintf_MC( FILE *file_ptr,    const char *format, ...);
#endif // (MSWIN32 && MSVCPP)

    // (de)initialisers of 'singleton':
    static Log *Init(int x, int y, int w, int h, const char *title, char bg_color, bool redirect_stdio);
    static Log *Init( void );
    static void DeInit( void );    // called via atexit

    // constructor & destructor:
    ~Log(void);

protected:
    Log(int x_pos, int y_pos, int width, int height, const char *title, char bg_color);

};

//reset changed Warning-Level: 
#if WIN32 && _MSC_VER
#pragma warning(pop)
#endif

#endif  /* LOG_HPP */
