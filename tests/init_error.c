/* conf_client_init() with an unreachable session bus: it must fail cleanly,
 * both with an error pointer and with NULL for it (GLib convention). */
#include <client_api.h>
#include <stdio.h>

int main(void) {
  conf_client proxy = NULL;
  GError *err = NULL;

  if (conf_client_init(&proxy, &err) || proxy != NULL || err == NULL) {
    fprintf(stderr, "init with &err: expected failure with an error set\n");
    return 1;
  }
  g_clear_error(&err);

  proxy = NULL;
  if (conf_client_init(&proxy, NULL) || proxy != NULL) {
    fprintf(stderr, "init with NULL err: expected failure\n");
    return 1;
  }
  return 0;
}
