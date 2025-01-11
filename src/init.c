#include "init.h"

#include <stdio.h>
#include "file.h"
#include "input.h"
#include "log.h"
#include "manager.h"
#include "render.h"
#include "util.h"

void init(void) {
  InputManager *im = input_init(60, 8);
  lm = layermgr_init(3, 40, 20);

  layermgr_add(lm,
               0,
               new_layer(40,
                         20,
                         0,
                         0,
                         /*TODO: lacking some error handling*/
                         file_read("./src/maps/test" /*"/home/saturn/Asciigine/src/maps/test"*/, 800)));
  layermgr_add(lm, 1, new_layer(1, 1, 5, 5, "@"));
  layermgr_add(lm, 2, new_layer(1, 1, 36, 3, "X"));

  keylist_add(im->keylist, new_key('w', moveup));
  keylist_add(im->keylist, new_key('s', movedown));
  keylist_add(im->keylist, new_key('a', moveleft));
  keylist_add(im->keylist, new_key('d', moveright));

  while (1) {
    input_read(im);
    render(lm);
  }

  // pthread_t *renderer = renderer_start(lm);
  // pthread_t *inputlistenner = input_startlistenner(im);
}
void moveup(void) {
  layermgr_shiftlayer(lm, 1, 0, 1);
}
void movedown(void) {
  layermgr_shiftlayer(lm, 1, 0, -1);
}
void moveleft(void) {
  layermgr_shiftlayer(lm, 1, -1, 0);
}
void moveright(void) {
  layermgr_shiftlayer(lm, 1, 1, 0);
}
