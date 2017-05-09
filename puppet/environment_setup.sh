#!/bin/bash

##creates an environment of 50 nodes to experiment with puppet



lxc-create -t ubuntu -n puppetmaster
lxc-attach -n puppetmaster -- apt-get update
lxc-attach -n puppetmaster -- apt-get upgrade -y
lxc-stop -n puppetmaster
lxc-start -n puppetmaster
lxc-attach -n puppetmaster -- apt-get install puppetmaster


lxc-create -t ubuntu -n puppetagent
lxc-attach -n puppetagent -- apt-get update
lxc-attach -n puppetagent -- apt-get upgrade -y
lxc-stop -n puppetagent
lxc-start -n puppetagent
lxc-attach -n puppetagent -- apt-get install puppet
lxc-stop -n puppetagent


#	make 50 clones with agent installed
for i in {1..50]
do
	lxc-copy -n puppetagent -N agent_$i
done



#	request certs for all nodes
for i in {1..50}; do lxc-attach -n agent_$i -- puppet agent --server puppetmaster --test; done



#	sign all certs ON MASTER
for i in {1..50}; do lxc-attach -n puppetmaster -- puppet cert --sign agent_$i;  done
