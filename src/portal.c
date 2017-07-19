#include <stdio.h>
#include <string.h>
#include "portal.h"

#define LINE_LENGTH 104 // handle '\0' return from fgets and three '\t' delimeters

WifiPortal* newWifiPortal(int line_length) {
  WifiPortal* wifi_portal = malloc(sizeof(WifiPortal));
  if (!wifi_portal) {
    fprintf(stderr, "WifiPortalError: failed to allocate memory for WifiPortal");
    return NULL;
  }

  max_conn_string_len = line_length - sizeof(wifi_portal->ip_address) - sizeof(wifi_portal->ssid);
  
  wifi_portal->auth_string = (char *) malloc(sizeof(char) * max_conn_string_len);
  if (!wifi_portal->auth_string) {
    fprintf(stderr, "WifiPortalError: failed to allocate memory for WifiPortal auth string");
    free((void *) wifi_portal);
    return NULL;
  }

  return wifi_portal
}

WifiPortal* parse_config(File* config, char* ssid) {
  WifiPortal* wifi_portal = (WifiPortal *) malloc(sizeof(WifiPortal));

  char* format_string = "%s\t%s\t%s\t%s\t"
  char line[LINE_LENGTH];

  while (fgets(line, LINE_LENGTH, config)) {
    sscanf(line,
	   format_string,
	   &(wifi_portal->ssid),
	   &(wifi_portal->protocol),
	   &(wifi_portal->ip_address),
	   &(wifi_portal->auth_string));
    if (strncmp(wifi_portal->ssid, ssid, 32))
      return wifi_portal;
  }
  return NULL;
}
