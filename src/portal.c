#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "portal.h"

WifiPortal* newWifiPortal(int line_length) {
  
  WifiPortal* wifi_portal = malloc(sizeof(WifiPortal));
  if (!wifi_portal) {
    fprintf(stderr, "WifiPortalError: failed to allocate memory for WifiPortal");
    return NULL;
  }

  wifi_portal->ssid[SSID_LEN] = '\0';
  wifi_portal->protocol[PROTOCOL_LEN] = '\0';
  wifi_portal->ip_address[IP_ADDRESS_LEN] = '\0';  

  /* wifi_portal->auth_string = (char *) malloc(sizeof(char) * AUTH_STRING_LEN); */
  if (!wifi_portal->auth_string) {
    fprintf(stderr, "WifiPortalError: failed to allocate memory for WifiPortal auth string");
    free((void *) wifi_portal);
    return NULL;
  }

  return wifi_portal;
}

void delWifiPortal(WifiPortal* wifi_portal) {
  if (wifi_portal != NULL) {
    free(wifi_portal->auth_string);
    free(wifi_portal);
  }
}

WifiPortal* parse_config(char* config_path, char* ssid) {
  FILE* config = fopen(config_path, "r");
  if (config == NULL) {
    fprintf(stderr, "WifiPortalError: Failed to read config file: %s\n", config_path);
    return NULL;
  }
  
  WifiPortal* wifi_portal = newWifiPortal(LINE_LENGTH);

  char* format_string = "%s\t%s\t%s\t%s";
  char line[LINE_LENGTH];

  while (fgets(line, LINE_LENGTH, config) != NULL) {
    char* tmp = strtok(line, "\t");

    strncpy(wifi_portal->ssid, tmp, SSID_LEN);
    if (strncmp(wifi_portal->ssid, ssid, SSID_LEN) != 0)
      continue;
    
    tmp = strtok(NULL, "\t");
    strncpy(wifi_portal->protocol, tmp, PROTOCOL_LEN);

    tmp = strtok(NULL, "\t");
    strncpy(wifi_portal->ip_address, tmp, IP_ADDRESS_LEN);
    
    tmp = strtok(NULL, "\0");
    printf("%s\n", tmp);
    wifi_portal->auth_string= strdup(tmp);
    
    return wifi_portal;
  }
  delWifiPortal(wifi_portal);
  return NULL;
}
