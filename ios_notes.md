### Basic IOS Switch Commands


- `enable` enter shell
- `configure terminal` enter configuration mode
- `show running config`
- `show startup config`
- `copy run start` save changes to starting config
- `write erase` clear all configuration
- `vlan 555` create vlan 555
- 'no vlan 555` delete vlan 555
- `int vlan 555` `ip addr xx.xx.xx.xx xx.xx.xx.xx` create virtual interface in vlan 555, then assign an address
- `vlan summary`
- `int ranf fasteth 0/1-10` configure range of interfaces
- `switchport mode access` set port mode to access; disabling 802.1q tagging
- `switchport mode trunk` set interface to trunk vlans; enabling 802.1q tagging
- `switchport access vlan 555` place port in vlan 555
- `switchport trunk allowed vlan 1,2,3` place vlans on the trunk
- `no spanning-tree vlan 1` disable stp
- `default interface fa x/x` clear configuration of int fa x/x
