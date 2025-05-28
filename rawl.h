// rawl - Raku's wayland compositor
// Copyright (c) 2025 Hasegawa, Raku
// See /LICENSE for licensing information.

#pragma once

#if defined(__cplusplus)
extern "C" {
#endif

#include <wayland-server.h>

// logging

void rw_log_info(const char *message);
void rw_log_warning(const char *message);
void rw_log_error(const char *message);
void rw_log_debug(const char *message);

// server

// Wayland server implementation
struct rw_server {
    struct wl_display *display;
    struct wl_event_loop *event_loop;
};

int rw_server_init(struct rw_server *server);
int rw_server_run(struct rw_server *server);
void rw_server_destroy(struct rw_server *server);

#if defined(__cplusplus)
} /* extern "C" */
#endif
