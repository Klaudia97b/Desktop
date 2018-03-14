typedef unsigned char  uchar;
typedef unsigned short ushort;
typedef unsigned int   uint;
typedef unsigned long  ulong;
typedef signed   char  schar;

#define FALSE          0
#define TRUE           1

#define DEF_PI         3.14159265358979323846264338327950

#if defined ( MEGATECH_C )
    #define MegaMain       main
    #define EXT(n)         extmega n
    #define _far
    #define _pascal
    #define NULL           (void*)0L
    #define va_start(ap,v) ap = (char*)((&v) + 1)

    typedef struct _hentry
    {
        ulong  size;        // Size of entry (if bit 31 set => free entry)
        char   *ptr;        // Address of entry
    } t_hentry;

    #define ML_READ        0x0
    #define ML_WRITE       0x1
    #define ML_PLUS        0x2
    #define ML_BIN         0x0
    #define ML_TEXT        0x4
    #define ML_APPEND      0x8
    #define ML_CHANGE_ATTR 0x10
    #define ML_SET_CHANGE  0x20
    #define ML_DENY_NO     0x0
    #define ML_DENY_RD     0x40
    #define ML_DENY_WR     0x80
    #define ML_DENY_RW     (ML_DENY_RD | ML_DENY_WR)

    EXT(1)  void   exit(int retcode);
    EXT(2)  int    abs(int i);
    EXT(3)  double fabs(double val);
    EXT(4)  double acos(double val);
    EXT(5)  double asin(double val);
    EXT(6)  double atan(double val);
    EXT(7)  double cos(double val);
    EXT(8)  double sin(double val);
    EXT(9)  double tan(double val);
    EXT(10) double cosh(double val);
    EXT(11) double sinh(double val);
    EXT(12) double tanh(double val);
    EXT(13) double log(double val);
    EXT(14) double log10(double val);
    EXT(15) double ceil(double val);
    EXT(16) double floor(double val);
    EXT(17) double sqrt(double val);
    EXT(18) double exp(double val);
    EXT(19) double hypot(double dx,double dy);
    EXT(20) double atan2(double dy,double dx);
    EXT(21) double fmod(double val1,double val2);
    EXT(22) double pow(double val1,double val2);
    EXT(23) double atof(char *str);
    EXT(24) int    atoi(char *str);
    EXT(25) char * malloc(uint size);
    EXT(26) void   free(void *ptr);
    EXT(27) ushort heapwalk(t_hentry *entry);
    EXT(28) short  sprintf(char *buf,char *fmt,...);
    EXT(29) short  vsprintf(char *buf,char *fmt,char *args);
    EXT(30) int    rand(void);
    EXT(31) void   srand(uint seed);
    EXT(32) short  strcmp(char *str1,char *str2);
    EXT(33) char * strcpy(char *dst,char *src);
    EXT(34) char * strchr(char *dst,short chr);
    EXT(35) uint   strlen(char *str);
    EXT(36) void   memset(void *ptr,ushort fill,uint size);
    EXT(37) void * memcpy(void *dst,void *src,uint size);
    EXT(38) short  ML_Open(char *name,ushort mode);
    EXT(39) short  ML_Close(short fh);
    EXT(40) short  ML_Remove(char *name);
    EXT(41) uint   ML_Read(void *buf,uint size,short fh);
    EXT(42) uint   ML_Write(void *buf,uint size,short fh);
    EXT(43) long   ML_Tell(short fh);
    EXT(44) short  ML_Seek(short fh,long offset,short origin);
    EXT(45) short  ML_Printf(short fh,char *fmt,...);
    EXT(46) long   ML_FileLen(short fh);
    EXT(47) void   ML_Flush(short fh);
    EXT(48) void   ML_Rewind(short fh);
    EXT(49) short  ML_Puts(char *str,short fh);
    EXT(50) char * ML_Gets(char *str,ushort max,short FH);
    EXT(51) short  ML_Putc(short fh,short chr);
    EXT(52) short  ML_Getc(short fh);
    EXT(53) short  set_debug(short flag);

#else  // ( MEGATECH_C )

    //#define main MegaMain

    #ifdef _WIN32
        #include <windows.h>
    #endif

    #ifdef _WINDOWS
        #include <windows.h>
    #endif
    #define EXT(n)
    #include <stdio.h>
    #include <math.h>
    #include <string.h>
    #include <stdarg.h>
    #include <malloc.h>
    #ifdef _WINDOWS
        #define sprintf  wsprintf
        #define vsprintf wvsprintf
    #endif

    #ifdef _WIN32
        #define  _far
        #define __far
        #define  _near
        #define __near
        #define __pascal __stdcall
        #define  _pascal __stdcall
        #define   pascal __stdcall
        #define _export
        #define __export
        #define hypot _hypot
    #endif

    #ifdef __cplusplus
        extern "C" short MegaMain(char *file,char *args);
        extern "C" short MegaNotify(uint reason,ulong lParam);
    #else
        extern short MegaMain(char *file,char *args);
        extern short MegaNotify(uint reason,ulong lParam);
    #endif

#endif // ( MEGATECH_C )
