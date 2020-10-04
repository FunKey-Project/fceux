#ifndef _MENU_H_
#define _MENU_H_


typedef enum{
    MENU_TYPE_VOLUME,
    MENU_TYPE_BRIGHTNESS,
    MENU_TYPE_SAVE,
    MENU_TYPE_LOAD,
    MENU_TYPE_ASPECT_RATIO,
    MENU_TYPE_EXIT,
    MENU_TYPE_POWERDOWN,
    NB_MENU_TYPES,
} ENUM_MENU_TYPE;


///------ Definition of the different aspect ratios 
#define ASPECT_RATIOS \
    X(ASPECT_RATIOS_TYPE_CROPPED, "CROPPED") \
    X(ASPECT_RATIOS_TYPE_STRETCHED, "STRETCHED") \
    X(NB_ASPECT_RATIOS_TYPES, "") 

////------ Enumeration of the different aspect ratios ------
#undef X
#define X(a, b) a,
typedef enum {ASPECT_RATIOS} ENUM_ASPECT_RATIOS_TYPES;

///------ Definition of the different resume options
#define RESUME_OPTIONS \
    X(RESUME_YES, "RESUME GAME") \
    X(RESUME_NO, "NEW GAME") \
    X(NB_RESUME_OPTIONS, "") 

////------ Enumeration of the different resume options ------
#undef X
#define X(a, b) a,
typedef enum {RESUME_OPTIONS} ENUM_RESUME_OPTIONS;

////------ Defines to be shared -------
#define STEP_CHANGE_VOLUME          10
#define STEP_CHANGE_BRIGHTNESS      10
#define NOTIF_SECONDS_DISP			2

////------ Menu commands -------
#define SHELL_CMD_VOLUME_GET        	  	"volume_get"
#define SHELL_CMD_VOLUME_SET        	  	"volume_set"
#define SHELL_CMD_BRIGHTNESS_GET    	  	"brightness_get"
#define SHELL_CMD_BRIGHTNESS_SET    	  	"brightness_set"
#define SHELL_CMD_POWERDOWN         	  	"shutdown_funkey"
#define SHELL_CMD_SCHEDULE_POWERDOWN		"sched_shutdown"
#define SHELL_CMD_NOTIF					  	"notif_set"
#define SHELL_CMD_WRITE_QUICK_LOAD_CMD	  	"write_args_quick_load_file"
 
////------ Global variables -------
extern int volume_percentage;
extern int brightness_percentage;

extern const char *aspect_ratio_name[];
extern int aspect_ratio;
extern int aspect_ratio_factor_percent;
extern int aspect_ratio_factor_step;
extern int stop_menu_loop;

extern struct SAVE_STATE mSaveState[10];
//extern s8 mSaveStateName[SAL_MAX_PATH];
//extern s8 mRomName[SAL_MAX_PATH];
//extern s8 mSystemDir[SAL_MAX_PATH];

extern char *mRomName;
extern char *mRomPath;
extern char *quick_save_file;

//####################################
//# Functions
//####################################
void init_menu_SDL();
void deinit_menu_SDL();
void init_menu_zones();
void init_menu_system_values();
void run_menu_loop();

int launch_resume_menu_loop();


#endif /* _MENU_H_ */