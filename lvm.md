## LVM

LVM abstracts disks from the filesystem, providing features such as live volume resizing

### Components
	- Physical Volumes
	- Logical Volumes
	- Volume Groups

### Semantics
	- PGs are disks and belong to VGs
	- VGs are groups of physical volumes
	- LGs present volumes to the filesystem

### Formatting
	- initialize a disk as a physical volume using `pvcreate /dev/sdx`
	- 
