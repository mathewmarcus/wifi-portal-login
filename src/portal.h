#ifndef PORTAL_H
#define PORTAL_H

#define LINE_LENGTH 104
#define SSID_LEN 32
#define IP_ADDRESS_LEN 15
#define PROTOCOL_LEN 5

typedef struct wifi_portal {
  char ssid[SSID_LEN + 1];
  char ip_address[IP_ADDRESS_LEN + 1];
  char protocol[PROTOCOL_LEN + 1];
  char* auth_string;
} WifiPortal;

WifiPortal* newWifiPortal(int line_length);
void delWifiPortal(WifiPortal* wifi_portal);
WifiPortal* parse_config(char* config_path, char* ssid);

#endif
