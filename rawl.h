#pragma once

#include <wayland-server.h>

struct rw_server {
    struct wl_display *display;
    struct wl_event_loop *event_loop;
};

typedef struct rw_server rw_server_t;

int rw_server_init(rw_server_t *server);
