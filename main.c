#include "rawl.h"

#include <stdlib.h>

// Wayland server
struct rw_server *server;

int rw_start() {
    rw_log_info("Starting Rawl Wayland server...");

    rw_server_init(server);
    if (server == NULL) {
        rw_log_error("Failed to initialize server");
        return 1;
    }

    return 0;
}

int main() {
    return rw_start();
}
