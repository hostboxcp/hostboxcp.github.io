#!/usr/bin/python3.9
# Certbot DNS Cleanup Hook
import os
import time
import json

config_file = open("/usr/local/hostboxcp/config.json", "r")
config = json.load(config_file)
config_file.close()

CERTBOT_DOMAIN = os.environ['CERTBOT_DOMAIN']

if config['dns.cluster'] == "enabled":
    pass
else:
    os.system(f"pdnsutil delete-rrset {CERTBOT_DOMAIN} _acme-challenge TXT")

time.sleep(25)

# Get your API key from https://www.cloudflare.com/a/account/my-account
# API_KEY="your-api-key"
# EMAIL="your.email@example.com"

# if [ -f /tmp/CERTBOT_$CERTBOT_DOMAIN/ZONE_ID ]; then
#         ZONE_ID=$(cat /tmp/CERTBOT_$CERTBOT_DOMAIN/ZONE_ID)
#         rm -f /tmp/CERTBOT_$CERTBOT_DOMAIN/ZONE_ID
# fi

# if [ -f /tmp/CERTBOT_$CERTBOT_DOMAIN/RECORD_ID ]; then
#         RECORD_ID=$(cat /tmp/CERTBOT_$CERTBOT_DOMAIN/RECORD_ID)
#         rm -f /tmp/CERTBOT_$CERTBOT_DOMAIN/RECORD_ID
# fi

# # Remove the challenge TXT record from the zone
# if [ -n "${ZONE_ID}" ]; then
#     if [ -n "${RECORD_ID}" ]; then
#         curl -s -X DELETE "https://api.cloudflare.com/client/v4/zones/$ZONE_ID/dns_records/$RECORD_ID" \
#                 -H "X-Auth-Email: $EMAIL" \
#                 -H "X-Auth-Key: $API_KEY" \
#                 -H "Content-Type: application/json"
#     fi
# fi