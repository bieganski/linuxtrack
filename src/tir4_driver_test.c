#include <stdlib.h>
#include <stdio.h>
#include "cal.h"

int main(int argc, char **argv) {
  struct frame_type frame;
  struct camera_control_block ccb;

  ccb.device.category = tir4_camera;
  ccb.mode = diagnostic;

  cal_init(&ccb);

  /* call below sets led green */
  cal_set_good_indication(&ccb, true);

  /* loop forever reading and printing results */
  while (true) {
    cal_get_frame(&ccb, &frame);
    frame_print(frame);
    frame_free(&ccb, &frame);
  }

  /* call disconnects, turns all LEDs off */
  cal_shutdown(&ccb);
  return 0;
}
