#include "rawl.h"

#include <stdlib.h>
#include <stdio.h>

int rw_server_init(rw_server_t *server) {
    server->display = wl_display_create();
    if (!server->display) {
        fprintf(stderr, "Failed to create Wayland display\n");
        return -1;
    }

    server->event_loop = wl_display_get_event_loop(server->display);

    if (wl_display_add_socket_auto(server->display) == NULL) {
        fprintf(stderr, "Failed to add Wayland socket\n");
        wl_display_destroy(server->display);
        return -1;
    }

    wl_display_run(server->display);

    wl_display_destroy(server->display);

    return 0;
}
