#ifndef PORTAL_H
#define PORTAL_H

#include <stdio.h>

typedef struct wifi_portal {
  char ssid[32];
  char ip_address[15];
  char protocol[5];
  char* auth_string;
} WifiPortal;

WifiPortal* newWifiPortal(int line_length);
void delWifiPortal(WifiPortal* wifi_portal);
WifiPortal* parse_config(File* config);

#endif
