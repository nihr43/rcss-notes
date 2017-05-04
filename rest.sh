#! /bin/sh

# quick and dirty getting a list of VMs from my digitalocean account


echo "Your current VMs.."
curl -X GET "https://api.digitalocean.com/v2/droplets" -H "Authorization: Bearer $TOKEN" | grep -Po '"name":.*?[^\\]",'




