project('rawl', 'c',
  version: '0.1.0',
  meson_version: '>= 0.60.0',
  default_options: [
    'c_std=c99',
  ]
)

wayland_server_dep = dependency('wayland-server', version: '>= 1.12.0')

executable('rawl',
  'main.c',
  'server.c',
  dependencies : [wayland_server_dep],
)
