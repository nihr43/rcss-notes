### LDAP

LDAP is the protocol for accessing a database running on an LDAP server.  The database is a hierarchy of directories.

Objects are adressed from right to left with the following attributes

	- dc : domain component
	- dn : distinguished names
	- cn : common name
	- ou : organizational unit


	- example query: `ldapsearch -x '(cn=nihr43)' -b 'ou=users,dc=people'`
