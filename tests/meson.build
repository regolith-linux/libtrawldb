init_error = executable(
	'init_error',
	'init_error.c',
	include_directories: '../',
	link_with: libclient_api,
	dependencies: [gio_dep]
)
test('init with an unreachable bus', init_error,
	env: ['DBUS_SESSION_BUS_ADDRESS=unix:path=/nonexistent/trawl-test-bus'])
