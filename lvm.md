## LVM

### Components
	- Physical Volumes
	- Logical Volumes
	- Volume Groups

### Semantics
	- PGs are disks and belong to VGs
	- VGs span volumes
	- LGs present volumes to the filesystem

### Formatting
	- initialize a disk as a physical volume using `pvcreate /dev/sdx`
	- 
