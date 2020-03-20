/**
 * @file lv_tinygl_test.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "lvgl/lvgl.h"
#include "src/gl.h"
#include "src/zbuffer.h"

/*********************
 *      DEFINES
 *********************/
#define CANVAS_WIDTH  160
#define CANVAS_HEIGHT 160


/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void anim(lv_task_t* t);

void showmodel_update (void);
void showmodel_init (int w, int h, void *cbuf, char *filename);

/**********************
 *  STATIC VARIABLES
 **********************/
static lv_obj_t * canvas;
static lv_color_t cbuf[LV_IMG_BUF_SIZE_TRUE_COLOR_ALPHA(CANVAS_WIDTH, CANVAS_HEIGHT)];

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lv_tinygl_test(void)
{
    /*Create glGears*/
    canvas = lv_canvas_create(lv_scr_act(), NULL);
    lv_canvas_set_buffer(canvas, cbuf, CANVAS_WIDTH, CANVAS_HEIGHT, LV_IMG_CF_TRUE_COLOR);
    lv_obj_align(canvas, NULL, LV_ALIGN_IN_LEFT_MID, 20, 0);

    showmodel_init(CANVAS_HEIGHT, CANVAS_HEIGHT, cbuf, "./lv_lib_tinygl/test.obj");

    lv_task_create(anim, 30, LV_TASK_PRIO_LOW, NULL);
}


static void anim(lv_task_t* t)
{
    showmodel_update();
    lv_obj_invalidate(canvas);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
