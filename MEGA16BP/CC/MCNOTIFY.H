/**********************************************************************/
/* mcnotify.h                                                         */
/**********************************************************************/

/**********************************************************************/
/* notification codes                                                 */
/**********************************************************************/

#define IF_NF_SAVE       2    // lParam = 0L
#define IF_NF_FREE       3    // lParam = 0L
#define IF_NF_LOAD       4    // lParam = 0L
#define IF_NF_FNEW       5    // lParam = 0L
#define IF_NF_EXIT       6    // lParam = 0L
#define IF_NF_UNDO       7    // lParam = 0L
#define IF_NF_REDO       8    // lParam = 0L
#define IF_NF_EMBEDSAVE  9    // lParam = entity ID
#define IF_NF_SEL_ENT   10    // lParam = t_SelNfy*
#define IF_NF_FREE_PID  11    // lParam = t_SelNfy*
#define IF_NF_DEL_ENT   12    // lParam = t_MfyNfy*
#define IF_NF_COPY_ENT  13    // lParam = t_CpyNfy*
#define IF_NF_DIALOG    14    // lParam = 0 / 1

/**********************************************************************/
/* sub codes for    'IF_NF_SEL_ENT'                                   */
/*                  'IF_NF_COPY_ENT'                                  */
/**********************************************************************/

#define IF_SNF_DEL_ENT      1
#define IF_SNF_MOV_ENT      2

/**********************************************************************/
#if defined ( MI_VERSION )
/**********************************************************************/

typedef struct _CpyNfy
{
    t_applic appl;          // application data
    ulong    subReason;     //
    t_EntPtr *ep;           //
    ulong    retval;        //
} t_CpyNfy;

typedef struct _MfyNfy
{
    t_applic appl;          // application data
    ulong    id;            //
    ulong    retval;        //
} t_MfyNfy;

typedef struct _OwNfy
{
    t_applic appl;          //
    ulong    id;            //
} t_OwNfy;

typedef struct _SelNfy
{
    uint    subReason;      // MegaCAD function
    ulong   num;            // number of entities
    t_OwNfy *ptr;           // entities
    ulong   cnt;            // output: number of entities
    ulong   *pid;           // output: entity ID's
} t_SelNfy;

/**********************************************************************/
#endif  // MI_VERSION
/**********************************************************************/
