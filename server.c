#include "rawl.h"

#include <stdlib.h>
#include <stdio.h>

int rw_server_init(struct rw_server *server) {
    server = malloc(sizeof(struct rw_server));

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

    return 0;
}

int rw_server_run(struct rw_server *server) {
    if (!server || !server->display) {
        fprintf(stderr, "Invalid server instance\n");
        return -1;
    }

    wl_display_run(server->display);

    return 0;
}

void rw_server_destroy(struct rw_server *server) {
    if (!server) {
        fprintf(stderr, "Invalid server instance\n");
        return;
    }

    if (server->display) {
        wl_display_destroy(server->display);
    }

    free(server);
}
